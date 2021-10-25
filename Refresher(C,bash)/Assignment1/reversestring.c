#include <stdio.h>

/*Input expected
A string and an EOF or newline. behaviour
can be changed by removing break*/

#define MAXLINE 1000

void reverse(char to[], char from[], int size);

void main(){
	char from[MAXLINE], c;
	int i=0;
	while((c=getchar())!=EOF){//read in char array till EOF or newline
		if(c=='\n'){break;} //behaviour changer
		from[i]=c;
		++i;
	}
	char rev[i+1];
	reverse(rev, from, i);//from doesnt store \0
	printf("%s\n",rev);
	getchar();
}

void reverse(char to[], char from[], int size){
	int i;
	for(i=0; i<size; i++){
		to[size-i-1]=from[i];
	}
	to[size]='\0';//to print using %s
}
