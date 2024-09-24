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

int main(){
    head=(struct node*)malloc(sizeof(struct node));
    creation(3);
    traversal();
}