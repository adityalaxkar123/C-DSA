#include <stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

struct node *head;

void creation(int n){
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    int data;
    printf("Enter the data\n");
    scanf("%d",&data);
    temp->data=data;
    while(n>1){
        int data;
        printf("Enter the data\n");
        scanf("%d",&data);
        struct node*new=(struct node*)malloc(sizeof(struct node));
        new->data=data;
        temp->next=new;
        new->next=NULL;
        temp=temp->next;
        n--;
 }
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
int n;
head=(struct node*)malloc(sizeof(struct node));
printf("Enter the number of list\n");
scanf("%d",&n);
creation(n);
traversal();
}