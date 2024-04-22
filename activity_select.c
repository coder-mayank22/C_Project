#include <stdio.h>
int start[100], end[100], acti[100];

void sort (int act) //Sorting the activities wrt finish time
{
	int temp, i, j, temp2;
	for (i= act-1;i>=1; i--)
	{
		for (j=1;j<=i;j++)
		{
			if (end[j-1]>end[j])
			{
				temp = end[j];
				end[j]= end[j-1];
				end[j-1] = temp;
				
				temp2 = start[j];
				start[j] = start[j-1];
				start[j-1] = temp2;
			}
		}
	}
}


void activity_sel (int act)
{
	int i,j;
	acti[0] = 0;
	j = 0;
	for (i=1;i<act;i++)
	{
		if (start[i]>=end[j])
		{
			acti[i] = i;
			j=i;
		}
	}
	
	printf ("Activity set: ");
	for (i = 0; i<act; i++)
		printf ("%d  ", acti[i]);
	printf ("\n");
}


int main ()
{
	int i, act, wish;
	do
	{
		printf ("Enter the number of Activities to be done: ");
		scanf ("%d", &act);
		
		printf ("Enter the start and end time of the activities: \n");
		for (i =0;i<act;i++)
		{
			printf ("%d-->", i+1);
			printf ("Start Time: ");
			scanf ("%d", &start[i]);
			printf ("\tEnd Time: ");
			scanf ("%d", &end[i]);
		}
			
		for(i=0;i<act;i++)
		acti[i] = -1; // Setting all values of the acti array to -1

		sort (act);
		
		printf ("Start set: ");
		for (i = 0; i<act; i++)
			printf ("%d  ", start[i]);
		printf ("\n");
		printf ("End   set: ");
		for (i = 0; i<act; i++)
			printf ("%d  ", end[i]);
		printf ("\n");
		
		activity_sel (act);
		
		printf ("Do you want to continue? (1/0): ");
		scanf ("%d", &wish);
	}while (wish!=0);
}