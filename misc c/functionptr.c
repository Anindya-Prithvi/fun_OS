#include<stdio.h>
#include<malloc.h>

void add(int x, int y);
void sub(int x, int y);
void mul(int x, int y);
void div(int x, int y);
void exp(int x, int y);

main(){
    void (*farray[5])(int x, int y) = {add, sub, mul, div, exp};
    // farray[0] = malloc(sizeof(add));
    (*farray[0])(10,100);
    (*farray[1])(10,100);
    (*farray[2])(10,100);
    (*farray[3])(10,100);
    (*farray[4])(10,100);
}

void add(int x, int y){
    printf("%d\n",(x)+(y));
}

void sub(int x, int y){
    printf("%d\n",(x)-(y));
}

void mul(int x, int y){
    printf("%d\n",(x)*(y));
}

void div(int x, int y){
    printf("%d\n",(x)/(y));
}

void exp(int x, int y){
    //compute x^y only integers
    if(y<0){printf("%d\n",0);return;}
    while(y--){
        x = x*x;//dont care about overflow
    }
    printf("%d\n",x);
}