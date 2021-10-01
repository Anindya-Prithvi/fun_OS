#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {
   //cmpfunc is returning int and it is not of much importance algorithmically
   //send the cmp value to sgn function 
   long long diff = ( ((long long)*(unsigned int*) a) - ((long long)*(unsigned int*) b) );
   return (diff>0)?1:(diff<0)?-1:0;
}

int main(int argc, char const *argv[])
{
   //create random array
   unsigned int arr[] = {111,2,3,4,4294967290, 4294967295,10400,5,6,7,8};
   //quicksort, LL added to avoid warning
   qsort(arr, sizeof(arr)/(sizeof(int)), sizeof(int), cmpfunc);
   //invoke binary search on element 10400 and print if found or not
   printf("%s\n",(binsearch(arr, 0, sizeof(arr)/sizeof(*arr)-1, 10400)==-1)?"Not found":"Found");
   getchar();
   return 0;
}

int binsearch(unsigned int* arr, int start, int end, unsigned int element){
   //classical binary search impl.
   if (end>=start){
      int mid = (end + start)/2;
      //printf("%d ",mid);
      if (arr[mid] == element)
         return mid;
      if (arr[mid] > element)
         return binsearch(arr, start, mid-1, element);
      return binsearch(arr, mid+1, end, element);
   }
   return -1;
}