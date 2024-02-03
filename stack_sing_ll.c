#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct node{
    int data;
    struct node* next;
}*top = NULL;

struct node* Createnode(int item){
    struct node* n =(struct node*)malloc(sizeof(struct node));
    n->data = item;
    n->next = NULL;
    return n;
}

void push(int item){
    struct node *n = Createnode(item);
    if(top==NULL){
        top = n;
    }
    else{
        n->next = top;
        top = n;
    }
}

void pop(){
    if(top==NULL){
        printf("\nUNDERFLOW\n");
        return;
    }
    else{
        struct node *del = top;
        top = top->next;
        free(del);
    }
}

void traverse(){
    struct node *ptr = top;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    printf("**YOU CAN PUSH MAXIMUM OF 5 ELEMENTS INTO THE STACK**");
    int ins, del_ele, conti=1, count = 0;
    do{
        printf("\n\nPress 1 to push an element into the stack.\n");
        printf("Press 2 to pop an element from the stack.\n");
        printf("Press 3 to display the stack elements.\n");
        printf("Press 4 to exit.\n");
        int ch;
        printf("Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if(count==5){
                printf("OVERFLOW\n");
            }
            else{
                printf("Enter element to be pushed : ");
                scanf("%d", &ins);
                push(ins);
                count++;
            }
            break;
        case 2:
            pop();
            count--;
            break;
        case 3:
            if(top==NULL){
                printf("Empty stack. No elements to show.\n");
            }
            else{
                printf("Stack elements are : ");
                traverse();
            }
            break;
        case 4:
            conti = 0;
            break;
        default:
            printf("WRONG CHOICE\n");
        }
        printf("Do you want to continue? (1/0) : ");
        scanf("%d", &conti);
    }while (conti==1);
}