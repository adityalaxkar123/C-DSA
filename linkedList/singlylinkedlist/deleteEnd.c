#include <stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

struct node *head;



void deletelast(){
    struct node*ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head->next;
    struct node*ptr2;
    ptr2=(struct node*)malloc(sizeof(struct node));
    ptr2=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
        ptr2=ptr2->next;
    }
    ptr2->next=NULL;
    free(ptr);
    
}


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


int main(){


struct node *first;
struct node *second;
struct node *third;
head=(struct node*)malloc(sizeof(struct node));
first=(struct node*)malloc(sizeof(struct node));
second=(struct node*)malloc(sizeof(struct node));
third=(struct node*)malloc(sizeof(struct node));


//linked of head and first
head=first;
first->data=15;
//linked of first and second
first->next=second;
second->data=20;
//linked of second and third
second->next=third;
third->data=25;
//termination of linked list 
third->next=NULL;

traversal();
deletelast();
traversal();


}