#include<stdio.h>
#include<stdlib.h>
#define N 4

void enqueue();
void dequeue();
void queuefront();
void queuerear();
void display();

int front=-1, rear=-1, queue[N];

void main(){
    int data,choice;
    printf("Name: Aditi Marathe \n");
    printf("SAP ID: 60019230113");
    do{
	printf("\n\nChoose Operation to perform on Circular Queue: ");
	printf("\n1. EnQueue \n2. DeQueue \n3. QueueFront \n4. QueueRear \n5. Display \n6. Exit\n");

	scanf("%d",&choice);

	switch(choice){
	    case 1:
		enqueue();
		display();
		break;
	    case 2:
		dequeue();
		display();
		break;
	    case 3:
		queuefront();
		break;
	    case 4:
		queuerear();
		break;
	    case 5:
		display();
		break;
	    case 6:
		exit(0);
		break;
	}
    }while(0<choice<5);
}

void enqueue(){
    int data;
    printf("Enter element to EnQueue: ");
    scanf("%d",&data);
    if(front==-1 && rear==-1){
	front=rear=0;
	queue[rear]=data;
    }
    else if((rear+1)%N==front){
	printf("OVERFLOW");
    }
    else{
	rear++;
	queue[rear]=data;
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("EMPTY");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        printf("%d POPPED", queue[front]);
        front=(front+1)%N;
    }
}

void display(){
    int i;
    printf("\nCurrent Queue: \n");
    if (front>rear){
        for(i=front;i<N;i++){
            printf("%d \t",queue[i]);
    
        }
        for(i=0;i<=rear;i++){
            printf("%d \t",queue[i]);
        }
    }
    else{
        for(i=front;i<=rear;i++){
            printf("%d \t",queue[i]);
    }
}
}

void queuefront(){
    printf("Element at FRONT: %d \n",queue[front]);
}

void queuerear(){
    printf("Element at REAR: %d \n",queue[rear]);
}

