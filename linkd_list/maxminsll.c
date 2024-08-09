#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *printsll(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element : %d\n", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}
struct node *createsll(struct node *head)
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
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf("enter the data of 1st node\n");
    scanf("%d", &head->data);
    head->next = NULL;
    head = createsll(head);
    head = createsll(head);
    head = createsll(head);
    head = createsll(head);
    printsll(head);
    printf("sorted linked list is :-\n");
    sort(head);
    printsll(head);
    return 0;
}