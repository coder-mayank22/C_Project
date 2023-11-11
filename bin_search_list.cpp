#include<stdio.h>
#include<stdlib.h>
int no;
struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;

/*void Createnode(int item){
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	n->data=item;
	n->next=NULL;
}*/

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

struct Array{
	int index;
	int val;
}s[5];
void sort(int n)
{
	int i=0,j,t,a[n];
	struct node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		a[i++]=ptr->data;
		ptr=ptr->next;
	}
	int swap;
	for(i=0;i<n-1;i++)
	{
		swap=0;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				swap=1;
			}
		}
		if(swap==0)break;
	}
	for(i=0;i<n;i++)
	{
		s[i].index=i;
		s[i].val=a[i];
	}
	//storing sorted list
	ptr=head;
	i=0;
	while(ptr!=NULL)
	{
		ptr->data=a[i++];
		ptr=ptr->next;
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
