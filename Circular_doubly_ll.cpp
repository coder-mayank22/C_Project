#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node *head=NULL;

struct node* Createnode(int item)
{
	struct node* n;
	n=(struct node*)malloc(sizeof(struct node*));
	n->data=item;
	n->next=NULL;
	return n;
}
void cir_insert_begin(int item)
{
	struct node* n=Createnode(item);
	n->next=head;
	head=n;
	struct node* ptr=head;
	if(head!=NULL)
	{
		while(ptr->next!=NULL){
		    ptr=ptr->next;
	    }
	    ptr->next=n;
	}
}//end of insert_begin

void cir_insert_last(int item)
{
	struct node* n=Createnode(item);
	struct node* ptr=head;
	if(head==NULL){
		cir_insert_begin(item);
	}
	else
	{
		while(ptr->next!=head){
		    ptr=ptr->next;
	    }
	    ptr->next=n;
	    n->next=head;
	}
}//end of insert_last

void cir_del_first()
{
	struct node* del;
	if(head==NULL){
	    printf("Empty list\n");
	    return;
	}
	else if(head->next==head)
	{
		printf("Single element circular list\n");
		del=head;
		head=NULL;
		free(del);
}
	else
	{
		struct node* ptr=head;
		del=head;
		while(ptr->next!=head){
			ptr=ptr->next;
		}
		head=head->next;
		ptr->next=head;
		free(del);
	}
}//end of del_first

void cir_del_last()
{
	struct node* ptr=head,*preptr;
	if(head==NULL)
	{
		printf("Empty list\n");
		return;
	}
	else if(head->next==head)
	{
		printf("Single element circular list\n");
		struct node* del=head;
		head=NULL;
		free(del);
	}
	else
	{
		while(ptr->next!=head){
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=head;
		free(ptr);
	}
}//end of del_last

void cir_Traverse()
{
	struct node* ptr=head;
	do{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}while(ptr!=head);
}//end of cir_Traverse

struct d_node
{
	int data;
	struct d_node *next;
	struct d_node *prev;
};

struct d_node *head1=NULL;

struct d_node* Createnode1(int item)
{
	struct d_node* n;
	n=(struct d_node*)malloc(sizeof(struct d_node*));
	n->data=item;
	n->prev=NULL;
	n->next=NULL;
}

void doubly_insert_first(int item){
	struct d_node* n=Createnode1(item);
	if(head1==NULL)
	head1=n;
	else{
		n->next=head1;
		head1->prev=n;
		head1=n;
	}
}

void doubly_insert_last(int item)
{
	if(head1==NULL)doubly_insert_first(item);
	else{
		struct d_node *n=Createnode1(item);
		struct d_node *ptr=head1;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		n->prev=ptr;
		ptr->next=n;
	}
}

void d_del_before(int ele)
{
	struct d_node* del,*ptr,*preptr;
	if(head1->data==ele)printf("First element. Node before cannot be deleted.\n");
	else if(head1==NULL)printf("Empty list\n");
	else if(head1->next==NULL){
		printf("Single element present.Node cannot be deleted before.\n");
	}
	else if((head1->next)->data==ele){
		del=head1;
		head1=head1->next;
		free(del);
	}
	else
	ptr=head1;
	while(((ptr->next)->next)->data!=ele){
		ptr=ptr->next;
	}
	del=ptr->next;
	(del->next)->prev=ptr;
	ptr->next=del->next;
	free(del);
}
void dTraverse(){
	struct d_node* ptr = head1;
	printf("--Current List--\n");
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

int main()
{
	int no=5,i,ins;
	for(i=1;i<=5;i++)
	{
		printf("Insert element %d :\n",i);
		scanf("%d",&ins);
		doubly_insert_last(ins);
	}
	dTraverse();
	int conti,ele;
	do{
		printf("Enter element before which element is to be deleted: \n");
		scanf("%d",&ele);
		d_del_before(ele);
		dTraverse();
		printf("Do you want to continue?(1/0)\n");
		scanf("%d",&conti);
	}while(conti==1);
}
