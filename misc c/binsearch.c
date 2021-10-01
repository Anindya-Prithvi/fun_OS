#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {
   //cmpfunc is returning int and it is not of much importance algorithmically
   //send the cmp value to sgn function 
   long long diff = ( *(long long*)a - *(long long*)b );
   return (diff>0)?1:(diff<0)?-1:0;
}

int main(int argc, char const *argv[])
{
   //create random array
   long long arr[] = {111,2,3,4,4294967290LL, 4294967295LL,10400,5,6,7,8};
   //quicksort, LL added to avoid warning
   qsort(arr, sizeof(arr)/(sizeof(long long)), sizeof(long long), cmpfunc);
   //invoke binary search on element 10400 and print if found or not
   printf("%s",(binsearch(arr, 0, sizeof(arr)/sizeof(*arr)-1, 10400)==-1)?"Not found":"Found");
   return 0;
}

int binsearch(long long* arr, int start, int end, unsigned int element){
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