#include <stdio.h>

struct c256int
{
    unsigned char num[32];
};

//#define c256int struct c256int
typedef struct c256int c256int;

void prettyprint(c256int* num1) {
    int i;
    for ( i = 0; i < 32; i += 1) {
        char temp = *(num1->num + i);
        printf("%X ", (unsigned)temp);
    }
    printf("\n");
}

int main() {

    // generate random number
    c256int num1;
    int i;
    for (i = 0; i < 32; i++) {
        num1.num[i] = rand() % 256;
    }


    printf("First number: %d\n", (int)num1.num[0]);
    prettyprint(&num1);
    printf("First number (part 2): %d\n", (int)num1.num[0]);
}