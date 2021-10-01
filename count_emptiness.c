#include<stdio.h>

/* counts \s from stdin ;*/
main()
{
	long n;
	int c;
	while((c=getchar())!=EOF){
		if((c=='\t')||(c==' ')||(c=='\n')){++n; continue;}
		putchar(c);
	}
	printf("%ld",n);
}