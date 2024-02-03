/*
Example:

Input : dict = {"ale", "apple", "monkey", "plea"}
        str = "abpcplea"
Output : apple
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[100];

struct node{
    char data[100];
    int length;
    struct node *next;
};
struct node *head = NULL;

struct node* Createnode(char item[]){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    int k=0, count = 0;
    int i = 0;
    while(item[i]!='\0'){
        n->data[i] = item[i];
        i++;
    }
    i = 0;
    while(item[i]!='\0'){
        int j = 0;
        while(str[j]!='\0'){
            if(item[i] == str[j]){
                count++;
                break;
            }
            j++;
        }
        i++;
    }

    n->length = count;
    n->next = NULL;
    return n;
}

void insert(char item[]){
    struct node *n = Createnode(item);
    if(head == NULL){
        head = n;
    }
    else{
        struct node *ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

void display(){
    if(head==NULL){
        printf("No Data in the dictionary.\n");
        return;
    }
    else{
        struct node *ptr = head, *max = head;
        while(ptr!=NULL){
            if(ptr->length > max->length)
            max = ptr;
            ptr = ptr->next;
        }
        if(max->length == 0){
            printf("No such string found in the dictionary.\n");
        }
        else{
            puts(max->data);
            printf("%d\n", max->length);
            return;
        }
    }
}

int main(){
    printf("Enter a string : ");
    scanf("%[^\n]s", str);
    char ins[100];
    int conti = 1;
    do{
        printf("\n\nPress 1 to enter a word in the dictionary\n");
        printf("Press 2 to display the longest matched string\n");
        printf("Press 3 to exit\n");

        int ch;
        printf("Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            printf("Enter a word to be inserted : ");
            scanf("%s", ins);
            insert(ins);
            break;
            
            case 2:
            display();
            break;

            case 3:
            conti = 0;
            break;
        
            default: printf("WRONG CHOICE\n");
        }
        printf("Do you want to continue ? (1/0) : ");
        scanf("%d", &conti);
    }while(conti == 1);

    return 0;
}