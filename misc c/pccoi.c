#include<stdio.h>

int main(){
    long pc;
    int r16,r17,r18;
    delay: 
        r16 = 60; ++pc;
    l1: 
        r17 = 255; ++pc;
    l2: 
        r18 = 255; ++pc;
    l3: 
        --r18; ++pc;
    if(r18!=0){++pc; goto l3;}
    --r17; ++pc;
    if(r17!=0){++pc;goto l2;}
    r16--; ++pc;
    if(r16!=0){++pc; goto l1;}
    ++pc;
    printf("%ld",&pc);
    return 0;
}