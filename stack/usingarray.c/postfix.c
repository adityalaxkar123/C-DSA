#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
char stack[N];
int top = -1;
char expr[] = "1+3*4+2^3*4+5";

void push(char ch){
    if(top == N - 1){
        printf("stack overflow\n");
        return;
    }
    else{
        top++;
        stack[top] = ch;
    }
}

char pop(){
    char ch;
    if(top == -1){
        printf("stack underflow\n");
        return ' ';
    }
    else{
        ch = stack[top];
        top--;
    }
    return ch;
}

int rightAsso(char ch){
    if(ch == '^'){
        return 1;
    }
    return 0;
}

int expressionCheak(char ch){
    switch(ch){
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
        default:
            printf("wrong input\n");
            break;
    }
    return 1;
}

int validatePriority(char ch1,char ch2){
    if(expressionCheak(ch1)<expressionCheak(ch2)){
        return 1;
    }
    else if(expressionCheak(ch1) == expressionCheak(ch2)){
        if(rightAsso(ch1)){
            return 1;
        }
        return 0;
    }
    else if(expressionCheak(ch1)>expressionCheak(ch2)){
        return 0;
    }
    return 0;
}


int isOperand(char ch){
    if(ch >= '0' && ch <='9'){
        return 1;
    }
    return 0;
}

void final(char ans[]){
    int k = 0;
    for(int i = 0;i<strlen(expr);i++){
        char ch =expr[i];
        if(isOperand(ch)){
            ans[k++]=ch;
        }
        else if(ch == '('){
            push(ch);
        }
        else if(ch == ')'){
            char symb = pop();
            while(symb!='(' || top != -1){
                ans[k++]=symb;
                symb=pop();
            }
        }
        else{
            if(top == -1){
                push(ch);
            }
            else{
                if(validatePriority(stack[top],ch)){
                push(ch);
                    }
                else{
                char symb;
                while(top !=-1 && validatePriority(stack[top],ch) !=1){
                    symb = pop();
                    ans[k++]=symb;
                    
                }
                push(ch);
                }
            }
        }
    }
    while(top !=-1){
        ans[k++]=pop();
    }
}


int main(){
    int n = strlen(expr);
    char ans[n];
    final(ans);
    for(int i = 0;i<strlen(ans);i++){
        printf("%c",ans[i]);
    }
    return 0;
}