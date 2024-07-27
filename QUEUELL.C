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

struct Node *node, *start = NULL, *q, *temp, *front = NULL, *rear = NULL;

void display() {
    if(start == NULL){
        printf("Queue is Empty.");
    }else{
        q = start;
        printf("Queue: ");
        while(q != NULL){
            printf("%d->",q->data);
            q = q-> next;
        }
        printf("NULL\n");
    }
}

void addAtLast(int info){
    temp = createNode(info);

    if(start == NULL){
        start = front = temp;
    }else{
        q = start;
        while(q->next != NULL){
            q = q-> next;
        }
        q->next = temp;
        temp->next = NULL;
    }
    rear = temp; //assigns rear to last node of the queue
}

void deleteAtFront(){
    if(start == NULL){
        printf("The List is empty.\n");
    }else{
        temp = front;
        front = temp-> next;
        start = front;
        printf("Deleted Node is: %d\n", temp->data);
        free(temp);
    }
}

void peekfront(){
    if(front == NULL){
        printf("Queue is Empty.");
    }else{
        printf("The element at the front is: %d", front->data);
    }
}

void peekrear(){
    if(front == NULL){
        printf("Queue is Empty.");
    }else if (front == rear){
        printf("The element at the rear is: %d", front->data);
    }else{
        printf("The element at the rear is: %d", rear->data);
    }
}

void isEmpty(){
    if(start == NULL){
        printf("Queue is Empty.");
    }else{
        printf("Queue is not Empty.");
    }
}

void size(){
int count=0;
    if(start == NULL){
        printf("Queue is Empty.");
    }else{
	q = start;
	while(q != NULL){
	    count++;
	    q = q->next;
	}
	printf("The size of the Queue is: %d\n", count);
    }
}

void main(){
    int n,choice;
    do{
	printf("\nEnter Choice: ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
	printf("Enter data: ");
	scanf("%d", &n);
	addAtLast(n);
	display();
	break;

	case 2:
	deleteAtFront();
	display();
	break;

	case 3:
	peekfront();
	break;

	case 4:
	peekrear();
	break;

	case 5:
	isEmpty();
	break;

	case 6:
	size();
	break;

	case 7:
	exit(0);

	default:
	printf("Invalid Input.");
	break;
	}
    }while(choice != 7);
}