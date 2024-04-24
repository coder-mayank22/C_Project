#include <stdio.h>
float wt[100], pt[100];
float pw[100];
int capacity;

void sort(int n)
{
	int i, j;
	float t, t1, t2;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(pw[j]<pw[j+1]){
				t= pw[j];
				t1 = wt[j];
				t2 = pt[j];
				
				pw[j] = pw[j+1];
				wt[j] = wt[j+1];
				pt[j] = pt[j+1];
				
				pw[j+1] = t;
				wt[j+1] = t1;
				pt[j+1] = t2;
			}
		}
	}
}

void knapsack(int capacity, int n)
{
	int i,k=0;
	float mul, profit = 0;
    // Calculating the unit profit values
	for(i = 0; i<n; i++)
	{
		pw[i] = pt[i]/wt[i];
	}

	sort(n); // Sorting the arrays wrt unit profit pw
	
	/*for (i=0;i<n;i++)
	{
		printf("%f  ", pw[i]);
	}
	printf ("\n");
	for (i=0;i<n;i++)
	{
		printf("%f  ", pt[i]);
	}
	printf ("\n");
	for (i=0;i<n;i++)
	{
		printf("%f  ", wt[i]);
	}
	printf ("\n");
	*/

	while(capacity != 0)
	{
		if(capacity >= wt[k])
		{
			capacity = (float)capacity - wt[k];
			profit = profit+pt[k];
			k++;
		}
		else
		{
			mul = capacity/wt[k];
			wt[k] = wt[k]*mul;
			pt[k] = pt[k]*mul;
			capacity = (float)capacity - wt[k];
			profit = profit + pt[k];
			k++;
		}
	}
	printf("The Maximum profit that can be made is: %f", profit);
}


int main()
{
	int n,i;
	printf("Enter the number of weights and profit: ");
	scanf("%d", &n);
	
	printf("Enter the capacity of the knapsack: ");
	scanf("%d", &capacity);
	
	for(i = 0; i< n; i++)
	{
		printf("Weight: ");
		scanf("%f", &wt[i]);
		printf("Profit: ");
		scanf("%f", &pt[i]);
	}
	
	
	knapsack(capacity, n);
}