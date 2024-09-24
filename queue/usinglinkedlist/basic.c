/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* front = 0;
struct node* rear = 0;

struct node* createNode(){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    return temp;
}

void enqueue(int x){
    struct node* newNode = createNode();
    newNode->data = x;
    newNode->next = 0;
    if(front == 0 && rear == 0){
        front =newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    if(front == 0 && rear == 0){
        printf("queue is empty\n");
    }
    else if(front == rear){
        front = 0;
        rear = 0;
    }
    else{
        struct node* ptr = createNode();
        ptr = front;
        front = front->next;
        free(ptr);
    }
}

void display(){
    struct node* ptr = createNode();
    ptr = front;
    if(front == 0 && rear == 0){
        printf("queue is empty\n");
        return;
    }
    else{
        while(ptr!=0){
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void peek(){
    if(front == 0 && rear == 0){
        printf("queue is empty\n");
    }
    else{
        printf("%d\n",front->data);
    }
}

int main()
{
    enqueue(9);
    enqueue(8);
    dequeue();
    dequeue();
    enqueue(7);
    enqueue(6);
    enqueue(5);
    enqueue(4);
    display();
    peek();
    

    return 0;
}