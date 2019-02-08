#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void insertLoc();

struct node{
    int info;
    struct node *link;
};

struct node *start = NULL;

int main() {
    char ch = 'y';
    create();
    display();
    while(ch=='y'||ch=='Y'){
        printf("Do you want to add more no. betwn linked list (y/n):");
        scanf_s("%c",ch);
        if(ch=='y'||ch=='Y')
           insertLoc();
    }
    return 0;
}

void create(){
    struct node *tmp,*ptr;
    int item;
    char ch='y';
    while (ch=='y'||ch=='Y'){
        tmp = (struct node*)malloc(sizeof(struct node));
        if(tmp==NULL){
            printf("Memory Overflow");
            exit(0);
        }
        printf("enter info value");
        scanf_s("%d",&item);
        tmp->info = item;
        tmp->link = NULL;
        if (start == NULL)
            start = tmp;
        else{
            ptr = start;

            while (ptr->link!=NULL)
                ptr = ptr->link;

            ptr->link = tmp;
        }
        printf("do you want to add more nodes:");
        fflush(stdin);
        scanf_s(" %c",&ch);
    }
}

void display(){
    struct node *ptr;
    if(start == NULL){
        printf("lists is empty");
        exit(0);
    } else{
        ptr = start;
        while (ptr!=NULL){
            printf(" %d",ptr->info);
            ptr=ptr->link;
        }
    }
}

void insertLoc(){
    struct node *tmp,*ptr;
    int item, pos, i;
    tmp = (struct node*)malloc(sizeof(struct node));
    if(tmp==NULL){
        printf("Overflow!");
        exit(0);
    }
    printf("Enter item Value:");
    scanf_s("%d",&item);
    printf("\n Enter position after which you want to enter:");
    scanf_s("%d",&pos);
    tmp->info = item;
    ptr = start;
    for (int i = 1; i < pos; i++) {
        if(ptr==NULL){
            printf("Enter correct locn:");
            exit(0);
        }
        ptr=ptr->link;
    }
    tmp->link = ptr->link;
    ptr->link = tmp;
}
