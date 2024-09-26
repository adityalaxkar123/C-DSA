#include <stdio.h>
#include <stdlib.h>
/*linear doubly linkedlist*/
struct node{
    int data;
    struct node*prev;
    struct node*next;
};

struct node*head;

struct node* createNode(){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("allocation failed!!\n");
        exit(0);
    }
    return temp;
}

void creation(int n){
    
    struct node*temp = createNode();
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
        struct node*new = createNode();
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
    struct node*ptr = createNode();
    ptr=head;
    while(ptr!=NULL){
        i++;
        printf(" data of %d node is %d\n",i,ptr->data);
        ptr=ptr->next;
    }
    
}


void insertionAtBeginning(int n){
    struct node*ptr = createNode();
    ptr->data=n;
    ptr->next=head;
    head->prev = ptr;
    ptr->prev=NULL;
    head=ptr;
}

void insertionAtLast(int n){
    struct node*ptr = createNode();
    struct node*ptr2 = createNode();
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr2->data=n;
    ptr->next=ptr2;
    ptr2->prev=ptr;
    ptr2->next=NULL;
}

void insertionInBetween(int n,int x){
    if(x == 1){
        insertionAtBeginning(n);
        return;
    }
    struct node*ptr1 = createNode();
    ptr1=head->next;
    struct node*ptr2 = createNode();
    ptr2 = head;
    int i=0;
    struct node* newNode = createNode();
    newNode->data=n;
    while(ptr1->next!=NULL){
        i++;
        if(i == x - 1){
            break;
        }
        ptr1=ptr1->next;
        ptr2 = ptr2->next;
    }
    newNode->next = ptr1;
    newNode->prev = ptr2;
    ptr2->next = newNode;
    ptr1->prev = newNode;
}

void deletionAtBeginning(){
    struct node*ptr = createNode();
    ptr = head;
    head = head->next;
    head->prev =NULL;
    free(ptr);
}

void deletionAtLast(){
    struct node*ptr = createNode();
    ptr=head->next;
    struct node*ptr2 = createNode();
    ptr2=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
        ptr2=ptr2->next;
    }
    ptr2->next=NULL;
    free(ptr);
}

void deletionInBetwen(int n){
    if(n == 1){
        deletionAtBeginning();
        return;
    }
    struct node*ptr = createNode();
    ptr=head->next;
    struct node*ptr2 = createNode();
    ptr2=head;
    int i=0;
    while(ptr->next!=NULL){
        i++;
        if(i == n - 1){
            break;
        }
        ptr=ptr->next;
        ptr2=ptr2->next;
    }
    ptr2->next=ptr->next;
    ptr->next->prev = ptr2;
    free(ptr);
}

int main(){
    head=createNode();
  int s;
    printf("Enter the list number\n");
    scanf("%d",&s);
    creation(s);
    traversal();
    int n;
    printf("Enter the number of query\n");
    scanf("%d",&n);
    while(n>0){
        int m;
        printf("Enter for following operation\n 1.for insertionAtBeginning\n 2.for insertionAtlast\n 3.for insertionInBetween\n 4.for deleteAtBeginning\n 5.for deletionAtLast\n 6.for deletionInBetween\n");
        scanf("%d",&m);
        switch(m){
            case 1:
                int d1;
                printf("Enter the data\n");
                scanf("%d",&d1);
                insertionAtBeginning(d1);
                traversal();
                break;
                
            case 2:
                int d2;
                printf("Enter the data\n");
                scanf("%d",&d2);
                insertionAtLast(d2);
                traversal();
                break;
            case 3:
                int d3;
                int d4;
                printf("Enter the data\n");
                scanf("%d",&d3);
                printf("Enter position\n");
                scanf("%d",&d4);
                insertionInBetween(d3,d4);
                traversal();
                break;
            case 4:
                deletionAtBeginning();
                traversal();
                break;
            case 5:
                deletionAtLast();
                traversal();
                break;
            case 6:
                int d5;
                printf("Enter position\n");
                scanf("%d",&d5);
                deletionInBetwen(d5);
                traversal();
                break;    
                
            default:
                printf("invalid input!!\n");
                break;
        }
        n--;
    }
    return  0;
}