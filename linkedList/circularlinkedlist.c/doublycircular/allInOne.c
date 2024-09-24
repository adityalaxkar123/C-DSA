#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node*head;

struct node* createNode(){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("allocation failed\n");
        exit(0);
    }
    return temp;
}

void createList(int num){
    struct node* temp = createNode();
    temp = head;
    int data;
    printf("Enter the data\n");
    scanf("%d",&data);
    temp->data = data;
    temp->prev = NULL;
    
    while(num>1){
        struct node* newNode = createNode();
        printf("Enter the data\n");
        scanf("%d",&newNode->data);
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
        temp = newNode;
        num--;
    }
    temp->next = head;
    head->prev = temp;
}

void reverseTraversal(){
    struct node* ptr = createNode();
    ptr=head->prev;
    printf("%d\t",ptr->data);
    ptr=ptr->prev;
    while(ptr!=head){
        printf("%d\t",ptr->data);
        ptr=ptr->prev;
    }
    printf("%d\t",head->data);
    printf("\n");
}

void traversal(){
    struct node* ptr = createNode();
    ptr=head;
    printf("%d\t",ptr->data);
    ptr=ptr->next;
    while(ptr!=head){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void insertAtBeginning(int data){
    struct node* temp = createNode();
    struct node* ptr = createNode();
    ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    // printf("cheak2\n");
    temp->data = data;
    temp->next = head;
    temp->prev = head->prev;
    head->prev = temp;
    head=temp;
    ptr->next=head;
}

void insertAtEnd(int data){
    struct node* ptr = createNode();
    ptr=head;
    while(ptr->next!=head){
        ptr = ptr->next;
    }
    struct node* temp = createNode();
    temp->data = data;
    temp->next = ptr->next;
    ptr->next = temp;
    temp->prev = ptr;
    head->prev = temp;
}

int  nodeLength(){
    struct node* ptr = createNode();
    int count = 0;
    while(ptr->next!=head){
        count++;
        ptr = ptr->next;
    }
    return count;
}


int main(){
    head = createNode();
    createList(3);
    traversal();
    // printf("cheak1\n");
    insertAtBeginning(1);
    // printf("cheak3\n");
    traversal();
    insertAtEnd(8);
    traversal();
    
}