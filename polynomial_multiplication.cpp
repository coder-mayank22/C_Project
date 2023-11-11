#include<stdio.h>
#include<stdlib.h>

struct poly{
	int coeff;
	int expo;
	struct poly *next;
	struct poly *prev;
};

struct poly *head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL;

struct poly* Createnode(int c,int e){
	struct poly *n;
	n=(struct poly *)malloc(sizeof(struct poly));
	n->coeff=c;
	n->expo=e;
	n->next=NULL;
	n->prev=NULL;
	return n;
}
void poly1(int c,int e){
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
		n1->prev=ptr1;
	}
}

void poly2(int c,int e){
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
		n2->prev=ptr2;
	}
}

void insert_last_finalPoly(int c,int e){
	struct poly *ptr,*n3=Createnode(c,e);
	if(head3==NULL){
		head3=n3;
	}
	else{
		ptr=head3;
		while(ptr->next!=NULL){
		    ptr=ptr->next;
	    }
	    ptr->next=n3;
    	n3->prev=ptr;
	}
}

void poly_mul_insert()
{
	struct poly *p1=head1,*p2,*p3=head3;
	int c3,e3;
	while(p1!=NULL){
		p2=head2;
		while(p2!=NULL){
			c3=p1->coeff*p2->coeff;
			e3=p1->expo+p2->expo;
			insert_last_finalPoly(c3,e3);
			p2=p2->next;
		}
		p1=p1->next;
	}
}

void del_extra(struct poly *ptr1,struct poly *ptr2)
{
	struct poly *del;
	ptr1->next=ptr2->next;
	if(ptr2->next!=NULL)(ptr2->next)->prev=ptr1;
	del=ptr2;
	free(del);
}

void mul_poly(){
	struct poly *ptr=head3,*ptr1;
	while(ptr!=NULL){
		ptr1=ptr->next;
		if(ptr1==NULL)
		break;
		
		else{
			while(ptr1!=NULL){
			    if(ptr1->expo==ptr->expo){
				    ptr->coeff=ptr->coeff+ptr1->coeff;
				    del_extra(ptr1->prev,ptr1);
				    ptr1=(ptr1->prev)->next;
			    }
			    else
			    ptr1=ptr1->next;
		    }
		}
		ptr=ptr->next;
	}
}

int main(){
	int i,no1,no2;
	printf("Enter number of nodes in first polynomial :\n");
	scanf("%d",&no1);
	for(i=1;i<=no1;i++)
	{
		int coeff1,expo1;
		printf("Enter coefficient and exponent %d :\n",i);
		scanf("%d%d",&coeff1,&expo1);
		poly1(coeff1,expo1);
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
		poly2(coeff2,expo2);
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
	//Multiplying the polynomials
	poly_mul_insert();
	mul_poly();
	printf("\nFinal Polynomial : ");
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
