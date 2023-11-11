#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct node{
	char data;
	struct node *next;
};

struct node *top=NULL,*head=NULL;
int check=0;

struct node* Createnode(char item){
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	n->data=item;
	n->next=NULL;
	return n;
}
void push_final_exp(char item){
	struct node *n=Createnode(item);
	if(head==NULL){
		head=n;
	}
	else{
		struct node *ptr=head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=n;
	}
}

void push_stack(char item){
	struct node *n=Createnode(item);
	if(top==NULL){
		top=n;
		//top->next=NULL;
	}
	else{
		n->next=top;
		top=n;
	}
}

char pop_stack(){
	char pop_ele;
	if(top==NULL){
		printf("UNDERFLOW\n");
	}
	else{
		pop_ele=top->data;
		struct node *del=top;
		top=top->next;
		free(del);
	}
	return pop_ele;
}

int search_pos(char a[],char x){
	int i,position;
	for(i=0;a[i]!='\0';i++){
		if(a[i]==x){
			position=i;
			return position;
		}
	}
	if(check==0)
	return 5;//For open parenthesis
	else
	return -1;
}

void convert(char exp[]){
	char precedence[]="^*/+-";
	//printf("%d\n",search_pos(precedence,'+'));
	int i;
	for(i=0;exp[i]!='\0';i++){
		int a=int(exp[i]);
		if(!(a>=65 && a<=90||a>=97 && a<=122) && exp[i]!=')'){
			if(top==NULL){
				push_stack(exp[i]);
				printf("Top element = %c\n",top->data);
			}
			else{
				if(top!=NULL && exp[i]=='('){
					check=1;
				    while(search_pos(precedence,exp[i])>search_pos(precedence,top->data)){
				    	push_final_exp(pop_stack());
					    printf("top element after pop-> %c\n",top->data);
				    }
				    check=0;
				}
				else
				while(search_pos(precedence,exp[i])>search_pos(precedence,top->data)){
					push_final_exp(pop_stack());
					printf("top element after pop-> %c\n",top->data);
				}
				if(search_pos(precedence,exp[i])<search_pos(precedence,top->data)){
					push_stack(exp[i]);
					printf("Top element= %c\n",top->data);
					//check=1;
				}
				else if(exp[i]=='(')
				push_stack(exp[i]);
				
				else
				{
					do{
						push_final_exp(pop_stack());
						
					}while(search_pos(precedence,exp[i])>search_pos(precedence,top->data));
				}
			}
		}
		else if(exp[i]!=')'){
			push_final_exp(exp[i]);
			struct node *ptr=head;
				while(ptr!=NULL){
		            printf("%c",ptr->data);
		            ptr=ptr->next;
              	}
	        printf("\n");
		}
		
		else{
			while(top->data!='('){
				char p=pop_stack();
				push_final_exp(p);
				printf("Pushed operator = %c\n",p);
				printf("Top element = %c\n",top->data);
			}
			top=top->next;
			//check=1;
		}
	}
}

int main(){
	char exp[MAX];
	printf("Enter the infix expression :");
	scanf("%[^\n]%*c",exp);
	//Conversion to postfix
	convert(exp);
	//Displaying the postfix expression
	printf("\nThe Postfix expression is : ");
	struct node *ptr=head;
	while(ptr!=NULL){
		printf("%c",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

