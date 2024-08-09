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
int binarysearch(struct node *head, int search, int length)
{
    int lo, mi, hi;
    struct node *low = head;
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct node *high = temp;
    int t = length/2;
    while ((t) != 0)
    {
        temp = temp->previous;
        t--;
    }
    struct node *mid = temp;
    temp = head;
    int p = 0;
    while (low->data != search || high->data != search || mid->data != search)
    {
        if (mid->data > search)
        {
            high = mid;
            int q = 0;
            while (temp->next != high->next)
            {
                q++;
                temp = temp->next;
            }
            temp = head;
            while (((q + 1) / 2) != 0)
            {
                temp = temp->next;
            }
        }
        else
        {
            low = mid;
            int q = 0;
            temp = low;
            while (temp->next != high->next)
            {
                q++;
                temp = temp->next;
            }
            temp = low;
            while (((q + 1) / 2) != 0)
            {
                temp = temp->next;
            }
        }
        p++;
    }
    if (p > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    int len;
    printf("enter the length of linked list\n");
    scanf("%d", &len);
    printf("enter the data of 1st node\n");
    scanf("%d", &head->data);
    head->previous = NULL;
    head->next = NULL;
    printf("please enter the data in sorted manner\n ");
    for (int i = 1; i <= len - 1; i++)
    {
        head = createdll(head);
    }
    int object;
    printf("enter the number you want to search in DLL\n");
    scanf("%d", &object);
    int epr = binarysearch(head, object, len);
    if (epr == 1)
    {
        printf("element found\n");
    }
    else
    {
        printf("element not found\n");
    }

    return 0;
}