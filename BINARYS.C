#include<stdio.h>
#include<stdlib.h>
int mid;
int BinarySearch(int a[],int,int,int);
void main(){
	int a[10],n=10,flag=-1,no;
	clrscr();
	printf("ADITI MARATHE \n60019230113\n B066\n");
	for(int i=0;i<n;i++){
		printf("enter the %d element in the array:-",i+1);
		scanf("%d",&a[i]);
	}
	printf("enter the no to be searched :- ");
	scanf("%d",&no);
	flag=BinarySearch(a,0,n-1,no);
	if(flag==-1){
		printf("%d is not found",no);
	}
	else{
		printf("%d is found at index %d",no,flag);
	}
	getch();
}
int BinarySearch(int a[],int l,int h,int no){
	while(l<= h){
		mid=(l+h)/2;
		if(no==a[mid]){
			return mid;
		}
		else if(no<a[mid]){
			return BinarySearch(a,l,mid-1,no);
		}
		else if(no>a[mid]){
			return BinarySearch(a,mid+1,h,no);
		}

	}
	return -1;
}
