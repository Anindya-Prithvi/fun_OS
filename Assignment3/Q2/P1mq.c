#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <mqueue.h>

int genString(char *ptr)
{
    char *itr = ptr;
    if (ptr == NULL)
        return -1;
    //generates a random string of length 8 given ptr | Capitals only
    //non NULL terminated

    for (size_t i = 0; i < 8; i++)
    {
        int num = rand() % 26;
        *(itr++) = num + 65;
    }

    return 0;
}

int readToBuf(int msgsock, char *readbuf, int sz)
{
    //Read in socket will always reset lseek
    //blocking syscall oneshot read
    if (mq_receive(msgsock, readbuf, sz, 0) < 0)
        perror("Oh no, read system call, it's broken\n");
}

int main()
{
    //generate 50, 8-byte strings
    char *stringarr[50];
    for (size_t i = 0; i < 50; i++)
    {
        stringarr[i] = calloc(8, sizeof(char));
        genString(*(stringarr + i));
    }

    int sock, msgsock, rval, acksock, wval;

    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 2;
    attr.mq_msgsize = 1024;
    attr.mq_curmsgs = 0;
    mqd_t fdw = mq_open("/wmqueue", O_RDWR | O_CREAT, 0666, &attr);
    mqd_t fdr = mq_open("/rmqueue", O_RDWR | O_CREAT, 0666, &attr);
    if (fdw & fdr < 0)
    {
        perror("FAILED TO CREATE MQ, FATAL\n");
        exit(1);
    }
    mq_close(fdr);
    mq_close(fdw);

    char readbuf[1024];
    char sendbuf[1024];
    bzero(readbuf, sizeof(readbuf));
    bzero(sendbuf, sizeof(sendbuf));

    int sendex = 0;

    while (1)
    {
        if ((fdw = mq_open("/wmqueue", O_WRONLY)) < 0)
            perror("mqueue not writable\n");
        else
        {
            printf("P1 process is ready!\n");
            //Writing a message
            if (snprintf(sendbuf, 100,
                         "%d.%s\n%d.%s\n%d.%s\n%d.%s\n%d.%s\n",
                         sendex, *(stringarr + sendex),
                         sendex + 1, *(stringarr + sendex + 1),
                         sendex + 2, *(stringarr + sendex + 2),
                         sendex + 3, *(stringarr + sendex + 3),
                         sendex + 4, *(stringarr + sendex + 4)) < 0)
                perror("");
            printf("I sent:\n%s", sendbuf);
            if ((wval = mq_send(fdw, sendbuf, sizeof(sendbuf), 0)) < 0)
                perror("errored while writing\n");
            printf("Message written--\nAwaiting ACK\n");

            mq_close(fdw);

            if ((fdr = mq_open("/rmqueue", O_RDONLY)) < 0)
                perror("mqueue not readable\n");

            readToBuf(fdr, readbuf, sizeof(readbuf));
            //it'll always fit in 1 byte (this ques)
            close(fdr);

            printf("Received ACK: %s, interpreted as: %d\n", readbuf, atoi(readbuf));
            if (atoi(readbuf) == sendex + 4)
            {
                printf("Transmission successful\n");
                sendex += 5;
            }
            else
            {
                printf("Failed, redoing\n");
            }
            if (sendex == 50)
            {
                break;
                //OBJECTIVE complete
            }
        }
    }
    printf("TERMINATING P1, TASK COMPLETED.\n");
    mq_unlink("/wmqueue");
    mq_unlink("/rmqueue");
    return 0;
}