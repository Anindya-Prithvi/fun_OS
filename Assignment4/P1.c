#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define SYS_writer 548
#define SYS_reader 549

unsigned long readbytes()
{
	FILE *cmd = popen("head -c 8 /dev/random", "r");
	char *buff = malloc(sizeof(long));
	fread(buff, 1, 8, cmd);
	fclose(cmd);
	return (unsigned long)buff;
}

int main()
{
	int i = 1;
	while (i < 10000)
	{
		unsigned long to_write = readbytes();
label:
		usleep((rand()%300)*1000);
		printf("I am about to write: %lu \n", to_write); //easier to verify long unsigned
		// write(1, &to_write, 8);
		//printf("\n");
		int x = syscall(SYS_writer, to_write);
		if (x == 0)
		{
			++i;
			printf("Write successful!\n");
			continue;
		}
		perror("Queue is full! Read it\n");
		goto label;
		//else keep reattempting | we shall send the same dev random
	}
	return 0;
}
