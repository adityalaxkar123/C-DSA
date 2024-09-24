

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
int stack[N];
int top = -1;

void push(int x){
    if(top == N - 1){
        printf("stack overflow\n");
        return;
    }
    else{
        top++;
        stack[top]=x;
    }
}

int pop(){
    int val;
    if(top == -1){
        printf("stack underflow\n");
        return -1;
    }
    else{
        val = stack[top--];
    }
    return val;
}

int isNum(char ch){
    if(ch >='0' && ch<='9'){
        return 1;
    }
    return 0;
}



int eval(int op1,int op2,char ch){
    switch(ch){
        case'+':
            return op1+op2;
            break;
        case'-':
            return op1-op2;
            break;
        case'*':
            return op1*op2;
            break;
        case'/':
            return op1/op2;
            break;
        default:
            printf("wrong operator\n");
            break;
    }
    return -1;
}

int final(char str[]){
    int op1,op2;
    for(int i = 0;i<strlen(str);i++){
        char ch = str[i];
        if(isNum(ch)){
            int x = atoi(&ch);
            push(x);
        }
        else{
            op2 = pop();
            op1 = pop();
            int val = eval(op1,op2,ch);
            push(val);
        }
    }
    if(top == 0){
        return pop();
    }
    return -1;
}


int main()
{
    
    char str[] = "534*+82/-4+5-";
    int value = final(str);
    printf("evaluation is:%d\n",value);
    return 0;
}