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
// struct node* insert(struct node *root, int key, struct node *prev)
// {
//     if (root == NULL)
//     {
//         struct node *newnode = (struct node *)malloc(sizeof(struct node));
//         newnode->data = key;
//         newnode->left = NULL;
//         newnode->right = NULL;
//         if (prev->data > key)
//         {
//             prev->left = newnode;
//         }
//         else
//         {
//             prev->right = newnode;
//         }
//         return root;
//     }
//     else
//     {
//         prev = root;
//         if (root->data > key)
//             return insert(root->left, key, prev);
//         if (root->data < key)
//         {
//             return insert(root->right, key, prev);
//         }
//     }
// }
struct node* insert(struct node*root,int key){
    struct node*prev = NULL;
    struct node*temp = root;
    while (root!=NULL)
    {
        prev = root;
        if (key==root->data)
        {
            return temp;
        }
        else if (root->data>key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }  
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = key;
    if (key<prev->data)
    {
        prev->left = newnode;
    }
    else
    {
        prev->right = newnode;
    }   
    return temp;
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
    // for (int i = 0; i < 3; i++)
    // {
        printf("enter the number you want to insert\n");
        int key;
        scanf("%d", &key);
        root = insert(root, key);
    // }
    printf("elements are\n");
    displayinorder(root);
// printf("\n%d\n",root->right->right->left->left->right);

    return 0;
}