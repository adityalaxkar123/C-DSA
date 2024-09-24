#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;

void traversal(){
    int i=0;
    struct node*ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    while(ptr!=NULL){
        i++;
        printf(" data of %d node is %d\n",i,ptr->data);
        ptr=ptr->next;
    }
    
}


void deletionAfterNode(struct node *ptr){

struct node *ptr2;
ptr2=(struct node*)malloc(sizeof(struct node));
ptr2=ptr->next;
ptr->next=ptr2->next;

if(ptr2->next!=NULL){
    ptr2->next->prev=ptr;
}

free(ptr2);


}


int main(){

head=(struct node*)malloc(sizeof(struct node));


struct node *first;
struct node *second;
struct node *third;
first=(struct node*)malloc(sizeof(struct node));
second=(struct node*)malloc(sizeof(struct node));
third=(struct node*)malloc(sizeof(struct node));


//linked of head and first
head=first;
first->data=15;
//linked of first and second
first->next=second;
first->prev=NULL;
second->data=20;
//linked of second and third
second->next=third;
second->prev=first;
third->data=25;
//termination of linked list 
third->prev=second;
third->next=NULL;

traversal();
deletionAfterNode(second);
traversal();


    return 0;
}