#include <stdio.h>
#define N 5
int stack[N];
int top = -1;

void push(int x){
    
    if(top == 4){
        printf("stack overflow\n");
        return;
    }
    else{
        top++;
        stack[top] = x;
    }
}

void pop(){
    if(top == -1){
        printf("stack underflow\n");
        return;
    }
    else{
        printf("popped element is :%d\n",stack[top]);
        top--;
    }
}
void peek(){
    if(top == N - 1){
        printf("stack overflow\n");
        return;
    }
    else if(top == -1){
        printf("stack underflow\n");
        return;
    }
    else{
        printf("top element is %d\n",stack[top]);
    }
}

void display(){
    for(int i = top ; i>=0;i--){
        printf("%d\t",stack[i]);
    }
    printf("\n");
}

int main(){
   push(1);
   display();
   push(2);
   display();
   pop();
   pop();
   pop();
display();
push(3);
display();
peek();
    
}