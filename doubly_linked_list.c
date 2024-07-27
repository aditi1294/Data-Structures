#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}Node;

struct Node *createNode(int info){
    Node *node = (Node *)malloc(sizeof(Node));
    node-> prev = NULL;
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
        start->prev = node;
        node-> next = start;
        start = node;
    }
}

void addAtLast(int info){
    temp = createNode(info);
    q = start;
    while(q->next != NULL){
        q = q-> next;
    }
    q->next = temp;
    temp->prev = q;
}

void addafter(int info){
    temp = createNode(info);
    int no;
    printf("Enter Data After Which You Want to Insert New data: ");
    scanf("%d", &no);
    q = start;
    while(q->data != no){
        q = q->next;
    }
    temp->next = q->next;
    q->next->prev = temp;
    q->next = temp;
    temp->prev = q;
}

void deleteAtFront(){
    if(start == NULL){
        printf("The List is empty.\n");
    }else{
        temp = start;
        start = temp-> next;
        start->prev = NULL;
        printf("Deleted Node is: %d\n", temp->data);
        free(temp);
    }
}

void deleteAtLast(){
    if(start == NULL){
        printf("The List is empty.\n");
    }else if(start-> next == NULL){
        free(start);
        start = NULL;
    }else{
        q = start;
        while(q->next->next != NULL){
            q = q->next;
        }
        temp = q->next;
        q->next = NULL;
        printf("Deleted Node is: %d\n", temp->data);
        free(temp);
    }
}

void deleteBeforeData(){
    if(start == NULL){
        printf("The List is empty.\n");
        return;
    }else{
        int no;
        printf("Enter Data Before Which You Want to Delete data: ");
        scanf("%d", &no);
        q=start;
        while(q->data != no){
            q = q->next;
        }
        temp = q->prev;
        q->prev = temp->prev;
        temp->prev->next = q;
        printf("Deleted Node is: %d\n", temp->data);
        free(temp);
    }
}

void deleteAfterData(){
    if(start == NULL){
        printf("The List is empty.\n");
        return;
    }else{
        int no;
        printf("Enter Data After Which You Want to Delete data: ");
        scanf("%d", &no);
        q=start;
        while(q->next->data != no){
            q = q->next;
        }
        temp = q->prev;
        temp->next = q->next;
        temp->next->prev = q;
        printf("Deleted Node is: %d\n", temp->data);
        free(temp);
    }
}

void display() {
    if(start == NULL){
        printf("List is Empty.");
    }else{
        q = start;
        printf("Linked List: ");
        while(q != NULL){
            printf("%d->",q->data);
            q = q-> next;
        }
        
        printf("NULL\n");
    }
}



int main(){
    int choice,n;
    do{
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        printf("Enter Data: ");
        scanf("%d", &n);
        addAtFront(n);
        display();
        break;
        

        case 2:
        printf("Enter Data: ");
        scanf("%d", &n);
        addAtLast(n);
        display();
        break;

        case 3:
        printf("Enter Data: ");
        scanf("%d", &n);
        addUsingData(n);
        display();
        break;

        case 4:
        deleteAtFront();
        display();
        break;

        case 5:
        deleteAtLast();
        display();
        break;

        case 6:
        deleteBeforeData();
        display();
        break;

        case 7:
        deleteAfterData();
        display();
        break;

        default:
        break;
        }
    }while(choice != 7);
    return 0;
}