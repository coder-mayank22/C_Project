#include<stdio.h>
#define MAX 100

int a[MAX], n;

void insert(int pos, int item){
    n+=1;
    if(pos==1){
        for(int i=n;i>0;i--)
        a[i] = a[i-1];
        a[pos-1] = item;
    }
    else if(pos==n){
        a[pos-1] = item;
    }
    else{
        for(int i=n;i>=pos;i--) a[i] = a[i-1];
        a[pos-1] = item;
    }
}

void delete(int pos){
    if(pos==1){
        for(int i=0;i<n-1;i++) a[i] = a[i+1];
    }
    else{
        for(int i=pos-1;i<n-1;i++) a[i] = a[i+1];
    }
    n-=1;
}

void display(){
    printf("Current Array : ");
    for(int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");
}

int main(){
    printf("Enter size of the array : ");
    scanf("%d", &n);
    printf("Enter %d values to the array\n", n);
    for(int i=0;i<n;i++)scanf("%d", &a[i]);
    display();

    int ins, pos, ch, conti=1;
    do{
        printf("\n\nPress 1 to insert an element.\n");
        printf("Press 2 to delete an element.\n");
        printf("Press 3 to display the current array.\n");
        printf("Press 4 to exit.\n");
        printf("\nEnter choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter item to be inserted : ");
                scanf("%d", &ins);
                printf("Enter position where it is to be inserted : ");
                scanf("%d", &pos);
                insert(pos, ins);
                break;
            case 2:
                printf("Enter position from where item is to be deleted : ");
                scanf("%d", &pos);
                delete(pos);
                break;
            case 3:
                display();
                break;
            case 4:
                conti = 0;
                break;
            default: printf("WRONG CHOICE\n");
        }
    }while(conti==1);
}