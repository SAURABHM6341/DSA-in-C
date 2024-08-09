#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *previous;
};
struct node *printdll(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element : %d\n", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}
struct node *createdll(struct node *head)
{
    struct node *temp = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data of element \n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode->previous = temp;
    temp->next = newnode;
    return head;
}
struct node *insertdll(struct node *head, int length)
{
    struct node *temp = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    int i = 0;
    printf("enter the data of new node\n");
    scanf("%d", &newnode->data);
    if (head->data > newnode->data)
    {
        i = -1;
    }
    while (temp->next != NULL)
    {
        if (temp->data < newnode->data)
        {
            i++;
            printf("\n%d\n", i);
        }
        temp = temp->next;
    }
    if (i == length-1)
    {
        newnode->next = NULL;
        newnode->previous = temp;
        temp->next = newnode;
    }
    else if (i == -1)
    {
        newnode->previous = NULL;
        newnode->next = head;
        head->previous = newnode;
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            if (newnode->data > temp->data && temp->next->data > newnode->data)
            {
                newnode->previous = temp;
                newnode->next = temp->next;
                temp->next->previous = newnode;
                temp->next = newnode;
                break;
            }

            temp = temp->next;
        }
    }

    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    int a;
    printf("enter the length of linked list\n");
    scanf("%d", &a);
    printf("enter the elements in sorted manner\n");
    printf("enter the data of 1st node\n");
    scanf("%d", &head->data);
    head->previous = NULL;
    head->next = NULL;
    for (int i = 0; i < a - 1; i++)
    {
        head = createdll(head);
    }
    printdll(head);
    head = insertdll(head, a);
    printdll(head);
    return 0;
}