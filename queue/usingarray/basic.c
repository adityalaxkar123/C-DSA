#include <stdio.h>
#include <stdlib.h>
#define N 5
int queue[N];
int rear = -1;
int front = -1;

void enqueue(int x){
    if(rear == N - 1){
        printf("queue overflow\n");
        return;
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
        return;
    }
    else{
        rear++;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("queue underflow\n");
        return;
    }
    else if(front == rear){
        front = rear = -1;
        return;
    }
    else{
        front++;
    }
}

void peek(){
    if(front == -1 && rear == -1){
        return;
    }
    else{
        printf("%d\n",queue[front]);
    }
}

void display(){
    if(front ==-1 && rear == -1){
        return;
    }
    else{
        for(int i = front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
        printf("\n");
    }
}

int main(){
    enqueue(2);
    enqueue(9);
    // display();
    enqueue(3);
    enqueue(4);
    enqueue(8);
    // enqueue(7);//because not the circular queue
    dequeue();
    // enqueue(7);
    display();
    peek();
    return 0;
}