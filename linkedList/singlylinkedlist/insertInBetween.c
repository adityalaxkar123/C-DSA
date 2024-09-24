#include <stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

struct node *head;



void insertionInBetween(int n,int x){
    struct node*temp=(struct node*)malloc(sizeof(struct node*));
     struct node*ptr=(struct node*)malloc(sizeof(struct node*));
     ptr=head;
    int i=0;
    while(head!=NULL){
         i++;
    if(i==x-1){
        break;
    }
    head=head->next;
   
    }
    temp->data=n;
    temp->next=head->next;
    head->next=temp;
    head=ptr;
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
insertionInBetween(10,2);
traversal();
insertionInBetween(27,3);
traversal();

}