#include<stdio.h>
int a[50],n;
void input()
{
	int i;
	printf("Enter %d values to the array\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
}//end of input()

int insert_first(int item)
{
	int i;
	for(i=n;i>=1;i--)
	a[i]=a[i-1];
	a[0]=item;
	n+=1;
	return 0;
}//end of insert_first()

int insert_last(int item)
{
	a[n]=item;
	n+=1;
	return 0;
}//end of insert_last()

int insert_any(int pos,int item)
{
	int i;
    for(i=n;i>pos;i--)a[i]=a[i-1];
	a[pos]=item;
	n+=1;
	return 0;
}//end of insert_any()

int delete_first()
{
	int i;
	for(i=0;i<n-1;i++)a[i]=a[i+1];
	n=n-1;
	return 0;
}//end of delete_first()

int delete_last()
{
	n=n-1;
	return 0;
}//end of delete_last()

int delete_any(int pos)
{
	int i;
	for(i=pos;i<n-1;i++)a[i]=a[i+1];
	n=n-1;
	return 0;
}//end of delete_any()

int main()
{
	int i;
	printf("Enter size of the array\n");
	scanf("%d",&n);
	//input array elements
	input();
	//Displaying original array
	printf("--Original Array--\n");
	for(i=0;i<n;i++)printf("%d ",a[i]);
	printf("\n");
	//Switch case
	int conti;
	do
	{
		printf("Press 1 to insert element\n");
		printf("Press 2 to delete element\n");
		printf("Press 3 to display the array\n\n");
		int c1,item;
		printf("Enter choice :\n");
		scanf("%d",&c1);
		switch(c1)
		{
			case 1:
				//int item;
				printf("Enter item to be inserted\n");
				scanf("%d",&item);
				printf("Press 1 to insert at first\n");
				printf("Press 2 to insert at last\n");
				printf("Press 3 to insert at any position\n\n");
				int c2,position;
				printf("Enter choice :\n");
				scanf("%d",&c2);
				switch(c2)
				{
					case 1:
						insert_first(item);
						break;
					case 2:
						insert_last(item);
						break;
					case 3:
						printf("Enter position where the item should be inserted\n");
						scanf("%d",&position);
						insert_any(position,item);
						break;
					default: printf("WRONG CHOICE\n");
				}//end of switch(c2)
				break;
			case 2:
				printf("Press 1 to delete from first\n");
				printf("Press 2 to delete from last\n");
				printf("Press 3 to delete from any position\n\n");
				int c3,position1;
				printf("Enter choice :\n");
				scanf("%d",&c3);
				switch(c3)
				{
					case 1:
						delete_first();
						break;
					case 2:
						delete_last();
						break;
					case 3:
						printf("Enter position from where element is to be deleted\n");
						scanf("%d",&position1);
						delete_any(position1);
						break;
					default: printf("WRONG CHOICE\n");
				}//end of switch(c3)
				break;
			case 3:
				printf("--Current Array--\n");
				for(i=0;i<n;i++)printf("%d ",a[i]);
				printf("\n");
				break;
			default: printf("WRONG CHOICE\n");
		}//end of switch(c1)
		
		printf("Do you want to continue?(1/0)\n");
		scanf("%d",&conti);
	}while(conti==1);
	return 0;
}//end of main()
