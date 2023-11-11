#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head=NULL;

struct node* Createnode(int item){
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	n->data=item;
	n->next=NULL;
	n->prev=NULL;
	return n;
}

void insert_first(int item)
{
	struct node *n=Createnode(item);
	if(head==NULL){
		head=n;
	}
	else{
		n->next=head;
		head->prev=n;
		head=n;
	}
	/*else{
		struct node *ptr=head;
		while()
	}*/
}

void insert_last(int item){
	struct node *n=Createnode(item);
	if(head==NULL)head=n;
	else{
		struct node *ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=n;
		n->prev=ptr;
		n->next=NULL;
	}
}

void insert_before(int item, int ele){
	if(head==NULL)
	{
		printf("Empty List. Element cannot be inserted before.\n");
		return;
	}
	else if(head->data==ele){
		insert_first(item);
	}
	else if(head->next==NULL){
		insert_first(item);
	}
	else{
		struct node *ptr=head,*n=Createnode(item);
		while((ptr->data)!=ele){
			ptr=ptr->next;
		}
		(ptr->prev)->next=n;
		n->prev=ptr->prev;
		n->next=ptr;
		ptr->prev=n;
	}
}

void insert_after(int item,int ele){
	if(head==NULL){
		printf("Empty list. Element cannot be inserted after.\n");
		return;
	}
	else{
		struct node *ptr=head, *n=Createnode(item);
		while((ptr->data)!=ele){
			ptr=ptr->next;
		}
		if(ptr->next==NULL)insert_last(item);
		else{
			(ptr->next)->prev=n;
			n->next=ptr->next;
			ptr->next=n;
			n->prev=ptr;
		}
	}
}

void del_first(){
	if(head==NULL){
		printf("Empty List\n");
		return;
	}
	else{
		struct node *del=head;
		head=head->next;
		free(del);
	}
}

void del_last(){
	struct node *del, *ptr;
	if(head==NULL){
		printf("Empty List\n");
		return;
	}
	else if(head->next==NULL){
		del=head;
		head=NULL;
		free(del);
	}
	else{
		ptr=head;
		while((ptr->next)->next!=NULL){
			ptr=ptr->next;
		}
		del=ptr->next;
		ptr->next=NULL;
		free(del);
	}
}

void del_before(int ele){
	struct node *del, *ptr;
	if(head==NULL){
		printf("Empty List\n");
		return;
	}
	else if(head->next==NULL){
		printf("Single element list. Element cannot be deleted before.\n");
	}
	else if((head->next)->data==ele){
		del=head;
		head=head->next;
		free(del);
	}
	else{
		ptr=head;
		while(ptr->data!=ele){
			ptr=ptr->next;
		}
		del=ptr->prev;
		((ptr->prev)->prev)->next=ptr;
		ptr->prev=(ptr->prev)->prev;
		free(del);
	}
}

void del_after(int ele){
	struct node *del, *ptr;
	if(head==NULL){
		printf("Empty List\n");
		return;
	}
	else if(head->next==NULL){
		printf("Single element list. Element cannot be deleted after.\n");
	}
	else if(head->data==ele && (head->next)->next==NULL){
		del=head->next;
		head->next=NULL;
		free(del);
	}
	else{
		ptr=head;
		while(ptr->data!=ele){
			ptr=ptr->next;
		}
		if(ptr->next==NULL){
			printf("Last Node. Element cannot be deleted after.\n");
		}
		else if((ptr->next)->next==NULL){
			del=ptr->next;
			ptr->next=NULL;
			free(del);
		}
		else{
			del=ptr->next;
			((ptr->next)->next)->prev=ptr;
			ptr->next=(ptr->next)->next;
			free(del);
		}
	}
}

void traverse(){
	struct node *ptr=head;
	printf("--Current List--\n");
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

int main()
{
	int ins,ele,conti;
	do{
		printf("Press 1 to insert an element\n");
		printf("Press 2 to delete an element\n");
		printf("Press 3 to display the list\n");
		int ch;
		printf("\nEnter choice :\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter element to be inserted :\n");
				scanf("%d",&ins);
				printf("Press 1 to insert at first\n");
				printf("Press 2 to insert at last\n");
				printf("Press 3 to insert before an element\n");
				printf("Press 4 to insert after an element\n");
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
					case 3:
						printf("Enter element before which item is to be inserted :\n");
						scanf("%d",&ele);
						insert_before(ins,ele);
						break;
					case 4:
						printf("Enter element after which item is to be inserted :\n");
						scanf("%d",&ele);
						insert_after(ins,ele);
						break;
					default:printf("WRONG CHOICE\n");
				}//end of c1
				break;
			
			case 2:
				printf("Press 1 to delete from first\n");
				printf("Press 2 to delete from last\n");
				printf("Press 3 to delete before an element\n");
				printf("Press 4 to delete after an element\n");
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
					case 3:
						printf("Enter element before which item is to be deleted :\n");
						scanf("%d",&ele);
						del_before(ele);
						break;
					case 4:
						printf("Enter element after which item is to be deleted :\n");
						scanf("%d",&ele);
						del_after(ele);
						break;
					default:printf("WRONG CHOICE\n");
				}//end of c2
				break;
			
			case 3:
				traverse();
				break;
			default:printf("WRONG CHOICE\n");
		}//end of ch
		printf("Do you want to continue?(1/0)\n");
		scanf("%d",&conti);
	}while(conti==1);
}
