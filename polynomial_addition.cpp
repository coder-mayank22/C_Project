#include<stdio.h>
#include<stdlib.h>

struct poly{
	int coeff;
	int expo;
	struct poly *next;
};

struct poly *head1=NULL,*head2=NULL,*head3=NULL;

struct poly* Createnode(int c,int e){
	struct poly *n;
	n=(struct poly *)malloc(sizeof(struct poly));
	n->coeff=c;
	n->expo=e;
	n->next=NULL;
	return n;
}
void add_poly1(int c,int e){
	struct poly *n1=Createnode(c,e);
	if(head1==NULL){
		head1=n1;
	}
	else{
		struct poly *ptr1=head1;
		while(ptr1->next!=NULL){
			ptr1=ptr1->next;
		}
		ptr1->next=n1;
	}
}

void add_poly2(int c,int e){
	struct poly *n2=Createnode(c,e);
	if(head2==NULL){
		head2=n2;
	}
	else{
		struct poly *ptr2=head2;
		while(ptr2->next!=NULL){
			ptr2=ptr2->next;
		}
		ptr2->next=n2;
	}
}

void insert_last_finalPoly(int c,int e){
	struct poly *ptr=head3,*n3=Createnode(c,e);
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=n3;
}
void final_poly(){
	struct poly *p1=head1,*p2=head2;
	struct poly *n3;
	int e3,c3;
	if(p1->expo>p2->expo){
		c3=p1->coeff;
		e3=p1->expo;
		p1=p1->next;
	}
	else if(p2->expo>p1->expo){
		c3=p2->coeff;
		e3=p2->expo;
		p2=p2->next;
	}
	else{
		c3=p1->coeff+p2->coeff;
		e3=p1->expo;
		p1=p1->next;
		p2=p2->next;
	}
	n3=Createnode(c3,e3);
	head3=n3;//1st node of resultant polynomial
	while(p1!=NULL && p2!=NULL){
		if(p1->expo>p2->expo){
			c3=p1->coeff;
			e3=p1->expo;
			p1=p1->next;
		}
		else if(p2->expo>p1->expo){
			c3=p2->coeff;
			e3=p2->expo;
			p2=p2->next;
		}
		else{
			c3=p1->coeff+p2->coeff;
			e3=p1->expo;
			p1=p1->next;
			p2=p2->next;
		}
		insert_last_finalPoly(c3,e3);
	}
	while(p1!=NULL){
		c3=p1->coeff;
		e3=p1->expo;
		insert_last_finalPoly(c3,e3);
		p1=p1->next;
	}
	while(p2!=NULL){
		c3=p2->coeff;
		e3=p2->expo;
		insert_last_finalPoly(c3,e3);
		p2=p2->next;
	}
}

int main()
{
	int i,no1,no2;
	printf("Enter number of nodes in first polynomial :\n");
	scanf("%d",&no1);
	for(i=1;i<=no1;i++)
	{
		int coeff1,expo1;
		printf("Enter coefficient and exponent %d :\n",i);
		scanf("%d%d",&coeff1,&expo1);
		add_poly1(coeff1,expo1);
	}
	
	
	
	struct poly *p1=head1;
	printf("1st polynomial: ");
	while(p1!=NULL){
		if(p1->next!=NULL){
			printf("%dX%d + ",p1->coeff,p1->expo);
		}
		else{
			if(p1->expo==0){
				printf("%d\n",p1->coeff);
			}
			else{
				printf("%dX%d\n",p1->coeff,p1->expo);
			}
		}
		p1=p1->next;
	}
	
	printf("Enter number of nodes in second polynomial :\n");
	scanf("%d",&no2);
	for(i=1;i<=no2;i++)
	{
		int coeff2,expo2;
		printf("Enter coefficient and exponent %d :\n",i);
		scanf("%d%d",&coeff2,&expo2);
		add_poly2(coeff2,expo2);
	}
	struct poly *p2=head2;
	printf("2nd polynomial: ");
	while(p2!=NULL){
		if(p2->next!=NULL){
			printf("%dX%d + ",p2->coeff,p2->expo);
		}
		else{
			if(p2->expo==0){
				printf("%d\n",p2->coeff);
			}
			else{
				printf("%dX%d\n",p2->coeff,p2->expo);
			}
		}
		p2=p2->next;
	}
	final_poly();
	printf("Final Polynomial : ");
	struct poly *ptr=head3;
	printf("%dX%d",ptr->coeff,ptr->expo);
	ptr=ptr->next;
	while(ptr!=NULL){
		if(ptr->next!=NULL && ptr->coeff>0){
			printf("+%dX%d",ptr->coeff,ptr->expo);
		}
		else if(ptr->next!=NULL && ptr->coeff<0){
			printf("%dX%d",ptr->coeff,ptr->expo);
		}
		else{
			if(ptr->expo==0){
				if(ptr->coeff>0)
				printf("+%d\n",ptr->coeff);
				else
				printf("%d\n",ptr->coeff);
			}
			else{
				if(ptr->coeff>0)
				printf("+%dx%d\n",ptr->coeff,ptr->expo);
				else
				printf("%dX%d\n",ptr->coeff,ptr->expo);
			}
		}
		ptr=ptr->next;
	}
}
