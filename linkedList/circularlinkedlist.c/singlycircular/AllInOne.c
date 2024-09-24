#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node*head; 

void creation(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        printf("Enter data of 1 node: ");
        scanf("%d", &data);
        struct node*temp=(struct node*)malloc(sizeof(struct node));
        temp=head;
        temp->data = data;
        temp->next = NULL;
        
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->next = NULL;
            temp->next = newNode;
            temp = newNode;
        }


        temp->next = head;
    }
}

void traversal()
{
    struct node *current;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        current = head;
        printf("DATA IN THE LIST:\n");

        do {
            printf("Data %d = %d\n", n, current->data);

            current = current->next;
            n++;
        }while(current != head);
    }
}

void insertionAtBeginning(int n){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=n;
    ptr->next=head;
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
 temp->next=ptr;
 head=ptr;
}

void insertionAtLast(int n){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    ptr->data=n;
    ptr->next=temp->next;
    temp->next=ptr;
}

void insertionInBetween(int n,int m){
struct node*ptr=(struct node*)malloc(sizeof(struct node));
struct node*ptr2=(struct node*)malloc(sizeof(struct node));
ptr=head;
int i=0;
while(ptr->next!=head){
i++;
if(m - 1 == i)
break;
ptr=ptr->next;
}
ptr2->data=n;
ptr2->next=ptr->next;
ptr->next=ptr2;
}

void deleteAtBeginning(){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    struct node*ptr2=(struct node*)malloc(sizeof(struct node));
    ptr2=head;
    while(ptr2->next!=head)
    ptr2=ptr2->next;
    head=head->next;
    ptr2->next=head;
    free(ptr);
    
}


void deletionAtLast(){
 struct node*ptr=(struct node*)malloc(sizeof(struct node));
 struct node*ptr2=(struct node*)malloc(sizeof(struct node));
 ptr=head->next;
 ptr2=head;
 while(ptr->next!=head){
     ptr=ptr->next;
     ptr2=ptr2->next;
 }
 ptr2->next=ptr->next;
 free(ptr);
 
 
}

void deletionInBetween(int n){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*ptr2=(struct node*)malloc(sizeof(struct node));
    ptr=head->next;
    ptr2=head;
    int i=0;
    while(ptr->next!=head){
        i++;
        if(n - 1==i){
            break;
        }
        ptr=ptr->next;
        ptr2=ptr2->next;
    }
    ptr2->next=ptr->next;
    free(ptr);
}

int main(){
    head=(struct node*)malloc(sizeof(struct node));
    int s;
    printf("Enter the list number\n");
    scanf("%d",&s);
    creation(s);
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
                insertionAtBeginning(d1);
                traversal();
                break;
                
            case 2:
                int d2;
                printf("Enter the data\n");
                scanf("%d",&d2);
                insertionAtLast(d2);
                traversal();
                break;
            case 3:
                int d3;
                int d4;
                printf("Enter the data\n");
                scanf("%d",&d3);
                printf("Enter position\n");
                scanf("%d",&d4);
                insertionInBetween(d3,d4);
                traversal();
                break;
            case 4:
                deleteAtBeginning();
                traversal();
                break;
            case 5:
                deletionAtLast();
                traversal();
                break;
            case 6:
                int d5;
                printf("Enter position\n");
                deletionInBetween(d5);
                traversal();
                break;    
                
            default:
                printf("invalid input!!\n");
                break;
        }
        n--;
    }
    
}
