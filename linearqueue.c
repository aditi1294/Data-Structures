#include <stdio.h> 
#include<conio.h> 
#define MAX 5 
void EnQueue(int data); 
void DeQueue(); 
void QueueFront(); 
void QueueRear(); 
void display(); 
int front=-1,rear=-1,queue[MAX]; 
int main() 
{ 
 int data,choice; 
 clrscr(); 
do
 { 
 printf("\n***QUEUE OPERATIONS***"); 
 printf("\n1. EnQueue\n2.DeQueue\n3.QueueFront\n4.QueueRear\n5.EXIT"); 
 printf("\n Enter The Choice:"); 
 scanf("%d",&choice); 
 switch(choice) 
 { 
 case 1: printf("\n Enter Data to add into Queue:"); 
 scanf("%d",&data); 
 EnQueue(data); 
 break; 
 case 2: DeQueue(); 
 break; 
 case 3: QueueFront(); 
 break; 
 case 4: QueueRear(); 
 break; 
 case 5: exit(0); 
 default: printf("\n Enter Correct Choice"); 
 } 
 }while(choice!=5); 
 getch(); 
 return 0; 
} 
void EnQueue(int data) 
{ 
 if(rear==(MAX-1)) 
    printf("\n Queue is Full..."); 
 else 
 { 
    if(rear==-1)
     front=rear=0; 
 rear++; 
 queue[rear]=data; 
 printf("\n After Enqueu Operation Queue is:"); 
 display(); 
 } 
 printf("\n FRONT=%d \t REAR=%d",front,rear); 
} 
void DeQueue() 
{ 
 if(front==-1)
 printf("\n Queue is Underflow DeQueue Operation is not possible"); 
 else 
 { 
 printf("\n Element Dequeued is: %d\n",queue[front]); 
    if(front==rear) 
        front=rear=-1;
    else 
        front++; 
 display(); 
 printf("\n FRONT=%d \t REAR=%d",front,rear); 
 } 
} 
void QueueFront() 
{ 
 if(rear==-1)
 printf("\n Queue is Empty."); 
 else 
 printf("Data at the Front end of the Queue is: %d",queue[front]); 
} 
void QueueRear() 
{ 
 if(rear==-1)
 printf("\n Queue is Empty."); 
 else 
 printf("Data at the Rear end of the Queue is: %d",queue[rear]); 
} 
void display() 
{ 
 int i; 
 if(rear==-1)
 printf("\n Queue is Empty."); 
 else 
 { 
printf("FRONT:"); 
 for(i=front;i<=rear;i++) 
 { 
    printf("%d",queue[i]); 
    printf(" <== "); 
 } 
 printf(":REAR"); 
 } 
}