#include<stdio.h>
#include<stdlib.h>

int main(){
    //each pointer is of 8bytes
    int sizecol[6] = {7,4,6,3,7,2};
    long* matr[]={malloc(sizecol[0]*sizeof(int)), malloc(sizecol[1]*sizeof(int)), 
                malloc(sizecol[2]*sizeof(int)), malloc(sizecol[3]*sizeof(int)),
                malloc(sizecol[4]*sizeof(int)), malloc(sizecol[5]*sizeof(int))};
    int i,j;
    for(i=0;i<6;i++){
        for(j=0;j<sizecol[i];j++){
            *(*(matr+i)+j)=i+7*j;
            //add gdb watch on *(*(matr+i)+j) to see the array at work
            printf("%d ",*(*(matr+i)+j));
        }
        printf("\n");
    }
    getchar();
    return 0;
}