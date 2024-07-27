#include <stdio.h>
#include<conio.h>
#define MAX 5
void push(int data);
void pop();
void stackTop();
void display();
int tos=-1,stack[MAX];


int main()
{
	int data=1,choice;
	do
	{   printf("\n***STACK OPERATIONS***");
		printf("\n1. PUSH\n2.POP\n3.STACKTOP\n4.DISPLAY\n5.EXIT");
		printf("\n Enter The Choice:");
		scanf("%d",&choice);
		switch(choice)

		{
			case 1: printf("\n Enter Data to add into stack:");
				scanf("%d",&data);
				push(data);
				display();
				break;
			case 2: pop();
				display();
				break;
			case 3: stackTop();
				display();
				break;
			case 4: display();
				break;
			case 5: exit(0);
			default: printf("\n Enter Correct Choice");
		}

	}while(choice!=5);
	getch();
	return 0;
}

void push(int data)
{
	if(tos==(MAX-1))
		printf("\n Stack is Full cant Push Element...");
	else
		{       tos++;
			stack[tos]=data;
			printf("\n After Push Operation Stack is:");

		}
}
void pop()
{
	if(tos==-1)
		printf("\n Stack is Underflow POP Operation is not possible");
	else
		{
			printf("\n Element Popped is: %d",stack[tos]);
			tos--;
		}
}
void stackTop()
{
		if(tos==-1)
			printf("\n Stack is Empty.");
		else
			printf("Data at the top of the stack is: %d",stack[tos]);
}
void display()
{
	int i;
	if(tos==-1)
		printf("\n Stack is Empty.");
	else
		{
			for(i=tos;i>=0;i--)
			{
				printf("\n\t\t\t\t%d",stack[i]);
				printf("\n\t\t\t\t______");

			}
		}

}

