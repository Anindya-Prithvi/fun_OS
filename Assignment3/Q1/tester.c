#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SYS_rtdelay 548

int fib(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		printf("Please tell delay\n");
		return -1;
	}
	else
	{
		printf("delay given is: %dms\n", atoi(argv[1]));
	}

	printf("eval: %d\n", syscall(SYS_rtdelay, getpid(), atoi(argv[1])));
	printf("fibo: %d\n", fib(46));

	return 0;
}
