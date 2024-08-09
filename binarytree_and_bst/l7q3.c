#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char data;
    struct node *left;
    struct node *right;
};
void displaypreorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%c ", root->data);
        displaypreorder(root->left);
        displaypreorder(root->right);
    }
    else
    {
        return;
    }
    
}
void displayinorder(struct node *root)
{
    if (root != NULL)
    {
        displayinorder(root->left);
        printf("%c ", root->data);
        displayinorder(root->right);
    }
    else
    {
        return;
    }
    
}
void displaypostorder(struct node *root)
{
    if (root != NULL)
    {
        displaypostorder(root->left);
        displaypostorder(root->right);
        printf("%c ",root->data);
    }
    else
    {
        return;
    }
    
}
struct node *createnode(char data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
int main()
{
    struct node *a = createnode('A');
    struct node *b = createnode('B');
    a->left = b;
    struct node *c = createnode('C');
    a->right = c;
    struct node *d = createnode('D');
    b->left = d;
    struct node *e = createnode('E');
    d->right = e;
    struct node *f = createnode('F');
    c->left = f;
    struct node *g = createnode('G');
    f->right = g;
    struct node *h = createnode('H');
    g->right = h;
    struct node *i = createnode('I');
    h->left = i;
    struct node *j = createnode('J');
    i->right = j;
    struct node *k = createnode('K');
    e->right = k;
    struct node *l = createnode('L');
    k->left = l;
    struct node *m = createnode('M');
    l->right = m;
printf("preorder traversal :-\n");
    displaypreorder(a);
    printf("\n");
printf("inorder traversal :-\n");
    displayinorder(a);
    printf("\n");
printf("postorder traversal :-\n");
    displaypostorder(a);
    return 0;
}