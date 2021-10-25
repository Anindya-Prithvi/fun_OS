#include<stdio.h>
void C(){
    printf("---\nCongrats, I made it to C\nEnding program now\n");
    //the end :)

    asm volatile(
        "mov rax, 60\n\t"
        "mov rdi, 0\n\t"
        "syscall\n\t"
        :
        :
    );

    printf("If exit call works, this wont print");
}