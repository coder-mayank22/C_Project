#include<stdio.h>
int a[50],n;
void input()
{
	int i;
	printf("Enter values for the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}//end f input()

int Merge(int lb,int mid,int ub)
{
	int i=lb,j=mid+1,k=lb;
	int b[n];
	while(i<=mid && j<=ub)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	while(i<=mid)
	b[k++]=a[i++];
	while(j<=ub)
	b[k++]=a[j++];
	//copying the values of array b into array a
	k=lb;
	while(k<=ub){
		a[k]=b[k];
		k++;
	}
}
void Mergesort(int lb,int ub)
{
	if(lb<ub)
	{
		int mid=(lb+ub)/2;
		Mergesort(lb,mid);
		Mergesort(mid+1,ub);
		Merge(lb,mid,ub);
	}
}
int main()
{
	printf("Enter size of the array\n");
	scanf("%d",&n);
	int i;
	//Input the array
	input();
	//Displaying original array
	printf("--Original Array--\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
	//sorting the array
	Mergesort(0,n-1);
	//Displaying sorted array
	printf("--Sorted Array--\n");
	for(i=0;i<n;i++)printf("%d ",a[i]);
	printf("\n");
}
