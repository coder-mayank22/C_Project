#include<stdio.h>
#include<stdlib.h>


struct node
{
    int key;
    struct node *left, *right;
};

struct node* createNode(int key)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key   = key;
    node->left  = node->right  = NULL;
    return (node);
}
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *x)
{
    struct node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

struct node *splay(struct node *root, int key) //Method for splaying
{
    // Base case
    if (root == NULL || root->key == key)
        return root;
 
    // Key lies in left subtree
    if (root->key > key)
    {
        if (root->left == NULL) return root;
 
        // Zig-Zig (Left Left)
        if ((root->left)->key > key)
        {
            // First recursively bring the key as root of left-left
            root->left->left = splay(root->left->left, key);
 
            // Do first rotation for root, second rotation is done after else
            root = rightRotate(root);
        }
        else if ((root->left)->key < key) // Zig-Zag (Left Right)
        {
            // First recursively bring the key as root of left-right
            root->left->right = splay(root->left->right, key);
 
            // Do first rotation for root->left
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
 
        // Do second rotation for root
        return (root->left == NULL)? root: rightRotate(root);
    }
    else // Key lies in right subtree
    {
        // Key is not in tree, we are done
        if (root->right == NULL) return root;
 
        // Zig-Zag (Right Left)
        if ((root->right)->key > key)
        {
            // Bring the key as root of right-left
            root->right->left = splay(root->right->left, key);
 
            // Do first rotation for root->right
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if ((root->right)->key < key)// Zag-Zag (Right Right)
        {
            // Bring the key as root of right-right and do first rotation
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
 
        // Do second rotation for root
        return (root->right == NULL)? root: leftRotate(root);
    }
}

struct node *insert(struct node *root, int k)
{
    // If tree is empty
    if (root == NULL) return createNode(k);
 
    // Bring the closest leaf node to root
    root = splay(root, k);
 
    // If key is already present, then return
    if (root->key == k) return root;
 
    // Otherwise allocate memory for new node
    struct node *newnode  = createNode(k);
 
    // If root's key is greater, make root as right child
    // of newnode and copy the left child of root to newnode
    if (root->key > k)
    {
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    }
 
    // If root's key is smaller, make root as left child
    // of newnode and copy the right child of root to newnode
    else
    {
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }
 
    return newnode; // newnode becomes new root
}

struct node* delete_key(struct node* root, int key) 
{ 
    struct node* temp; 
    if (!root) 
        return NULL; 
  
    // Splay the given key 
    root = splay(root, key); 
  
    // If key is not present, then 
    // return root 
    if (key != root->key) 
        return root; 
  
    // If key is present 
    // If left child of root does not exist 
    // make root->right as root 
    if (!root->left) { 
        temp = root; 
        root = root->right; 
    } 
  
    // Else if left child exits 
    else { 
        temp = root; 
  
        /*Note: Since key == root->key, 
        so after Splay(key, root->lchild), 
        the tree we get will have no right child tree 
        and maximum node in left subtree will get splayed*/
        // New root 
        root = splay(root->left, key); 
  
        // Make right child of previous root as 
        // new root's right child 
        root->right = temp->right; 
    } 
  
    // free the previous root node, that is, 
    // the node containing the key 
    free(temp); 
  
    // return root of the new Splay Tree 
    return root; 
} 

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct node *root = createNode(100);
    root->left = createNode(50);
    root->right = createNode(200);
    root->left->left = createNode(40);
    root->left->left->left = createNode(30);
    root->left->left->left->left = createNode(20);
    printf("Preorder traversal of the original Splay tree: \n");
    preOrder(root);
    printf("\n\n25 is inserted\n");
    root = insert(root, 25);
    printf("Preorder traversal of the modified Splay tree: \n");
    preOrder(root);

    int key;
    printf("\n\nEnter key to be deleted :");
    scanf("%d",&key);
    root = delete_key(root, key);
    printf("Preorder traversal of the Splay tree after deleting %d:\n", key);
    preOrder(root);
    return 0;
}