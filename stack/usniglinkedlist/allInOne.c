//using linked list
#include <stdio.h>
#include <stdlib.h>
struct stack{
    int data;
    struct stack *next;
};


struct stack *top;

int isEmpty(){
    if(top->next==NULL){
        return 1;
    }
    else{
        return 0;
    }
    
}

int isFull(){
    struct stack *p=(struct stack*)malloc(sizeof(struct stack));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
    
}



void push(int n){
    struct stack*ptr=(struct stack*)malloc(sizeof(struct stack));
    ptr->data=n;
    if(ptr==NULL){
        printf("allocation failed!!\n");
        return;
    }
    else if(isFull(top)){
        printf("stack overflow\n");
        return;
    }
    printf("%d is pushed\n",ptr->data);
    ptr->next=top;
    top=ptr;
}

void peek(){
    struct stack *ptr=(struct stack*)malloc(sizeof(struct stack));
    if(ptr==NULL){
        printf("allocation failed!!\n");
        return;
    }
    ptr=top;
    int i=0;
    while(ptr->next!=NULL){
        i++;
        printf("the data of stack member %d is %d\n",i,ptr->data);
        ptr=ptr->next;
    }
    
}

void pop(){
    struct stack *ptr=(struct stack*)malloc(sizeof(struct stack));
    if(ptr==NULL){
        printf("allocation failed!!\n");
        return;
    }
    else if(isEmpty(top)){
        printf("stack underflow\n");
        return;
    }
    ptr=top;
    printf("%d is popped\n",ptr->data);
    top=top->next;
    free(ptr);
}

void stackTop(){
    printf("the top element of stack member is %d\n",top->data);
}

void stackBottom(){
    struct stack *ptr=(struct stack*)malloc(sizeof(struct stack));
    ptr=top;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    printf("the bottom element of stack member is %d\n",ptr->data);
}

void searchInStack(int n){
    struct stack *ptr=(struct stack*)malloc(sizeof(struct stack));
    ptr=top;
    int i=0;
    while(ptr!=NULL){
        i++;
        if(ptr->data == n){
        printf("found at position %d\n",i);
        break;
        }
        ptr=ptr->next;
    }
    
    
}

void countStackMember(){
    struct stack *ptr=(struct stack*)malloc(sizeof(struct stack));
    ptr=top;
    int i=0;
    while(ptr->next!=NULL){
        ptr=ptr->next;
        i++;
    }
    printf("the number of stack members is %d\n",i);
}

int main()
{
    top=(struct stack*)malloc(sizeof(struct stack));
    top->next=NULL;
    
    push(8);
    pop();
    push(10);
    push(12);
    push(14);
    push(16);
    pop();
    push(18);
    peek();
    stackTop();
    stackBottom();
    searchInStack(14);
    countStackMember();
 }