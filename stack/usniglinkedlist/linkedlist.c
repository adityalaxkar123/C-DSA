/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* top = 0;

struct node* createNode(){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        exit(0);
    }
    return temp;
}

void push(int x){
    struct node* newNode = createNode();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void display(){
    struct node* temp = createNode();
    temp = top;
    if(top == 0){
        printf("stack is empty\n");
        return;
    }
    else{
        while(temp!=0){
            printf("%d\t",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

void pop(){
    if(top == 0){
        printf("stack underflow\n");
        return;
    }
    else{
        top=top->next;
    }
}
void peek(){
    if(top == 0){
        printf("stack is empty\n");
        return;
    }
    else{
        printf("%d\n",top->data);
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    // pop();
    // pop();
    // pop();
    // pop();
    // pop();
    display();
    peek();

    return 0;
}