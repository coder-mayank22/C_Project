#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *Createnode(int item){
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=item;
	n->left=NULL;
	n->right=NULL;
	return n;
}

struct node *insert(struct node *root, int item){
	struct node *n=Createnode(item);
	if(root==NULL)
	return n;
	else if(item<root->data)
	root->left=insert(root->left,item);
	else if(item>root->data)
	root->right=insert(root->right,item);
	
	return root;
}

void preorder(struct node *root){
	if(root!=NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void postorder(struct node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

struct node* findnode(struct node *node){
	struct node *current=node;
    if(current->left!=NULL){
		current=current->left;
	}
	return current;
}
struct node *prev_root;
void Delete_BST(struct node *root, int val){
	struct node *temp;
	if(root==NULL)
	printf("Val not found\n");
	else if(val<root->data){
        prev_root=root;
		Delete_BST(root->left,val);
	}
	else if(val>root->data){
        prev_root=root;
		Delete_BST(root->right,val);
	}
	else if(root->left && root->right){
		temp=findnode(root->right); //Inorder successor(smallest element in right subtree of root)
		root->data=temp->data;
		struct node *ptr=root->right;
		while((ptr->left)->data != temp->data){
			ptr=ptr->left;
		}
		ptr->left=NULL;
        free(temp);
	}
	else{
		temp=root;
		
		if(root->left==NULL && root->right==NULL)
		root=NULL;
		else if(root->left!=NULL){
            if(prev_root->data < root->data) prev_root->right = root->left;
			else
			prev_root->left = root->left;
        }
		else if(root->right!=NULL){
            if(prev_root->data < root->data) prev_root->right = root->right;
			else
			prev_root->left = root->right;
        }

		free(temp);
	}
}

int main()
{
	int n,i,ins,del_ele;
	struct node *root=NULL;
	int conti;
	do{
		printf("\nPress 1 to insert element");
		printf("\nPress 2 to delete element");
		printf("\nPress 3 for traversing the BST");
		int c1;
		printf("\nEnter choice : ");
		scanf("%d",&c1);
		switch(c1){
			case 1:
				printf("Enter element to be inserted : ");
				scanf("%d",&ins);
				if(root==NULL)
				root=insert(root,ins);
				else
				insert(root,ins);
				break;
			
			case 2:
				printf("Enter element to be deleted : ");
				scanf("%d",&del_ele);
				Delete_BST(root,del_ele);
				break;
				
			case 3:
				printf("\nPress 1 for Preorder Traversal");
				printf("\nPress 2 for Inorder Traversal");
				printf("\nPress 3 for Postorder Traversal");
				int c2;
				printf("\nEnter choice : ");
				scanf("%d",&c2);
				switch(c2){
					case 1:
						printf("\nPreorder Traversal : ");
						preorder(root);
						break;
						
					case 2:
						printf("\nInorder Traversal : ");
						inorder(root);
						break;
						
					case 3:
						printf("\nPostorder Traversal : ");
						postorder(root);
						break;
						
					default:printf("WRONG CHOICE\n");
				}
				break;
				
				default:printf("WRONG CHOICE\n");
		}
		printf("\nDo you want to continue?(1/0) : ");
		scanf("%d",&conti);
	}while(conti==1);
}