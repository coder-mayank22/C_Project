#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int coeff;
	int expo;
	struct node* next;
}*poly1= NULL,*poly2= NULL,*n1,*poly3 = NULL;

void display_add()
{
	struct node *ptr4 = poly3;
	while (ptr4 != NULL)
	{
		printf ("%4d", ptr4->coeff);
		printf ("%4d", ptr4->expo);
		ptr4 = ptr4 ->next;
	}
	printf ("NULL");
}

void addition()
{
	struct node* ptr1 =poly1;
	struct node* ptr2 =poly2;
	struct node* ptr3 =poly3;
	struct node* ptr =poly3;
	
	while (ptr1!= NULL && ptr2!=NULL)
	{
		struct node* add = (struct node*) malloc(sizeof(struct node));
		if (ptr1->expo==ptr2->expo)
		{
			add->coeff=ptr1->coeff+ptr2->coeff;
			add->expo=ptr1->expo;
			add->next=NULL;
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else
		{
			if (ptr1->expo>ptr2->expo)
			{
				add->coeff=ptr1->coeff;
				add->expo=ptr1->expo;
				add->next=NULL;
				ptr1=ptr1->next;
			}
			else
			{
				add->coeff=ptr2->coeff;
				add->expo=ptr2->expo;
				add->next=NULL;
				ptr2=ptr2->next;
				
			}
		}
		if (poly3==NULL)
		{
			poly3=add;
		}
		else
		{
			ptr3 =poly3;
			while (ptr3->next!=NULL)
			{
				ptr3=ptr3->next;
			}
			//add->next=ptr3->next;
			ptr3->next=add;
		}
	}
	while (ptr1!=NULL)
	{
		struct node* add = (struct node*) malloc(sizeof(struct node));
		add->coeff=ptr1->coeff;
		add->expo=ptr1->expo;
		add->next=ptr3->next;
		ptr1=ptr1->next;
		ptr3->next=add;
	}
	while (ptr2!=NULL)
	{
		struct node* add = (struct node*) malloc(sizeof(struct node));
		add->coeff=ptr2->coeff;
		add->expo=ptr2->expo;
		add->next=ptr3->next;
		ptr2=ptr2->next;
		ptr3->next=add;
	}
}

int main()
{
	int i,b,x,coef,exp,n,a;
	printf ("Enter 1 to begin and -1 to Exit: ");
	scanf ("%d", &x);
	while (x!=-1)
	{
		printf ("\n1. Enter the first polynmial\n");
		printf ("2. Enter the second polynomial\n");
		printf ("3. Addition\n");
		printf ("Enter the your choice: ");
		scanf ("%d", &b);
		switch (b)
		{
			case 1:
				printf ("Enter the number of terms of FIRST POLYNOMIAL: ");
				scanf("%d", &n);
				for (i=1;i<=n;i++)
				{
					struct node* n1=(struct node*) malloc(sizeof(struct node));
					printf ("\nThe coefficient of 'x' is: ");
					scanf ("%d", &coef);
					printf ("\nThe exponent of 'x' is: ");
					scanf ("%d", &exp);
					n1->coeff=coef;
					n1->expo=exp;
					n1->next= NULL;
					if (poly1==NULL)
					{
						poly1 = n1;
					}
					else
					{
						struct node* ptr =poly1;
						while (ptr->next!=NULL)
						{
							ptr=ptr->next;
						}
						n1->next=ptr->next;
						ptr->next=n1;
					}
				}
				break;
			case 2:
				printf ("Enter the number of terms of SECOND POLYNOMIAL: ");
				scanf ("%d", &a);
				for (i=1;i<=a;i++)
				{
					struct node* n1=(struct node*) malloc(sizeof(struct node));
					printf ("\nThe coefficient of 'x' is: ");
					scanf ("%d", &coef);
					printf ("\nThe exponent of 'x' is: ");
					scanf ("%d", &exp);
					n1->coeff=coef;
					n1->expo=exp;
					n1->next= NULL;
					if (poly2==NULL)
					{
						poly2 = n1;
					}
					else
					{
						struct node* ptr =poly2;
						while (ptr->next!=NULL)
						{
							ptr=ptr->next;
						}
						n1->next=ptr->next;
						ptr->next=n1;
					}
				}
				display_add();
				break;
			case 3:
				addition();
				display_add();
				break;
			default:
				printf("Wrong Choice\n");
		}
		
	}
}
