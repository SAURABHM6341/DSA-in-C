#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int search(struct node *root, int key)
{
    if (root == NULL)
        return 0;
    if (root->data == key)
    {
        return 1;
    }
    else
    {
        if (root->data > key)
        {
            search(root->left, key);
        }
        else
        {
            search(root->right, key);
        }
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
    for (int i = 0; i < 6; i++)
    {
        root = createnode(root);
    }
    displayinorder(root);
    printf("enter the number you want to search\n");
    int key;
    scanf("%d", &key);
    if (search(root, key))
    {
        printf("Number Present in BST\n");
    }
    else
    {
        printf("Number not Found");
    }
    return 0;
}