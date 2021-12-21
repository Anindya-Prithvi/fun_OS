#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int readToBuf(int msgsock, char *readbuf, int sz)
{
    //Read in socket will always reset lseek
    if (read(msgsock, readbuf, sz) < 0)
        perror("Oh no, read system call, it's broken\n");
}

int main()
{
    int sock, wval;
    struct sockaddr_un server;
    char readbuf[1024];
    char sendbuf[1024];
    bzero(readbuf, sizeof(readbuf));
    bzero(sendbuf, sizeof(sendbuf));

    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("opening stream socket");
        exit(1);
    }
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, "server");

    if (connect(sock, (struct sockaddr *)&server, sizeof(struct sockaddr_un)) < 0)
    {
        close(sock);
        perror("Connecting socket, retry\n");
        exit(1);
    }

    printf("P2 process is ready!\n");

    int maxind = -1;
    int prev_maxind = -1;

    int itr = 10;

    while (itr)
    {
        readToBuf(sock, readbuf, sizeof(readbuf));

        printf("I received:\n%s", readbuf);

        sscanf(readbuf, "%d%*s", &maxind);
        if (prev_maxind != maxind)
        {
            --itr;
            prev_maxind = maxind;
        }

        snprintf(sendbuf, 8, "%d", maxind + 4);
        printf("send val = %s\n", sendbuf);
        if (wval = write(sock, sendbuf, sizeof(sendbuf)) < 0)
            perror("writing on stream socket\n");
    }

    printf("TERMINATING P2, TASK COMPLETED.\n");
    close(sock);
}