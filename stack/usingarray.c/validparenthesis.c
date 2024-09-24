#include <stdio.h>
#define N 20
char str[N] = "(((()))";
char stack[N] = "";
int top = -1;
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
        return '1';
    }
    else{
         ch = stack[top--];
    }
    return ch;
}

int match(char a,char b){
    if(a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b == ']'){
        return 1;
    }
    return 0;
}

void valid(){
    for(int i = 0;i<N;i++)
    {
        char ch = str[i];
        if(ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']')
        {
            if(top == -1)
            {
                printf("not valid\n");
                return;
            }
            else if(match(stack[top],str[i]))
            {
                pop();
            }
        }
    }
    if(top == -1){
        printf("valid\n");
    }
    else{
        printf("not valid\n");
    }
}

int main()
{
    valid();
    return 0;
}