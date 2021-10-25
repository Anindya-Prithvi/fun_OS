#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
extern void B(long arg);

void A(){
    printf("---\nA was called\n");
    long arg = 478560413000L;
    printf("Going to B now, bye\n");
    B(arg);
}

int main(){
    printf("---\nBeginning program from main()\nCalling A\n");
    A();
    return 0;
}
