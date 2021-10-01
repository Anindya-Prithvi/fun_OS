#include<stdio.h>
#include<malloc.h>

struct c256int
{
	unsigned char num[32];
};

//#define c256int struct c256int
typedef struct c256int c256int;

c256int* processbin(char* arr);
c256int* sumit(c256int* num1, c256int* num2);
void prettyprint(c256int* num);
int main()
{
	c256int* mynum1;
	c256int* mynum2;

	char binproc[80];
	printf("Enter first number: ");
	scanf("%s",binproc);
	mynum1 = processbin(binproc);
	printf("\nsuccess\n"); //as seen by gdb
	printf("Enter second number: ");
	scanf("%s",binproc);
	mynum2 = processbin(binproc);
	printf("\nsuccess\n"); //as seen by gdb
	c256int* thesum = sumit(mynum1, mynum2);//overflow notified
	//The computed sum has been stored in variable
	//use gdb
	prettyprint(thesum);
	return 0;
}

c256int* sumit(c256int* num1, c256int* num2){//verified
	c256int* ans = malloc(32*3);
	unsigned int extr = 0;
	int i;
	for(i=31;i>=0;i--){
		*(ans->num+i)=*(num1->num+i)+*(num2->num+i)+((unsigned char)extr);
		extr = (((unsigned int) *(num1->num+i))+((unsigned int)*(num2->num+i))+((unsigned char)extr)-*(ans->num+i))/256;
	}
	if(extr>0){printf("Overflow detected\n");}
	return ans;
}

update(char* arr, int i){//divides the number by 2
	int buff=0;
	int j;
	for(j=0;j<i;j++){
		arr[j]-='0';
		arr[j]+=buff;
		if(arr[j]%2==1){
			buff=10;
		}
		else{
			buff=0;
		}
		arr[j]=arr[j]/2+'0';
	}
}

c256int* processbin(char* arr){//attempts to convert the 256 bit integer to binary
	//get length
	int i,j,k,oof;
	for(i=0; i<79; i++){
		if(*(arr+i)=='\0'){
			break;
		}
	}
	c256int* newnum = malloc(32*3);
	for(j=0; j<32; j++){*(newnum->num+j)=0;}
	for(k=0;k<256;k++){
		if(k%8==0){
			oof=1;
		}
		else{
			oof*=2;
		}
		*(newnum->num+(255-k)/8)+=((arr[i-1]-'0')%2)*oof;
		update(arr, i);
	}
	return newnum;
}

void prettyprint(c256int* num1){
	//num is 32 byte char array (known)
	//WEIRD behaviour, printf is modifying num1->num values //fixed using malloc
	//it was a call stack issue
	int i;
	for(i=0;i<32;i+=1){
		unsigned char temp = *(num1->num+i);
		printf("%X ",(unsigned) temp);
		//printf("fniewnforg");
	}
}

