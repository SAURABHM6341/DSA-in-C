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
struct node *sort(struct node *head)
{
    struct node *temp = head;

    int a = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        a++;
    }
    temp = head;
    int b = a - 1;
    for (int i = 1; i <= b; i++)
    {
        struct node *next1 = temp->next;
        for (int j = 1; j <= a - 1; j++)
        {

            if (temp->data > next1->data)
            {
                int r = next1->data;
                next1->data = temp->data;
                temp->data = r;
            }
            next1 = next1->next;
        }
        a--;
        temp = temp->next;
    }
    return head;
}
struct node * deldupli(struct node *head)
{
    struct node *temp = head;
    int i =1;
    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            if (i==1)
            {
                temp->next->previous = NULL;
                head = temp->next;
                free(temp);
                break;
            }
            else
            {
                temp->next->previous = temp->previous;
                temp->previous->next = temp->next;
                free(temp);
                break;
            }
        }
        i++;
        temp= temp->next;
    }
    
    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    int a;
    printf("enter the length of linked list\n");
    scanf("%d", &a);
    printf("enter the data of 1st node\n");
    scanf("%d", &head->data);
    head->previous = NULL;
    head->next = NULL;
    for (int i = 0; i < a - 1; i++)
    {
        head = createdll(head);
    }
    printdll(head);
    printf("sorted linked list is :-\n");
    sort(head);
    printdll(head);
    head = deldupli(head);
    printf("after deleting duplicate element \n");
    printdll(head);
    return 0;
}