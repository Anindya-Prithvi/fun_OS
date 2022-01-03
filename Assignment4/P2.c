#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define SYS_writer 548
#define SYS_reader 549

int main()
{
	while (1)
	{
		usleep((rand() % 350) * 100); //35ms
		long unsigned popped = syscall(SYS_reader);
		if ((int)popped == -1)
		{
			printf("Error occured?\n");
			if (errno == EAGAIN)
			{
				perror("empty buffer\n");
				// printf("Reading failed, buffer empty, reattempting!");
				continue;
			}
		}
		else
		{
			printf("I read: %lu\n", popped);
			printf("Done reading!\n");
		}
	}
	return 0;
}
