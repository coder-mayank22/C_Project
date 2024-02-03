#include <stdio.h>

int ch[100];

void triplet(int n)
{
	int i, j, k, flag =0,wish, sum_2;
	do
	{
		for(i=0;i<=n-2;i++) //For fixing the 1st digit of the triplet
        {
            for(j=i+1;j<n-1;j++) //For fixing the 2nd digit of the triplet
            {
                for(k=j+1;k<n;k++) //For varying the 3rd digit of the triplet
                {
                    if(ch[i] + ch[j] + ch[k] == 0){
                        flag=1;
                        printf("%d %d %d\n", ch[i], ch[j], ch[k]);
                    }
                }
            }
        }

		if (flag == 0)
		{
			printf ("\n No triplets found ");
		}
		printf ("\n Thanks for using this program\n Press 0 to EXIT: \n");
		scanf ("%d", &wish);
	}while (wish != 0);
}

int main()
{
	int i=0, wish;
	
	do 
	{
		printf ("Enter a term :");
		scanf ("%d", &ch[i]);
		++i;
		
		printf ("\nDo you want to continue (1/0)?");
		scanf ("%d", &wish);
	}while (wish != 0);
	//printf ("%d", i);
	
	triplet(i);
}