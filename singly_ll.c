#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head = NULL;

struct node* Createnode(int item){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = item;
    n->next = NULL;
    return n;
}

void insert_first(int item){
    struct node *n = Createnode(item);
    if(head==NULL){
        head = n;
    }
    else{
        n->next = head;
        head = n;
    }
}

void insert_last(int item){
    struct node *n = Createnode(item);
    if(head==NULL) insert_first(item);
    else{
        struct node *ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

void insert_before(int item, int ele){
    struct node *n = Createnode(item);
    if(head==NULL){
        printf("Empty list. Item cannot be inserted before.\n");
        return;
    }
    else{
        int flag = 0;
        struct node *ptr = head;
        while(ptr!=NULL){
            if(ptr->data==ele){
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if(flag==0){
            printf("Element is not present in the list. Item cannot be inserted before.\n");
            return;
        }
        else{
            ptr = head;
            while(ptr->next->data!=ele){
                ptr = ptr->next;
            }
            n->next = ptr->next;
            ptr->next = n;
        }
    }
}

void insert_after(int item, int ele){
    struct node *n = Createnode(item);
    if(head==NULL){
        printf("Empty list. Item cannot be inserted after.\n");
        return;
    }
    else{
        int flag = 0;
        struct node *ptr = head;
        while(ptr!=NULL){
            if(ptr->data==ele){
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if(flag==0){
            printf("Element is not present in the list. Item cannot be inserted after.\n");
            return;
        }
        else{
            ptr = head;
            while(ptr->data!=ele){
                ptr = ptr->next;
            }
            n->next = ptr->next;
            ptr->next = n;
        }
    }
}

void del_first(){
    if(head==NULL){
        printf("Empty list. No element deleted.\n");
        return;
    }
    else{
        struct node *del = head;
        head = head->next;
        free(del);
    }
}

void del_last(){
    if(head==NULL) del_first();
    else if(head->next==NULL){
        struct node *del = head;
        head = NULL;
        free(del);
    }
    else{
        struct node *ptr = head, *del;
        while(ptr->next->next!=NULL){
            ptr = ptr->next;
        }
        del = ptr->next;
        ptr->next = NULL;
        free(del);
    }
}

void del_before(int ele){
    if(head==NULL){
        printf("Empty list. Element cannot be deleted before.\n");
        return;
    }
    else if(head->data==ele){
        printf("There is no element that can be deleted before the head element.\n");
        return;
    }
    else if(head->next->data==ele){
        struct node *del = head;
        head = head->next;
        free(del);
    }
    else{
        struct node *ptr = head, *del;
        int flag = 0;
        while(ptr!=NULL){
            if(ptr->data==ele){
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if(flag==0){
            printf("Element is not present in the list. Item cannot be deleted before.\n");
            return;
        }
        else{
            ptr = head;
            while(ptr->next->next->data!=ele){
                ptr = ptr->next;
            }
            del = ptr->next;
            ptr->next = ptr->next->next;
        }
    }
}

void del_after(int ele){
    if(head==NULL){
        printf("Empty list. Item cannot be deleted after.\n");
        return;
    }
    else if(head->next==NULL){
        printf("Single element list. Item cannot be deleted after.\n");
        return;
    }
    else if(head->data==ele && head->next->next==NULL){
        struct node *del = head->next;
        head->next = NULL;
        free(del);
    }
    else{
        struct node *ptr = head, *del;
        int flag = 0;
        while(ptr!=NULL){
            if(ptr->data==ele){
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if(flag==0){
            printf("Element is not present in the list. Item cannot be deleted after.\n");
            return;
        }
        else{
            if(ptr->next==NULL){
                printf("Last element. Item cannot be deleted after.\n");
                return;
            }
            else{
                del = ptr->next;
                ptr->next = ptr->next->next;
                free(del);
            }
        }
    }
}

void traverse(){
    if(head==NULL){
        printf("Empty list. No elements to show.\n");
        return;
    }
    else{
        printf("List elements are : ");
        struct node *ptr = head;
        while(ptr!=NULL){
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main(){
    int ins, ele, conti = 1;
    do{
        printf("\n\nPress 1 to insert element.\n");
        printf("Press 2 to delete element.\n");
        printf("Press 3 to display the elements of the list.\n");
        printf("Press 4 to exit.\n");
        int c1, c2;
        printf("Enter choice : ");
        scanf("%d", &c1);
        switch (c1)
        {
        case 1:
            printf("Enter element to be inserted : ");
            scanf("%d", &ins);
            printf("\nPress 1 to insert at first.\n");
            printf("Press 2 to insert at last.\n");
            printf("Press 3 to insert before an element.\n");
            printf("Press 4 to insert after an element.\n");
            printf("Enter choice : ");
            scanf("%d", &c2);
            switch(c2){
                case 1:
                    insert_first(ins);
                    break;
                case 2:
                    insert_last(ins);
                    break;
                case 3:
                    printf("Enter element before which item should be inserted : ");
                    scanf("%d", &ele);
                    insert_before(ins, ele);
                    break;
                case 4:
                    printf("Enter element after which item should be inserted : ");
                    scanf("%d", &ele);
                    insert_after(ins, ele);
                    break;
                default: printf("WRONG CHOICE\n");
            }
            break;
        
        case 2:
            printf("Press 1 to delete from first.\n");
            printf("Press 2 to delete from last.\n");
            printf("Press 3 to delete before an element.\n");
            printf("Press 4 to delete after an element.\n");
            printf("Enter choice : ");
            scanf("%d", &c2);
            switch(c2){
                case 1:
                    del_first();
                    break;
                case 2:
                    del_last();
                    break;
                case 3:
                    printf("Enter element before which item should be deleted : ");
                    scanf("%d", &ele);
                    del_before(ele);
                    break;
                case 4:
                    printf("Enter element after which item should be deleted : ");
                    scanf("%d", &ele);
                    del_after(ele);
                    break;
                default: printf("WRONG CHOICE\n");
            }
            break;

        case 3:
            traverse();
            break;

        case 4:
            conti = 0;
            break;

        default: printf("WRONG CHOICE\n");
        }
        printf("Do you want to continue? (1/0) : ");
        scanf("%d", &conti);
    }while(conti==1);
}