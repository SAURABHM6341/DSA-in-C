#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
int max(int data1,int data2){
    if (data1>data2)
    {
        return data1;
    }
    return data2;
    
}

int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}
int getbalancefactor(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return height(root->left) - height(root->right);
}
struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(height(y->left), height(y->right));
    x->height = max(height(x->left), height(x->right));
    return x;
}
struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;
    y->left = x;
    x->right = t2;
    y->height = max(height(y->left), height(y->right));
    x->height = max(height(x->left), height(x->right));
    return y;
}
struct node *insert(struct node *root, int key)
{
    if (root == NULL)
    {
        return createnode(key);
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    // return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int bf = getbalancefactor(root);
    // left left case
    if (bf > 1 && key < root->left->data)
    {
        return rightrotate(root);
    }

    // right right case
    if (bf < -1 && key > root->right->data)
    {
        return leftrotate(root);
    }
    // left right case
    if (bf > 1 && key > root->left->data)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    // right left case
    if (bf < -1 && key < root->right->data)
    {
        root->right = rightrotate(root->right);

        return leftrotate(root);
    }
    return root;
}
void displayinorder(struct node *root)
{
    if (root != NULL)
    {
        displayinorder(root->left);
        printf("%d\n", root->data);
        displayinorder(root->right);
    }
    else
    {
        return;
    }
    
}
int main()
{
struct node*root = createnode(100);
root = insert(root,50);
root = insert(root,20);
root = insert(root,70);
root = insert(root,90);
root = insert(root,25);
root = insert(root,10);
root = insert(root,30);
root = insert(root,5);
root = insert(root,40);
root = insert(root,200);
displayinorder(root);
    return 0;
}