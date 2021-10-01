#include<stdio.h>

void bubblesort(int* arr, int len);
void selectionsort(int* arr, int len);
void swapint(int *a, int *b);

int main(){//inplace sort
    printf("Enter number of elements to be sorted: ");
    int els;
    scanf("%d",&els);
    printf("\nEnter the elements (space seperated):\n");
    int arr[els];
    int i,j;
    for(i=0; i<els; i++){
        scanf("%d",&arr[i]);
    }
    //print array to be sorted
    printf("Array to be sorted-> ");
    for(i=0;i<sizeof(arr)/sizeof(int);i++){
        printf("%d ",*(arr+i));
    }

    printf("\n\nChoose:\n1.Bubble sort\n2.Selection sort\n\n");
    scanf("%d",&j);

    if((j>2)||(j<1)){printf("Invalid, exit"); return 1;}
    if(j==1){
        bubblesort(arr, sizeof(arr)/sizeof(int));
    }
    else if(j==2){
        selectionsort(arr, sizeof(arr)/sizeof(int));
    }
    //print sorted array
    printf("Sorted array-> ");
    for(i=0;i<sizeof(arr)/sizeof(int);i++){
        printf("%d ",*(arr+i));
    }
    getchar();
}

void bubblesort(int* arr, int len){
    int i,j;
    for(i=len-1;i>-1;i--){
        for(j=0;j<i;j++){
            if(*(arr+j)>*(arr+j+1)){
                swapint(arr+j,arr+j+1);
            }
        }
    }
}

void selectionsort(int* arr, int len){
    int* minptr;
    int i,j,m;
    for(i=0;i<len-1;i++){
        m=arr[i];
        minptr = arr+i;
        for(j=i+1;j<len;j++){
            if(arr[j]<m){m=arr[j];minptr=arr+j;}
        }
        swapint(minptr,arr+i);
    }
}

void swapint(int *a, int *b){
   int temp = *a;
   *a = *b;
   *b = temp;
}