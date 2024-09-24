
#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = x;
        return;
    }
    else if((rear + 1)%N == front){
        printf("queue is full\n");
        return;
    }
    else{
        rear = (rear + 1)%N;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("queue is empty\n");
        return;
    }
    else if(rear == front){
        rear = -1;
        front = -1;
        return;
    }
    else{
        front = (front + 1)%N;
    }
}

void display(){
    int i = front;
    if(front == -1 && rear == -1){
        printf("queue is empty\n");
        return;
    }
    else{
        while(i!=rear){
            printf("%d\t",queue[i]);
            i = (i + 1)%N;
        }
        printf("%d\n",queue[rear]);
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

int main()
{
    enqueue(9);
    enqueue(8);
    dequeue();
    display();
    // display();
    // enqueue(8);
    // enqueue(7);
    // enqueue(6);
    // // display();
    // dequeue();
    // enqueue(5);
    // dequeue();
    // dequeue();
    // // display();
    // // enqueue(4);
    // // enqueue(3);
    // // enqueue(2);
    // dequeue();
    // dequeue();
    // display();
    // enqueue(1);
    
    
    return 0;
}
