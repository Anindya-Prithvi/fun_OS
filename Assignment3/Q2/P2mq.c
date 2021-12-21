#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/fcntl.h>
#include <mqueue.h>

int readToBuf(int msgsock, char *readbuf, int sz)
{
    int rval;
    //Read in socket will always reset lseek
    if (mq_receive(msgsock, readbuf, sz, 0) < 0)
        perror("Oh no, read system call, it's broken\n");
}

int main()
{
    int sock, wval, fdr, fdw;
    char readbuf[1024];
    char sendbuf[1024];
    bzero(readbuf, sizeof(readbuf));
    bzero(sendbuf, sizeof(sendbuf));

    printf("P2 process is ready!\n");

    int maxind = -1;
    int prev_maxind = -1;

    int itr = 10;

    while (itr)
    {
        if ((fdr = mq_open("/wmqueue", O_RDONLY)) < 0)
        {
            perror("Do not run p2 first");
        }
        readToBuf(fdr, readbuf, sizeof(readbuf));

        printf("I received:\n%s", readbuf);

        sscanf(readbuf, "%d%*s", &maxind);
        if (prev_maxind != maxind)
        {
            --itr;
            prev_maxind = maxind;
        }

        mq_close(fdr);
        if ((fdw = mq_open("/rmqueue", O_WRONLY)) < 0)
            perror("fifo not writable\n");

        snprintf(sendbuf, 8, "%d", maxind + 4);
        printf("send val = %s\n", sendbuf);
        if ((wval = mq_send(fdw, sendbuf, sizeof(sendbuf), 0)) < 0)
            perror("writing on stream socket\n");
        mq_close(fdw);
    }

    printf("TERMINATING P2, TASK COMPLETED.\n");
}