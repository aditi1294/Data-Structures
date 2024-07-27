#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

struct Node *createNode(int info){
    Node *node = (Node *)malloc(sizeof(Node));
    node ->data = info;
    node ->next = NULL;
    return node;
}

struct Node *node, *start = NULL, *q, *temp;

void addAtFront(int info){
    node = createNode(info);
    if(start == NULL){
        start = node;
    }else{
        node-> next = start;
        start = node;
    }
}

void deleteAtFront(){
    if(start == NULL){
        printf("The List is empty.\n");
    }else{
        temp = start;
        start = temp-> next;
        printf("Deleted Node is: %d\n", temp->data);
        free(temp);
    }
}

void display() {
    if(start == NULL){
        printf("List is Empty.");
    }else{
        q = start;
        printf("Stack\n");
        while(q != NULL){
            printf("%d\n",q->data);
            q = q-> next;
        }
    }
}

void peek(){
    if(start == NULL){
        printf("Stack is Empty.");
    }
    else{
        printf("Top element of the Stack is: %d",start->data);
    }
}

int main(){
    int choice,n;

    do{
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
            printf("Enter data: ");
            scanf("%d", &n);
            addAtFront(n);
            display();
            break;

            case 2:
            deleteAtFront();
            display();
            break;

            case 3:
            peek();
            break;
            
            case 4:
            display();
            break;

            case 5:
            exit(0);
            break;

            default:
            break;
        }
    }while (choice != 5);
    
}