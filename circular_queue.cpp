#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front=-1,rear=-1;
int arr[MAX];

struct node{
    int data;
    struct node* next;
};

struct node* Createnode(int item){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=item;
    n->next=NULL;
    return n;
}

struct node *F=NULL, *R=NULL;

void insert_queue(int item){
    if(front==0 && rear==MAX-1|| rear==front-1){
        printf("OVERFLOW\n");
        return;
    }
    else{
        if(front==-1 && rear==-1){
            front=0;rear=0;
        }
        else if(front>0 && rear==MAX-1){
            rear=0;
        }
        else{
            rear+=1;
        }
    }
    printf("\nRear = %d\n\n",rear);
    arr[rear]=item;
}

void del_queue(){
    if(front==-1 || (front>rear && !arr[front])){
        printf("UNDERFLOW\n");
        return;
    }
    else{
        arr[front]=0;
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else if(front==MAX-1){
            front=0;
        }
        else
        front+=1;
    }
    printf("\nFront = %d\n\n",front);
}

void traverse(){
    printf("--CURRENT QUEUE--\n");
    int i;
    if(front!=-1 && front<=rear){
        for(i=front;i<=rear;i++)
        printf("%d ",arr[i]);
    }
    else if(front>rear){
        for(i=0;i<MAX;i++)
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    printf("YOU CAN ENTER MAXIMUM OF %d ELEMENTS INTO THE QUEUE\n",MAX);
    int ins;
    int conti=1;
    do{
        printf("Press 1 to insert element to the rear\n");
        printf("Press 2 to delete element from the front\n");
        printf("Press 3 to display current queue\n");
        printf("Press 4 to exit\n");
        int ch;
        printf("Enter choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter element to be inserted : ");
            scanf("%d",&ins);
            insert_queue(ins);
            break;

            case 2:
            del_queue();
            break;

            case 3:
            traverse();
            break;

            case 4:
            conti=0;
            break;

            default:printf("WRONG CHOICE\n");
        }
    }while(conti==1);
}