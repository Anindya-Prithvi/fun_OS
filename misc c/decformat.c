#include<stdio.h>

/* print f-c table*/
main()
{
	double fahr, cel;
	double lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	while(fahr<=upper){
		cel = 5*(fahr-32)/9;
		printf("%6.0f\t%6.5f\n", fahr, cel);
		fahr = fahr + step;
	}
}