#include<stdio.h>
struct Employee
{
	int emp_id;
	char name[20];
	float age;
	char dept[20];
}s[60];
int main()
{
	int i,n;
	printf("Enter number of employees :\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter ID of employee %d\n",i+1);
		scanf("%d",&s[i].emp_id);
		printf("Enter name of employee %d\n",i+1);
		scanf("%s",&s[i].name);
		printf("Enter age of employee %d\n",i+1);
		scanf("%f",&s[i].age);
		printf("Enter department of employee %d\n",i+1);
		scanf("%s",&s[i].dept);
		
	}//end of loop
	int flag=0;
	
	for(i=0;i<n;i++)
	{
		if(s[i].age==58)
		{
			printf("Employee who will retire after 2 years : %s\n",&s[i].name);
			printf("Department : %s\n",&s[i].dept);
			flag=1;
		}
		if(flag!=0)break;
    }
    if(flag==0)printf("No employee will retire after 2 years\n");
	return 0;
}//end of employee

