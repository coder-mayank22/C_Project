#include<stdio.h>
#include<stdlib.h>
 struct node{
    int data;
    struct node *next;
    struct node *prev;
 };

 struct node* Createnode(int item){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=item;
    n->next=NULL;
    n->prev=NULL;
 }
 
 struct node *head1=NULL, *head2=NULL, *head3=NULL;

 void add_no1(int item){
    struct node *n=Createnode(item);
    struct node *p1=head1;
    if(head1==NULL)
    head1=n;
    else{
        while(p1->next!=NULL){
            p1=p1->next;
        }
        p1->next=n;
        n->prev=p1;
    }
 }

 void add_no2(int item){
    struct node *n=Createnode(item);
    struct node *p2=head2;
    if(head2==NULL)
    head2=n;
    else{
        while(p2->next!=NULL){
            p2=p2->next;
        }
        p2->next=n;
        n->prev=p2;
    }
 }

void add_final(int item){
    struct node *n=Createnode(item), *p3=head3;
    if(head3==NULL){
        head3=n;
    }
    else{
        while(p3->next!=NULL){
            p3=p3->next;
        }
        p3->next=n;
        n->prev=p3;
    }
}

 int rev_num(struct node *head){
    struct node *ptr=head;
    struct node *tail;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    tail=ptr;
    int no=0;
    while(tail!=NULL){
        no=no*10 + tail->data;
        tail=tail->prev;
    }
    return no;
 }

 int main(){
    int i, ins, n1, n2, num1, num2, sum;
    //Inserting elements into list 1
    printf("Enter number of elements in list 1 : ");
    scanf("%d",&n1);
    if(!(n1>=1 && n1<=100)){
        printf("Input out of the given range (1-100).\n");
        exit(0);
    }
    
    for(i=1;i<=n1;i++){
        printf("Enter element %d : ",i);
        scanf("%d",&ins);
        if(ins<=9)
        add_no1(ins);
        else{
            printf("Invalid Input. Value must not exceed 9. \n");
            printf("Please try again...\n");
            i-=1;
        }
    }
    //Inserting elements into list 2
    printf("Enter number of elements in list 2 : ");
    scanf("%d",&n2);
    if(!(n2>=1 && n2<=100)){
        printf("Input out of the given range (1-100).\n");
        exit(0);
    }

    for(i=1;i<=n2;i++){
        printf("Enter element %d : ",i);
        scanf("%d",&ins);
        if(ins<=9)
        add_no2(ins);
        else{
            printf("Invalid Input. Value must not exceed 9. \n");
            printf("Please try again...\n");
            i-=1;
        }
    }
    //Adding the reverse numbers
    num1=rev_num(head1); //For list 1
    num2=rev_num(head2); //For list 2
    sum=num1+num2;

    //Storing the reversed sum in linked list
    while(sum!=0){
        int d=sum%10;
        add_final(d);
        sum/=10;
    }
    //Displaying the list
    struct node *ptr=head3;
    printf("Result : ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");

    return 0;
 }