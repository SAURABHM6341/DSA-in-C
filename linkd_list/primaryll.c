#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createsll(struct node *head, int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    newnode->next = NULL;
    newnode->data = num;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}
void displayll(struct node *head)
{
    struct node *ptr = head;
    int a = 0;
    while (ptr != NULL)
    {
        printf("element : %d\n", ptr->data);
        a++;
        ptr = ptr->next;
    }
    printf("total no. of node ot prime number is %d\n",a);
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    head->data = 2;
    for (int i = 3; i <= 100; i++)
    {
        int a = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                a++;
            }
        }
        if (a == 2)
        {
            head = createsll(head, i);
        }
    }
    displayll(head);

    return 0;
}