#include<stdio.h>

/* copy i-/o ;*/
main()
{
	int c;
	while(c=getchar()){
		putchar(c);
		if(c==EOF){break;}
	}
}