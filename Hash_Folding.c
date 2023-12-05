#include<stdio.h>
#include<math.h>
#define size 10

int arr[size];


void initialize()
{   
    int i;
    for(i = 0; i < size; i++)
        arr[i] = -1;
}

int count_digits(int value){
	int c=0;
	while(value>0){
		c++;
		value/=10;
	}
	return c;
}

int calculate_key(int value){
	int key,no_digits=count_digits(value);
	if(no_digits<=2){
		key=value%size;
	}
	else{
		int copy=value,rev=0;
		while(copy>0){
			int d=copy%10;
			rev=rev*10+d;
			copy/=10;
		}
		int sum=0;
		while(rev>0){
			int d=rev%100;
			int rev_d=0;
			while(d>0){
				rev_d=rev_d*10 + (d%10);
				d/=10;
			}
			sum+=rev_d;
			rev/=100;
		}
		key = sum%10;
	}
	return key;
}

void insert(int value)
{
	int key=calculate_key(value);
    if(arr[key] == -1)
    {   
        arr[key] = value;
    }
    else
    {   
        int i,pos=key;
        for(i=key+1;i<size;i++){
        	if(arr[i]==-1){
        		pos=i;
        		break;
			}
		}
		if(pos!=key)
		arr[pos]=value;
		else
		printf("\nNo free space found. %d cannot be inserted.\n\n",value);
    }
}

void search(int value)
{
    int key = calculate_key(value);
    if(arr[key] == value)
        printf("\nSearch Found at position %d\n",key);
    else
        printf("\nSearch Not Found\n");
}

void display_hash_table()
{
    int i;
    for(i = 0; i < size; i++)
        printf("arr[%d] = %d\n",i,arr[i]);
}

int main()
{
    int ins,val;
    int conti=1;
    
    initialize();//to initialize the hash table elements to -1
    
    do{
    	printf("Press 1 to insert element\n");
    	printf("Press 2 to search for an element\n");
    	printf("Press 3 to display the hash table\n");
    	printf("Press 4 to exit\n");
    	int ch;
    	printf("Enter choice : ");
    	scanf("%d",&ch);
    	switch(ch){
    		case 1:
    			printf("Enter element to be inserted : ");
    			scanf("%d",&ins);
    			insert(ins);
    			break;
    			
    		case 2:
    			printf("Enter element to be searched for : ");
    			scanf("%d",&val);
    			search(val);
    			break;
    			
    		case 3:
    			printf("Hash Table elements are : \n");
    			display_hash_table();
    			break;
    			
    		case 4:
    			conti=0;
    			break;
    			
    		default:printf("WRONG CHOICE\n");
		}
	}while(conti==1);
    return 0;
}