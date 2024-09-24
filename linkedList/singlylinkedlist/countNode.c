//count the node of linked list;
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node *head;

void creation(int n){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    int data;
    printf("Enter the data\n");
    scanf("%d",&data);
    ptr->data=data;
    while(n>1){
        struct node *new;
        new=(struct node*)malloc(sizeof(struct node));
        int data;
        printf("Enter the data\n");
        scanf("%d",&data);
        new->next=NULL;
        new->data=data;
        ptr->next=new;
        ptr=ptr->next;
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


int countNode(){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    int i=0;
    while(ptr!=NULL){
        ptr=ptr->next;
        i++;
    }
    
    return i;
}


int main(){
    head=(struct node*)malloc(sizeof(struct node));
    creation(3);
    int k=countNode();
    printf(" no. of nodes in linked list is: %d\n",k);
    
    
    return 0;
}