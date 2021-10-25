#include<stdio.h>
//please see the .exe as well, recompiling MAY change the behaviour
void a();
void b();
void c();

int main(){
    //call a, a calls b, b returns to c
    long arr[1];
    
    printf("old ret main: %p\n", __builtin_return_address(0));
    a();
    arr[6] = 0x4013e8;
    printf("back to main: %p\n", __builtin_return_address(0));
     //overwrite
}

void a(){
    printf("a has been called\n");
    printf("addr of main: %p\n", main);
    b();
    printf("THIS WILL NOT PRINT\n");
    printf("ret a: %p\n", __builtin_return_address(0));
    
    return; //returning to main
}

void b(){
    long arr[1]; //after brute force, it was found return address is at index 6
    arr[6]=&c; //overwrite return addr to jump to c
        //printf("addrs: offset -%d-> %p\n",i, *(arr-i));
    printf("b has been called\n");
    printf("ret b: %p\n", __builtin_return_address(0));
    return;
}

void c(){
    long arr[1];
    arr[6] = 0x401555; //return to main (not the beginning lol)
    printf("last function to be called\n");
    printf("ret c: %p\n", __builtin_return_address(0));
}