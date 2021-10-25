#include<stdio.h>

void swapint(int *a, int *b){
   int temp = *a;
   *a = *b;
   *b = temp;
}

void swaparr(int *a, int sz, int *b){
   int i=0;
   for(i=0; i<sz; i++){//swap each element
      swapint(a+i,b+i);//access using address of array + offset (less than size)
   }
}

int main(int argc, char const *argv[])
{
   int a = 10;
   int b = 12;
   printf("preswap==>\ta: %d, b: %d\n", a, b);
   swapint(&a,&b);
   printf("postswap==>\ta: %d, b: %d\n\n", a, b);

   int array1[3] = {1,2,3};
   int array2[3] = {4,5,6};
   printf("preswap==>\tarray1: %d %d %d\n", array1[0], array1[1], array1[2]);
   printf("preswap==>\tarray2: %d %d %d\n", array2[0], array2[1], array2[2]);
   swaparr(array1, sizeof(array1)/4, array2);
   printf("postswap==>\tarray1: %d %d %d\n", array1[0], array1[1], array1[2]);
   printf("postswap==>\tarray2: %d %d %d\n", array2[0], array2[1], array2[2]);
}