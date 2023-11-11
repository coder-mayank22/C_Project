#include<stdio.h>
#define MAX 5
int top=-1,arr[MAX];

void push(int item){
	if(top==MAX-1)
	printf("OVERFLOW\n");
	else{
		arr[++top]=item;
	}
}

int pop(){
	if(top==-1)
	printf("UNDERFLOW\n");
	else
	return arr[top--];
}

void peek(){
	if(top!=-1){
		printf("Stack Elements are : ");
		for(int i=top;i>=0;i--)
		printf("%d ",arr[i]);
		printf("\n");
	}
}

int main(){
	int conti=1,ins,pop_ele;
	printf("MAXIMUM NUMBER OF STACK ELEMENTS = %d\n\n",MAX);
	do{
		printf("Press 1 to push element into stack\n");
		printf("Press 2 to pop element from the stack\n");
		printf("Press 3 to view stack elements\n");
		printf("Press 4 to terminate\n");
		int ch;
		printf("\nEnter Choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter element to be pushed into the stack : ");
				scanf("%d",&ins);
				push(ins);
				break;
			case 2:
				pop_ele=pop();
				printf("Popped element : %d\n",pop_ele);
				break;
			case 3:
				peek();
				break;
			case 4:
				conti=0;
				break;
			default:printf("WRONG CHOICE\n");
		}
	}while(conti==1);
}
