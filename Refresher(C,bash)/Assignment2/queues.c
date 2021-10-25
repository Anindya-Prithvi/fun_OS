#include<stdio.h>
#include<stdlib.h>

struct node
{   int data;
    struct node *next; //next node in sll
};

typedef struct node node;
void enqueue(node**s, int d);
int dequeue(node**s);

int main(){
    node* baseptr = NULL;
    int i;
    for(i=0; i<5; i++){
        enqueue(&baseptr, i); //here i is some data
    }
    printf("%d\n",dequeue(&baseptr));
    printf("%d\n",dequeue(&baseptr));
    printf("%d\n",dequeue(&baseptr));
    printf("%d\n",dequeue(&baseptr));
    printf("%d\n",dequeue(&baseptr));
    printf("%d\n",dequeue(&baseptr)); //extra dequeue error handling
    getchar();//to keep it in display
    return 0;
}

void enqueue(node** this, int data){//enqueue using memaddr of variable; reassign vars
    node* newtail = malloc(sizeof(node));
    newtail->data = data;
    newtail->next = NULL;
    node* temp = *this;
    if(temp==NULL){*this = newtail; return;}
    while(temp->next!=NULL){temp = temp->next;}
    temp->next = newtail;
    return;
}

int dequeue(node** this){
    if(*this==NULL){
        printf("nothing to dequeue");
        return -1;}
    int temp = (*this)->data;
    node* tempn = (*this)->next;
    free(*this);
    *this = tempn;
    return temp;
}
