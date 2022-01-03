#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define WAITING 2
#define REQUESTED 1
#define EATING 0
#define LEFT (phnum + 4) % 5  //to check left fork
#define RIGHT (phnum + 1) % 5 //to check right fork

int state[5];
int philosophers[5] = {0, 1, 2, 3, 4};

sem_t phSems[5];
sem_t sauceTaker;
sem_t takekeep;

//@CounterSemp
char test(int phnum) //for testing if eatable, also sets semaphore
{
    sleep(0);
    if (state[phnum] == REQUESTED && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
        sem_wait(&sauceTaker); //wait for any of 4 saucebowls
        sem_post(&phSems[phnum]);
        // state that eating
        state[phnum] = EATING;
        usleep(rand() % 120000);
        int whichbowl;
        sem_getvalue(&sauceTaker, &whichbowl);
        printf("Philosopher%d takes fork %d and %d and\teats, bowls unused: %d\n", phnum + 1, phnum + 1, LEFT + 1, whichbowl);
        sem_post(&takekeep); //async taking forks with taking sauce bowls
        usleep(rand() % 1200000);
        printf("\t\t\t\t\t\tBOWL GIVEN UP\n");
        sem_post(&sauceTaker);
        return 1;
    }
    return 0;
}

// take up chopsticks
void take_forks(int phnum) //takes 2 forks in test method or relinquishes
{
    sleep(0);
    sem_wait(&takekeep); //wait for any of 4 saucebowls
    // request for food
    state[phnum] = REQUESTED;
    printf("Philosopher%d has requested\n", phnum + 1);
    if (!test(phnum))
        sem_post(&takekeep);

    // if unable to eat wait to be signalled
    sem_wait(&phSems[phnum]); // wait is finished in test when semaphore is updated
    usleep(rand() % 2200);
}

void put_fork(int phnum)
{
    sleep(0);
    sem_wait(&takekeep);
    state[phnum] = WAITING; //change state
    printf("Philosopher%d keeping fork %d and %d down\n", phnum + 1, LEFT + 1, phnum + 1);

    // test(LEFT);
    //right biasing
    if (!test(RIGHT))
        sem_post(&takekeep);
    // sem_post(&takekeep);
}

void *philosopher(void *num)
{
    while (1)
    {
        int *i = num;
        usleep(rand() % 1500);
        take_forks(*i);
        sleep(0); //switch threads/relinquish timeslice
        put_fork(*i);
    }
}

int main()
{
    int i;
    pthread_t thread_id[5];

    //inits
    sem_init(&sauceTaker, 0, 4); //4 sauce
    sem_init(&takekeep, 0, 1);

    for (i = 0; i < 5; i++)
        sem_init(&phSems[i], 0, 0);

    for (i = 0; i < 5; i++)
    {
        pthread_create(&thread_id[i], NULL,
                       philosopher, &philosophers[i]);
    }

    for (i = 0; i < 5; i++)
        pthread_join(thread_id[i], NULL); //force trigger processes

    return 0;
}
