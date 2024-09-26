#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node*head;

struct node* createNode(){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("allocation failed\n");
        exit(0);
    }
    return temp;
}

void createList(int num){
    struct node* temp = createNode();
    temp = head;
    int data;
    printf("Enter the data\n");
    scanf("%d",&data);
    temp->data = data;
    temp->prev = NULL;
    
    while(num>1){
        struct node* newNode = createNode();
        printf("Enter the data\n");
        scanf("%d",&newNode->data);
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
        temp = newNode;
        num--;
    }
    temp->next = head;
    head->prev = temp;
}

void traversal(){
    struct node* ptr = createNode();
    ptr=head;
    printf("%d\t",ptr->data);
    ptr=ptr->next;
    while(ptr!=head){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void insertAtBeginning(int data){
    struct node* temp = createNode();
    struct node* ptr = createNode();
    ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    // printf("cheak2\n");
    temp->data = data;
    temp->next = head;
    temp->prev = head->prev;
    head->prev = temp;
    head=temp;
    ptr->next=head;
}

void insertAtEnd(int data){
    struct node* ptr = createNode();
    ptr=head;
    while(ptr->next!=head){
        ptr = ptr->next;
    }
    struct node* temp = createNode();
    temp->data = data;
    temp->next = ptr->next;
    ptr->next = temp;
    temp->prev = ptr;
    head->prev = temp;
}

void insertInBetween(int data, int n){
    if(n == 1){
        insertAtBeginning(data);
        return;
    }
    struct node* ptr1 = createNode();
    struct node* ptr2 = createNode();
    ptr1 = head->next;
    ptr2 = head;
    int i = 0;
    while(ptr1->next!=head){
        i++;
        if(i == n - 1){
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    struct node* newNode = createNode();
    newNode->data = data;
    newNode->next = ptr1;
    newNode->prev = ptr2;
    ptr2->next = newNode;
    ptr1->prev = newNode;
    
}

void deleteAtBeginning(){
    struct node* ptr1 = createNode();
    ptr1=head->next;
    while(ptr1->next!=head){
        ptr1=ptr1->next;
    }
    struct node*ptr2 = createNode();
    ptr2 = head;
    head = head->next;
    head->prev = ptr1;
    ptr1->next = head;
    free(ptr2);
}

void deleteAtLast(){
    struct node* ptr1 = createNode();
    struct node* ptr2 = createNode();
    ptr1 = head->next;
    ptr2 = head;
    while(ptr1->next!=head){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr2->next =head;
    head->prev = ptr2;
    free(ptr1);
}

void deleteInBetween(int n){
    if(n == 1){
        deleteAtBeginning();
        return;
    }
    struct node* ptr1 = createNode();
    struct node* ptr2 = createNode();
    ptr1 = head->next;
    ptr2 = head;
    int i = 0;
    while(ptr1->next!=head){
        i++;
        if(i == n - 1){
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr2->next = ptr1->next;
    ptr1->next->prev = ptr2;
    free(ptr1);
}

int main(){
    head = createNode();
    int s;
    printf("Enter the list number\n");
    scanf("%d",&s);
    createList(s);
    traversal();
    int n;
    printf("Enter the number of query\n");
    scanf("%d",&n);
    while(n>0){
        int m;
        printf("Enter for following operation\n 1.for insertionAtBeginning\n 2.for insertionAtlast\n 3.for insertionInBetween\n 4.for deleteAtBeginning\n 5.for deletionAtLast\n 6.for deletionInBetween\n");
        scanf("%d",&m);
        switch(m){
            case 1:
                int d1;
                printf("Enter the data\n");
                scanf("%d",&d1);
                insertAtBeginning(d1);
                traversal();
                break;
                
            case 2:
                int d2;
                printf("Enter the data\n");
                scanf("%d",&d2);
                insertAtEnd(d2);
                traversal();
                break;
            case 3:
                int d3;
                int d4;
                printf("Enter the data\n");
                scanf("%d",&d3);
                printf("Enter position\n");
                scanf("%d",&d4);
                insertInBetween(d3,d4);
                traversal();
                break;
            case 4:
                deleteAtBeginning();
                traversal();
                break;
            case 5:
            
                deleteAtLast();
                traversal();
                break;
            case 6:
                int d5;
                printf("Enter position\n");
                scanf("%d",&d5);
                deleteInBetween(d5);
                traversal();
                break;    
                
            default:
                printf("invalid input!!\n");
                break;
        }
        n--;
    }
    
}