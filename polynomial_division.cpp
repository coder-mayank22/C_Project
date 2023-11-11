#include<stdio.h>
#include<stdlib.h>
struct node{
	int coeff;
	int expo;
	struct node *next;
};

struct node *head1=NULL,*head2=NULL,*quo=NULL,*rem=NULL;

struct node *Createnode(int c,int e){
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	n->coeff=c;
	n->expo=e;
	n->next=NULL;
}

void insert_poly1(int c,int e)
{
	struct node *n=Createnode(c,e);
	if(head1==NULL){
		head1=n;
	}
	else{
	    struct node *ptr1;
	    ptr1=head1;
	    while(ptr1->next!=NULL)
	    {
	    	ptr1=ptr1->next;
	    }
	    ptr1->next=n;
	}
}

void insert_poly2(int c,int e)
{
	struct node *n=Createnode(c,e);
	if(head2==NULL){
		head2=n;
	}
	else{
	    struct node *ptr2;
	    ptr2=head2;
	    while(ptr2->next!=NULL)
	    {
	    	ptr2=ptr2->next;
	    }
	    ptr2->next=n;
	}
}

void div_poly(struct node *p1,struct node *p2)//p1->dividend, p2->divisor
{
	struct node *pq,*pr,*interm;//interm stores the intermediate to be subtracted from p1
	struct node *quo_node,*rem_node;
	if(p1->expo<p2->expo){
		printf("Quotient : 0\n");
		printf("Remainder : ");
		while(p1!=NULL)
		{
			if(p1->next!=NULL){
				printf("%dx%d + ",p1->coeff,p1->expo);
			}
			else
			printf("%dx%d\n",p1->coeff,p1->expo);
			p1=p1->next;
		}
		exit(0);
	}
	
}

int main(){
	int n1,n2,i,c,e;
	printf("Enter number of terms in dividend : ");
	scanf("%d",&n1);
	for(i=1;i<=n1;i++){
		printf("Enter coefficient %d : ",i);
		scanf("%d",&c);
		printf("Enter exponent %d : ",i);
		scanf("%d",&e);
		insert_poly1(c,e);
	}
	printf("Enter number of terms in divisor : ");
	scanf("%d",&n2);
	for(i=1;i<=n2;i++){
		printf("Enter coefficient %d : ",i);
		scanf("%d",&c);
		printf("Enter exponent %d : ",i);
		scanf("%d",&e);
		insert_poly2(c,e);
	}
	struct node *p1=head1,*p2=head2;
	div_poly(p1,p2);
}
