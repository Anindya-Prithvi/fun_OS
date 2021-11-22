#include<unistd.h>
#include<sys/syscall.h>
#include<stdio.h>
#include<malloc.h>

#define SYS_memcpy 548

int main(){
	double arr[4][3] = {	{1.24,		2.234,		3.345664},
				{2.123456,	3.300240,	4.32445345},
				{3.1415923,	4.23894583,	5.23298348},
				{4.0001,	5.23425422,	6.6969669}	};
	//declared floating point matrix

	double* copyto = malloc(sizeof(arr));

	//print both locations
	printf("%p %p\n", arr, copyto);

	//TEST THE SYSCALL
	//syscall number 548
	//first arg: copy_from
	//second arg: cells_to_copy
	//third arg: copy_to location

	printf("eval: %p\n", syscall(SYS_memcpy, arr, 12, copyto));

	//declare iterator
	int i;

	//print from the destination array
	for(i=0; i<12; i++){
		printf("%0.17lf ",*copyto++);
	}
	return 0;
}
