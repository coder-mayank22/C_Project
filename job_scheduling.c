#include<stdio.h>

int p[100], jobs, d[100], final_dead[100];

void input(){
	printf("Enter the profits and deadlines\n\n");
	for(int i=0;i<jobs;i++){
		printf("Job %d\n", i+1);
		printf("Profit : ");
		scanf("%d", &p[i]);
		printf("Deadline : ");
		scanf("%d", &d[i]);
	}
	printf("\n");
}

void sort(){
	int i, j, t1, t2;
	for(i=0;i<jobs-1;i++){
		for(j=0;j<jobs-1-i;j++){
			if(p[j]<p[j+1]){
				t1 = p[j];
				t2 = d[j];
				
				p[j] = p[j+1];
				d[j] = d[j+1];
				
				p[j+1] = t1;
				d[j+1] = t2;
			}
		}
	}
}

void jobSelection(){
	sort();
	int i, j;
	printf("Profit Array: ");
	for(i=0;i<jobs;i++){
		printf("%d ", p[i]);
	}
	
	printf("\nDeadlines: ");
	for(i=0;i<jobs;i++)
	printf("%d ", d[i]);
	
	int max = d[0];
	for(i=0;i<jobs;i++)
	if(d[i]>max) max = d[i];
	
	int profit = 0; //Stores the maximum profit
	
	for(i=0;i<max;i++)
	final_dead[i] = 0;
	
	for(i=max;i>=0;i--){
		if(final_dead[i]!=0)
		continue;
		else{
			//Searching for the deadline index in array d
			for(j=0;j<jobs;j++){
				if(d[j]==i){
					final_dead[i] = p[j]; //Store the profits in the final deadline list
					profit += p[j];
					break;
				}
			}
		}
	}
	printf("\nMaximum Profit = %d\n", profit);
	
}

int main(){
	printf("Enter number of jobs: ");
	scanf("%d", &jobs);
	input();
	jobSelection();
	return 0;
}