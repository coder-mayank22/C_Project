#include<stdio.h>
#include<stdlib.h>
int no;
struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;

void insert_first(int item)
{
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	n->data=item;
	n->next=head;
	head=n;
}

void insert_last(int item)
{
	if(head==NULL)insert_first(item);
	else{
		struct node *n;
	    n=(struct node*)malloc(sizeof(struct node));
	    n->data=item;
	    n->next=NULL;
	    struct node *ptr;
	    ptr=head;
	    while(ptr->next!=NULL)
	    {
	    	ptr=ptr->next;
	    }
	    ptr->next=n;
	}
}

void sort(int n)
{
	int i,j,t,swap;
	struct node *ptr;
	for(i=0;i<n-1;i++)
	{
		swap=0;ptr=head;
		for(j=0;j<n-1-i;j++){
			if(ptr->data>(ptr->next)->data)
			{
				t=ptr->data;
				ptr->data=(ptr->next)->data;
				(ptr->next)->data=t;
				swap=1;
			}
			ptr=ptr->next;
		}
		if(swap==0)break;
	}
}
int main()
{
	int i;
	printf("Enter number of elements\n");
	scanf("%d",&no);
	int item;
	
	for(i=1;i<=no;i++)
	{
		printf("Insert item %d : ",i);
		scanf("%d",&item);
		insert_last(item);
	}
	sort(no);
	printf("Sorted list:\n");
	struct node *ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
