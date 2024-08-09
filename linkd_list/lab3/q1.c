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
}
struct node *inseratbeg(struct node *head)
{
    struct node *temp = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data of the new element that is being inserted at begining\n");
    scanf("\n%d", &newnode->data);
    newnode->next = temp;
    newnode->previous = NULL;
    temp->previous = newnode;
    head = newnode;
    return head;
}
struct node *insertatend(struct node *head)
{
    struct node *newnode1 = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Enter the data of the new element that is being inserted at end of list :\n");
    scanf("%d", &newnode1->data);
    newnode1->next = NULL;
    newnode1->previous = temp;
    temp->next = newnode1;
    return head;
}
struct node *insertatpos(struct node *head)
{
    struct node *temp = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    int pos, i = 1;
    printf("enter the node position where you want to insert the new node\n");
    scanf("%d", &pos);
    printf("enter the data of the new node\n");
    scanf("%d", &newnode->data);
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    i = 1;
    struct node *temp1 = head;
    while (i < pos)
    {
        temp1 = temp1->next;
        i++;
    }
    newnode->previous = temp;
    newnode->next = temp1;
    temp->next = newnode;
    temp1->previous = newnode;

    return head;
}
struct node *deleteatbeg(struct node *head)
{
    struct node *temp = head;
    temp = temp->next;
    head->data = temp->data;
    head->next = temp->next;
    head->previous = NULL;
    free(temp);
    return head;
}
struct node *deleteatend(struct node *head)
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct node *temp1 = temp;
    temp1 = temp1->previous;
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
    int a= psoi;
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
    temp1->next->previous = temp0;
    temp0->next = temp1->next;
    free(temp1);
    return head;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf("enter the data of 1st node\n");
    scanf("%d", &head->data);
    head->previous = NULL;
    head->next = NULL;
    createdll(head);
    printdll(head);
    head = inseratbeg(head);
    printdll(head);
    head = insertatend(head);
    printdll(head);
    head = insertatpos(head);
    printdll(head);
    head = deleteatbeg(head);
    printf("new node after deleting the first node of list\n");
    printdll(head);
    printf("new node after deleting the ending node of list\n");
    head = deleteatend(head);
    printdll(head);
    head = deleteatpos(head);
    printf("new list after deleting the given position's element\n");
    printdll(head);
    return 0;
}