#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createsll(struct node *head)
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data of node");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp->next = newnode;
    if (head->next == NULL)
    {
        head->next = newnode;
    }
    return head;
}
struct node *printsll(struct node *temp1)
{
    while (temp1 != NULL)
    {
        printf("element : %d\n", temp1->data);
        temp1 = temp1->next;
    }
}
struct node *insertatfirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = NULL;
    ptr->data = data;
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    return head;
}
struct node *insertatpos(struct node *head, int f, int pos)
{
    struct node *temp = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = f;
    for (int i = 1; i <= (pos - 2); i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}
struct node *deleteatbeg(struct node *head)
{
    struct node *temp = head;
    struct node *temp1 = head;
    temp = temp->next;
    head = temp;
    free(temp1);
    return head;
}
struct node *deleteatend(struct node *head, int length)
{
    struct node *temp = head;
    struct node *temp1 = head;
    for (int j = 1; j <= length; j++)
    {
        temp1 = temp1->next;
    }
    printf("%d\n",temp1->data);
    temp = temp1->next;
    temp1->next = NULL;
    free(temp);
    return head;
}
struct node *deleteatpos(struct node *head)
{
    int psoi;
    struct node *temp1 = head;
    printf("enter the node position which you want to remove from DLL\n");
    scanf("%d", &psoi);
    int a = psoi;
    while (psoi != 1)
    {
        temp1 = temp1->next;
        psoi--;
    }
    struct node *temp0 = head;
    while (a != 2)
    {
        temp0 = temp0->next;
        a--;
    }
    temp0->next = temp1->next;
    free(temp1);
    return head;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf("enter the length of linked list");
    int a;
    scanf("%d", &a);
    printf("enter the first element");
    scanf("%d", &head->data);
    head->next = NULL;
    struct node *temp1;
    for (int i = 1; i <= a - 1; i++)
    {
        temp1 = createsll(head);
    }
    printsll(head);
    int d;
    for (;;)
    {
        printf("if you want to insert at begining type 1\n if at end type 2\n and if at a specific position type 3\n for exiting the program press 0\n");
        scanf("%d", &d);
        int f;
        if (d == 1)
        {
            printf("enter the data of new node");
            scanf("%d", &f);
            head = insertatfirst(head, f);
            printsll(head);
        }
        else if (d == 2)
        {
            printf("enter the data of new node");
            scanf("%d", &f);
            head = insertatend(head, f);
            printsll(head);
        }
        else if (d == 3)
        {
            int pos;
            printf("enter the position of new inserted node\n");
            scanf("%d", &pos);
            printf("enter the data of new node");
            scanf("%d", &f);
            head = insertatpos(head, f, pos);
            printsll(head);
        }
        else
        {
            break;
        }
        continue;
    }
    head = deleteatbeg(head);
    printf("new node after deleting the first node of list\n");
    printsll(head);
    printf("new node after deleting the ending node of list\n");
    head = deleteatend(head,a);
    printsll(head);
    head = deleteatpos(head);
    printf("new list after deleting the given position's element\n");
    printsll(head);

    return 0;
}