#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1,max;

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
    if(rear==max-1){
        printf("OVERFLOW\n");
        return;
    }
    else{
        if(front==-1 && rear==-1){
            front=0;rear=0;
        }
        else{
            rear+=1;
        }
    }
    struct node *n=Createnode(item);
    if(F==NULL && R==NULL){
        R=n;
        F=n;
    }
    else{
        struct node *ptr=R;
        while(ptr->next!=NULL)ptr=ptr->next;
        ptr->next=n;
    }
}

void del_queue(){
    if(front==-1 || front>rear){
        printf("UNDERFLOW\n");
        return;
    }
    else{
        struct node *del;
        if(F->next==NULL){
            del=F;
            F=NULL;
            R=NULL;
            free(del);
        }
        else{
            del=F;
            F=R->next;
            R=R->next;
            free(del);
        }
        front+=1;
    }
}

void traverse(){
    printf("--CURRENT LIST--\n");
    struct node *ptr=F;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main(){
    int ins;
    printf("Enter maximum number of elements : ");
    scanf("%d",&max);
    int conti=1;
    do{
        printf("Press 1 to insert element to the rear\n");
        printf("Press 2 to delete element from the front\n");
        printf("Press 3 to display current list\n");
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