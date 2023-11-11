#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
//Insertion of elements at the first
void insert(int item)
{
	struct node *n;
	n= (struct node *)malloc(sizeof(struct node));
	n->data = item;
	//n->next = NULL;
	n->next = head;
	head = n;
}
//Traversal from last position to first position
int Traverse(int n)
{
	//int a[50];
	int i=0,j,c;
	printf("Elements are: \n");
	struct node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		//a[i++]=ptr->data;
		ptr=ptr->next;
	}
	printf("\n");
	
	ptr=head;
	struct node *ptr1;
	int flag;
	while(ptr!=NULL)
	{
		flag=0;
		ptr1=head;
		while(ptr1!=ptr)
		{
			if(ptr1->data==ptr->data){
				flag=1;
				break;
			}
			ptr1=ptr1->next;
		}
		if(flag==1){
			ptr=ptr->next;
			continue;
		}
		else
		{
			c=0;
			printf("Frequency of %d = ",ptr->data);
			struct node *ptr2;
			ptr2=head;
			while(ptr2!=NULL)
			{
				if(ptr2->data==ptr->data)c++;
				ptr2=ptr2->next;
			}
			printf("%d\n",c);
		}//end of else
		ptr=ptr->next;
	}//end of while
}

int main()
{
	int no;
    printf("Enter number of elements \n");
    scanf("%d",&no);
    for(int i=1;i<=no;i++)
    {
       	int ins;
        printf("Insert element %d : ",i);
        scanf("%d",&ins);
        insert(ins);
   	}
    Traverse(no);
}
