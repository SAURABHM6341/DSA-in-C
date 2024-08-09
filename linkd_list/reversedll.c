#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *previous;
} node;
node *createdll(node *head, int data)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data= data;
    newnode->previous = temp;
    newnode->next = NULL;
    temp->next = newnode;
    return head;
}
node *printdll(node *temp)
{
    while (temp != NULL)
    {
        printf("element : %d\n", temp->data);
        temp = temp->next;
    }
}
node *reversedll(node *head)
{
    node *temp = head;
    node *temp1 = NULL;
    while (temp->next != NULL)
    {
        temp1 = temp->next;
        temp->next = temp->previous;
        temp->previous = temp1;
        temp = temp->previous;
    }
    if (temp1 != NULL) {
        head = temp1->previous;
    }
    return head;
}
int main()
{
    node *head = (node *)malloc(sizeof(node));
    head->data = 1;
    head->next = NULL;
    head->previous = NULL;
    head = createdll(head,2);
    head = createdll(head,3);
    head = createdll(head,4);
    head = createdll(head,5);
    head = createdll(head,6);
    head = createdll(head,7);
    printf("original linked list is : ");
    printdll(head);
    printf("reverse of the linked list is :-\n");
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("element : %d\n", temp->data);
    head = reversedll(head);
    printdll(head);
        return 0;
}