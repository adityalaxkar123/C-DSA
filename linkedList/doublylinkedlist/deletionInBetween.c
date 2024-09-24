#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node*prev;
    struct node*next;
};

struct node*head;

void creation(int n){
    
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    int data;
    printf("Enter the data\n");
    scanf("%d",&data);
    temp->data=data;
    temp->prev=NULL;
    while(n>1){
        int data;
        printf("Entere the data\n");
        scanf("%d",&data);
        struct node*new;
        new=(struct node*)malloc(sizeof(struct node));
        new->next=NULL;
        new->data=data;
        temp->next=new;
        new->prev=temp;
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

void deletionInBetwen(int n){
    
    struct node*ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head->next;
    struct node*ptr2;
    ptr2=(struct node*)malloc(sizeof(struct node));
    ptr2=head;
    int i=0;
    while(i < n - 2){
        ptr=ptr->next;
        ptr2=ptr2->next;
        i++;
    }
    ptr2->next=ptr->next;
    free(ptr);
}


int main(){
    head=(struct node*)malloc(sizeof(struct node));
    creation(5);
    traversal();
    deletionInBetwen(3);
    traversal();
    
    
    
    return  0;
}