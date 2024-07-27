#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int main(){
	int n=5,data,flag=0;
	int a[MAX];
	clrscr();
	printf("ADITI MARATHE\n60019230113\nB066\n");
	for(int i=0;i<n;i++){
		printf("Enter the elements in the array:-");
		scanf("%d",&a[i]);
	}
	printf("\nEnter data to search:- ");
	scanf("%d",&data);
	for(int i=0;i<n;i++){
		if(a[i]==data){
			printf("\nDATA is found at index %d",i);
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("\nDATA is not found");
	}
	getch();
	
	}

