#include<stdio.h>
#include<stdlib.h>

int main(){
    //each pointer is of 8bytes
    printf("Enter 6 numbers delimitted by space:\n");
    int sizecol[6];
    {scanf("%d",sizecol),scanf("%d",sizecol+1),scanf("%d",sizecol+2),
    scanf("%d",sizecol+3),scanf("%d",sizecol+4),scanf("%d",sizecol+5);}
    long* matr[]={malloc(sizecol[0]*sizeof(int)), malloc(sizecol[1]*sizeof(int)), 
                malloc(sizecol[2]*sizeof(int)), malloc(sizecol[3]*sizeof(int)),
                malloc(sizecol[4]*sizeof(int)), malloc(sizecol[5]*sizeof(int))};
    int i,j;
    for(i=0;i<6;i++){
        for(j=0;j<sizecol[i];j++){
            *(*(matr+i)+j)=i; //populated with row number since const
            //add gdb watch on *(*(matr+i)+j) to see the array at work
            printf("%d ",*(*(matr+i)+j));
        }
        printf("\n");
    }
    getchar();
    return 0;
}