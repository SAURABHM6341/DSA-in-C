#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
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
        {
            if (temp->left != NULL)
            {

                temp = temp->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (temp->right != NULL)
            {

                temp = temp->right;
            }
            else
            {
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
struct node *inorderpredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *delete1(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key < root->data)
    {
        root->left = delete1(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete1(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = inorderpredecessor(root);
            root->data = temp->data;
            root->left = delete1(root->left, temp->data);
        }
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
    struct node *root = (struct node *)malloc(sizeof(struct node));
    printf("enter the data of main root\n");
    scanf("%d", &root->data);
    root->left = NULL;
    root->right = NULL;
    for (int i = 0; i < 8; i++)
    {
        root = createnode(root);
    }
    displayinorder(root);
    printf("enter the element you want to delete\n");
    int key;
    scanf("%d", &key);
    delete1(root, key);
    printf("elements are\n");
    displayinorder(root);
    return 0;
}