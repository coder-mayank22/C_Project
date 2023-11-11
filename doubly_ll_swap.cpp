#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
};

struct node* Createnode(int item)
{
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	n->data=item;
	n->prev=NULL;
	n->next=NULL;
	return n;
}
struct node *head=NULL,*tail=NULL;
void insert_first(int item){
	struct node* n=Createnode(item);
	n->next=head;
	head=n;
}

void insert_last(int item){
	struct node* n=Createnode(item);
	if(head==NULL)insert_first(item);
	else{
		struct node* ptr=head;
	    while(ptr->next!=NULL)
	    {
	    	ptr=ptr->next;
		}
		ptr->next=n;
		n->prev=ptr;
	}
}

void Traverse()
{
	printf("--Current List--\n");
	struct node* ptr=head;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

void swap(int no)
{
	int i;
	struct node *ptr=head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	tail=ptr;
	ptr=head;
	for(i=1;i<=(int)no/2;i++)
	{
		int data_ptr=ptr->data;
		ptr->data=tail->data;
		tail->data=data_ptr;
		ptr=ptr->next;
		tail=tail->prev;
	}
}

int main()
{
	int i,no,ins;
	printf("Enter number of terms : ");
	scanf("%d",&no);
	for(i=1;i<=no;i++)
	{
		printf("Insert element %d : ",i);
		scanf("%d",&ins);
		insert_last(ins);
	}
	Traverse();//to display the linked list before sorting
	swap(no);//to swap the elements according the given condition
	printf("--List After Swapping--\n");
	struct node *ptr=head;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
	return 0;
}
