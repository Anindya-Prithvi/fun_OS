#include<stdio.h>
#include<stdlib.h>

struct student
{
    char name[100];
    char program[100];
    int rollno;
    int joining;
    struct student *next; //next node in dll
    struct student *prev; //prev node in dll
};

typedef struct student student;

void createstudent(student* n);
void show(student s);
void traverse(student* s);
void delete(student*s ,int roll);
void find(student*s, int roll); 
student* insert(student*s);

int main(){
    student head; createstudent(&head); //creates the head of dll
    head.next = NULL;
    student* curr = &head;

    //create 5 members in dll || can be more (just for demo)
    //insertion
    int mem = 2;
    while(mem--){
        curr = insert(curr); //takes any node and inserts at the end
    }

    //all methods demonstrated
    show(head);
    insert(curr);
    traverse(&head);
    find(&head, 3);//find by roll, can be anything else as well
    delete(&head, 3);
    traverse(&head);
    //deletion based on roll number (say 100)
    getchar();//to keep it in display
    return 0;
}

student* insert(student* this){
    student* curr = this;
    if(curr==NULL){
        curr = malloc(sizeof(student));
        createstudent(curr);
        curr->next = NULL;
        curr->prev = NULL;
        return curr;
    }
    while(curr->next!=NULL){curr = curr->next;}
    curr->next=malloc(sizeof(student));
    createstudent(curr->next);
    curr->next->prev = curr;
    curr = curr->next;
    curr->next=NULL;
    return this;
}

void traverse(student* this){//forward only
    student* curr = this;
    while(curr!=NULL){
        show(*curr);
        curr = curr->next;
    }
}

void find(student* this, int roll){//forward only
    student* curr = this;
    while(curr!=NULL){
        if(curr->rollno==roll){printf("\nFOUND\n");break;}
        curr = curr->next;
    }
}

void delete(student* this, int roll){//forward trav and delete
    student* curr = this;
    if(curr->rollno==roll){
        free(curr->name); free(curr->program);
        curr->next->prev = curr->prev; curr=curr->next;return;}
    while(curr!=NULL){
        if(curr->next->rollno==roll){
            student* end = curr->next->next;
            if(curr->next->next!=NULL) curr->next->next->prev = curr;
            free(curr->next);
            curr->next = end;
            printf("\nDELETED STUDENT NODE SUCCESSFULLY \n");
            break;
        }
        curr = curr->next;
        if(curr->next==NULL) {
            printf("\nSTUDENT NOT FOUND \n");
            break;
        }
    }
}

void createstudent(student* n){//regex based scanning into 100 char array
    printf("Enter name: ");
    scanf("%[A-Za-z ]%*c",(*n).name);
    printf("Enter roll number: ");
    scanf("%d%*c",&((*n).rollno));
    printf("Enter joining: ");
    scanf("%d%*c",&((*n).joining));
    printf("Enter program name: ");
    scanf("%[0-9A-Za-z\- ]%*c",(*n).program);
    printf("\n");
}

void show(student s){
    printf("name of student: %s\n",s.name);
    printf("roll number: %d\n",s.rollno);
    printf("year of joining: %d\n",s.joining);
    printf("Program enrolled %s\n\n",s.program);
}