#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>

/*Functionality of SR: 
Corresponding to SR, the SIGLARM handler should read a random number
from the CPU using the the RDRAND instruction (using inline assembly).
Thereafter, SR needs to enqueue the random number andthe SIGTERM and
deliver it to S1’s SIGTERM handler (using kill() system call). 
S1’s SIGTERM handler should print the random number supplied by SR.*/
pid_t s1;

void alarmed(int signal){
    long rd_var;
    int itr; //https://www.intel.com/content/www/us/en/developer/articles/guide/intel-digital-random-number-generator-drng-software-implementation-guide.html    
    for(itr = 0; itr<10; itr++){
        asm volatile (
        "RDRAND %0\n\t"
        :"=r" (rd_var)
        :
        );
        if(rd_var!=0) break; //RDRAND may return 0 sometimes
    }
    union sigval value;
    value.sival_ptr = (void*) rd_var;
    sigqueue(s1, SIGTERM, value);
}

int main(int argc, char const *argv[]){
    if(argc==1) exit(0);
    struct itimerval initial;
    initial.it_value.tv_sec = 1;
    initial.it_value.tv_usec =  0;
    initial.it_interval.tv_sec = 1;
    initial.it_interval.tv_usec = 0;
    int err = setitimer(ITIMER_REAL, &initial, NULL);
    if (err==-1){
        perror("Failed to get alarmed lol\n");
    }
    if(argc==2){
        s1 = atoi(*++argv);
        // printf("%d\n", s1); //names the process
    }
    if(signal(SIGALRM, alarmed)==SIG_ERR){
        perror("Failed to catch SIGALRM");
    }
    while(1){
        pause();
    }
    return 0;
}