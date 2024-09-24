#include <stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

// void traversal(struct node*head){
//     int i=0;
//     while(head!=NULL){
//         i++;
//         printf(" data of %d node is %d\n",i,head->data);
//         head=head->next;
//     }
    
// }


int search(struct node*head,int n){
    while(head!=NULL){
        if(head->data==n){
            return 1;
        }
        head=head->next;
    }
    return 0;
}

int main(){



struct node *head;
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

// traversal(head);
int n;
printf("Enter the number you want to search\n");
scanf("%d",&n);
int k=search(head,n);
if(k==1){
    printf("found");
}
else{
    printf("not found");
}
}