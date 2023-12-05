#include<stdio.h>

#define size 10

int arr[size];


void initialize()
{   
    int i;
    for(i = 0; i < size; i++)
        arr[i] = -1;
}

void insert(int value)
{   
    int key = value % size;
    
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
		printf("No free space found. %d cannot be inserted.\n\n",value);
    }
}

void search(int value)
{
    int key = value % size;
    if(arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
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