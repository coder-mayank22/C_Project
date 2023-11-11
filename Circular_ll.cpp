#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* head=NULL;

struct node* Createnode(int item){
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	n->data=item;
	n->next=NULL;
	return n;
}

void insert_first(int item){
	struct node *n=Createnode(item);
	if(head==NULL){
		head=n;
		n->next=head;
	}
	else if(head->next==head){
		n->next=head;
		head->next=n;
		head=n;
	}
	else{
		struct node *ptr=head;
		do{
			ptr=ptr->next;
		}while(ptr->next!=head);
		n->next=head;
		head=n;
		ptr->next=head;
	}
}

void insert_last(int item){
	struct node *n=Createnode(item);
	if(head==NULL)insert_first(item);
	else{
		struct node *ptr=head;
		while(ptr->next!=head){
			ptr=ptr->next;
		}
		ptr->next=n;
		n->next=head;
	}
}

void del_first(){
	struct node *ptr=head,*del;
	if(head==NULL){
		printf("Empty circular singly linked list\n");
		return;
	}
	else if(head->next==head){
		del=head;
		head=NULL;
		free(del);
	}
	else{
		while(ptr->next!=head){
			ptr=ptr->next;
		}
		del=head;
		head=head->next;
		ptr->next=head;
		free(del);
	}
}

void del_last(){
	struct node *ptr=head,*del;
	if(head==NULL){
		printf("Empty circular singly linked list\n");
		return;
	}
	else if(head->next==head){
		del=head;
		head=NULL;
		free(del);
	}
	else{
		while((ptr->next)->next!=head){
			ptr=ptr->next;
		}
		del=ptr->next;
		ptr->next=head;
		free(del);
	}
}

void traverse()
{
	if(head==NULL)printf("Empty List.\n");
	else{
		struct node *ptr=head;
    	printf("--Current List--\n");
    	do{
    		printf("%d ",ptr->data);
    		ptr=ptr->next;
    	}while(ptr!=head);
    	printf("\n");
	}
}

int main(){
	int i,ins,conti;
	do{
		printf("Press 1 to insert an element\n");
		printf("Press 2 to delete an element\n");
		printf("Press 3 to display the list\n");
		int ch;
		printf("\nEnter choice :\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter item to be inserted : \n");
				scanf("%d",&ins);
				printf("Press 1 to insert at beginning\n");
				printf("Press 2 to insert at last\n");
				int c1;
				printf("\nEnter choice :\n");
				scanf("%d",&c1);
				switch(c1)
				{
					case 1:
						insert_first(ins);
						break;
					case 2:
						insert_last(ins);
						break;
					default:printf("WRONG CHOICE\n");
				}//end of switch(c1)
				break;
				
			case 2:
				printf("Press 1 to delete from beginning\n");
				printf("Press 2 to delete from last\n");
				int c2;
				printf("\nEnter choice :\n");
				scanf("%d",&c2);
				switch(c2)
				{
					case 1:
						del_first();
						break;
					case 2:
						del_last();
						break;
					default:printf("WRONG CHOICE\n");
				}//end of switch(c2)
				break;
			case 3:
				traverse();
				break;
			default:printf("WRONG CHOICE\n");
		}//end of switch(ch)
		printf("Do you want to continue?(1/0)\n");
		scanf("%d",&conti);
	}while(conti==1);
}
