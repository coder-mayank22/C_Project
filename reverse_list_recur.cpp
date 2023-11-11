#include<stdio.h>
#include<stdlib.h>
int no;
struct node{
	int data;
	struct node *next;
};

struct node *top=NULL,*rev=NULL;

void insert_last(int item)
{
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	n->data=item;
	n->next=NULL;
	if(top==NULL){
		top=n;
	}
	else{
		struct node *ptr=top;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=n;
	}
}

void insert_first_rev(int item){
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	n->data=item;
	n->next=rev;
	rev=n;
}

/*void insert_last(int item)
{
	if(head==NULL)insert_first(item);
	else{
		struct node *n;
	    n=(struct node*)malloc(sizeof(struct node));
	    n->data=item;
	    n->next=NULL;
	    struct node *ptr;
	    ptr=head;
	    while(ptr->next!=NULL)
	    {
	    	ptr=ptr->next;
	    }
	    ptr->next=n;
	}
}*/

void recur_rev_list(struct node *ptr){
	if(ptr!=NULL){
		insert_first_rev(ptr->data);
		recur_rev_list(ptr->next);
	}
}

int main(){
	int n,ele;
	printf("Enter number of elements :");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("Enter element %d : ",i);
		scanf("%d",&ele);
		insert_last(ele);
	}
	struct node *ptr=top;
	printf("--Current List--\n");
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
	recur_rev_list(top);
	printf("--Reverse List--\n");
	struct node *rev_ptr=rev;
	while(rev_ptr!=NULL){
		printf("%d ",rev_ptr->data);
		rev_ptr=rev_ptr->next;
	}
	printf("\n");
}

