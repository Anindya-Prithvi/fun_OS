#include<stdio.h>
#include<stdlib.h>

struct node
{   int data;
    struct node *next; //next node in sll
};

typedef struct node node;
void push(node**s, int d);
int pop(node**s);

int main(){
    node* baseptr = NULL;
    int i;
    for(i=0; i<5; i++){
        push(&baseptr, i); //here i is some data
    }
    printf("%d\n",pop(&baseptr));
    printf("%d\n",pop(&baseptr));
    printf("%d\n",pop(&baseptr));
    printf("%d\n",pop(&baseptr));
    printf("%d\n",pop(&baseptr));
    printf("%d\n",pop(&baseptr)); //extra pop error handling
    getchar();//to keep it in display
    return 0;
}

void push(node** this, int data){//push using memaddr of variable; reassign vars
    node* newhead = malloc(sizeof(node));
    newhead->data = data;
    newhead->next = *this;
    *this = newhead;
    return;
}

int pop(node** this){
    if(*this==NULL){
        printf("nothing to pop");
        return -1;}
    int temp = (*this)->data;
    node* tempn = (*this)->next;
    free(*this);
    *this = tempn;
    return temp;
}
