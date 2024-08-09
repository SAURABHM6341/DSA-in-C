#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int maxinlst(struct node *rootlst,int num)
{
    if (rootlst != NULL)
    {
        if (num<rootlst->data)
        {
            num = rootlst->data;
        }
        maxinlst(rootlst->left,num);
        maxinlst(rootlst->right,num);
    }
    else
    {
        return num;
    }
    
}
int mininrst(struct node *rootrst,int num)
{
    if (rootrst != NULL)
    {
        if (num>rootrst->data)
        {
            num = rootrst->data;
        }
        mininrst(rootrst->left,num);
        mininrst(rootrst->right,num);
    }
    else
    {
        return num;
    }
    
}
void displayinorder(struct node *root)
{
    if (root != NULL)
    {
        displayinorder(root->left);
        printf("%d ", root->data);
        displayinorder(root->right);
    }
    else
    {
        return;
    }
    
}
struct node *createnode(struct node *root)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = root;
    while (temp->left != NULL || temp->right != NULL)
    {
        int n;
        printf("for left type 1\nfor right type 2\n");
        scanf("%d", &n);
        if (n == 1)
        {if (temp->left!=NULL)
        {
        
            temp = temp->left;
        }
        else{
            break;
        }}
        else
        {if (temp->right!=NULL)
        {
        
            temp = temp->right;
        }
        else{
            break;
        }
        }
    }
    int n;
    printf("if you want to insert at left type 1 otherwise 2\n");
    scanf("%d", &n);
    printf("enter the data of new node\n");
    scanf("%d", &newnode->data);
    if (n == 1)
    {
        if (temp != NULL)
        {
            temp->left = newnode;
        }
        else
        {
            printf("NO more NODES\n");
        }
    }
    else
    {
        if (temp != NULL)
        {
            temp->right = newnode;
        }
        else
        {
            printf("NO more NODES\n");
        }
    }
    newnode->left = NULL;
    newnode->right = NULL;
    return root;
}
int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    printf("enter the data of main root\n");
    scanf("%d", &root->data);
    root->left = NULL;
    root->right = NULL;
    for (int i = 0; i < 10; i++)
    {
        root = createnode(root);
    }
    printf("max element in lst is %d\n", maxinlst(root->left, root->left->data));// printf("inorder traversal\n");
    printf("min element in rst is %d\n", mininrst(root->right,root->right->data));
    displayinorder(root);
    return 0;
}