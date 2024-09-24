#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};


struct stack *s;

int isFull(){
    if(s->size == s->top + 1){
    return 1;
    }
    else{
    return 0;
    }
}

int isEmpty(){
if(s->top == -1){
    return 1;
}   
else{
    return 0;
}
}



void push(int n){
    
    if(isFull(s)){
        printf("stack overflow\n");
        return;
    }
   s->top++;
   s->arr[s->top]=n;
   printf("%d is pushed\n",s->arr[s->top]);
}

void pop(){
    
    if(isEmpty(s)){
        printf("stack underflow\n");
        return;
    }
    printf("%d is popped\n",s->arr[s->top]);
    s->top--;
}

void peek(){
    int peek=0;
    for(int i=0; i < s->top + 1;i++){
        peek++;
        printf("the data of stack position %d is %d\n",peek,s->arr[s->top - peek + 1]);
    }
}

void stackTop(){
    printf("the topmost position of stack is %d\n",s->arr[s->top]);
}

void stackBottom(){
    printf("the bottom position of stack is %d\n",s->arr[0]);
}

void searchInStack(int n){
    for(int i=0;i<s->top + 1;i++){
        if(n==s->arr[i]){
            printf("found at position %d\n",i + 1);
        }
    }
    
}

void countStackMember(){
    int count=0;
    for(int i=0;i<s->top + 1;i++){
        count++;
    }
    printf("the number of member in stack is: %d\n",count);
    
}

int main()
{
    s=(struct stack*)malloc(sizeof(struct stack));
    s->size = 8;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    
    push(8);
    peek();
    push(10);
    peek();
    push(12);
    peek();
    push(14);
    peek();
    push(16);
    peek();
    push(18);
    peek();
    push(20);
    peek();
    push(22);
    peek();
    pop();
    push(24);
    peek();
    stackTop();
    stackBottom();
    searchInStack(20);
    countStackMember();
    // push(1);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
 }