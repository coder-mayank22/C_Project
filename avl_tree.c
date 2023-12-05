#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

//To get height of the tree
int height(struct node *n){
    if(n==NULL)
    return 0;
    return n->height;
}

//To get the larger of two numbers
int max(int a, int b){
    return (a>b)?a:b;
}

struct node* Createnode(int key){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->key=key;
    n->left=NULL;
    n->right=NULL;
    n->height=1; //New node is initially added at leaf

    return n;
}

//To right rotate subtree, rooted with y
struct node *rightRotate(struct node *y) 
{ 
    struct node *x = y->left; 
    struct node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), 
                    height(y->right)) + 1; 
    x->height = max(height(x->left), 
                    height(x->right)) + 1; 
  
    // Return new root 
    return x; 
} 

//To left rotate subtree, rooted with x
struct node *leftRotate(struct node *x) 
{ 
    struct node *y = x->right; 
    struct node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left),    
                    height(x->right)) + 1; 
    y->height = max(height(y->left), 
                    height(y->right)) + 1; 
  
    // Return new root 
    return y; 
} 

//Get Balance Factor of node n
int getBalance(struct node *n) 
{ 
    if (n == NULL) 
        return 0; 
    return height(n->left) - height(n->right); 
} 

/*Recursive function to insert a key in the subtree rooted
with node and returns the new node of the subtree*/
struct node* insert(struct node* node, int key) 
{ 
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return Createnode(key);
  
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    else // Equal keys are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), 
                        height(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    int ins, conti=1;
    struct node *root=NULL;
    do{
        printf("\n\nPress 1 to enter an element\n");
        printf("Press 2 for Preorder Traversal the AVL Tree\n");
        printf("Press 3 to exit\n");
        int ch;
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\nEnter element to be inserted : ");
            scanf("%d",&ins);
            root=insert(root, ins);
            break;

            case 2:
            printf("\nPreoder Traversal is : ");
            preorder(root);
            break;

            case 3:
            conti=0;
            break;

            default:printf("WRONG CHOICE\n");
        }
    }while(conti==1);
}
  