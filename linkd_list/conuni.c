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
struct node *concatenate(struct node *head1, struct node *head2)
{
    struct node *temp = head1;
    struct node *temp2 = head2;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = temp2;
    temp2->previous = temp;
    return head1;
}
struct node *intersect(struct node *head1, struct node *head2)
{
    struct node *head3 = (struct node *)malloc(sizeof(struct node));
    head3->next = NULL;
    head3->previous = NULL;
    head3->data = 0;
    int b = 0;
    struct node *temp3 = head3;
    struct node *temp1 = head1;
    while (temp1 != NULL)
    {
        struct node *temp2 = head2;
        while (temp2 != NULL)
        {
            if (temp1->data == temp2->data)
            {
                int a = temp1->data;
                b++;
                if (b == 1)
                {
                    head3->data = a;
                }
                else
                {
                    while (temp3->next != NULL)
                    {
                        temp3 = temp3->next;
                    }
                    struct node *newnode = (struct node *)malloc(sizeof(struct node));
                    newnode->data = a;
                    newnode->next = NULL;
                    newnode->previous = temp3;
                    temp3->next = newnode;
                }
                break;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }

    return head3;
}
struct node *Union(struct node *head1, struct node *head2)
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    struct node *unio = (struct node *)malloc(sizeof(struct node));
    unio->data = temp2->data;
    unio->next = temp2->next;
    unio->previous = temp2->previous;
    temp2 = temp2->next;
    struct node * temp4 =unio;
    temp4 = temp4->next;
    while (temp2->next != NULL)
    {
        struct node *newnode1 = (struct node *)malloc(sizeof(struct node));
        newnode1->data = temp2->data;
        newnode1->next = temp2->next;
        newnode1->previous = temp4;
        temp2 = temp2->next;
        temp4 = temp4->next;
    }
    temp2 = head2;

    while (temp1 != NULL)
    {
        struct node *temp2 = head2;
        int b = 0;
        while (temp2->next != NULL)
        {
            if (temp1->data == temp2->data)
            {
                b++;
                break;
            }  
            else
            {
                temp2 = temp2->next;
            }
        }
        if (b == 0)
        {
            while (unio->next != NULL)
            {
                unio = unio->next;
            }
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->next = NULL;
            newnode->previous = unio;
            newnode->data = temp1->data;
            unio->next = newnode;
        }

        temp1 = temp1->next;
    }

    return head2;
}
int main()
{
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    struct node *head2 = (struct node *)malloc(sizeof(struct node));
    printf("enter the data of 1st node of 1st linked list\n");
    scanf("%d", &head1->data);
    head1->previous = NULL;
    head1->next = NULL;
    head1 = createdll(head1);
    head1 = createdll(head1);
    head1 = createdll(head1);
    head1 = createdll(head1);
    printf("1st linked list\n");
    printdll(head1);

    printf("enter the data of 1st node of 2nd linked list\n");
    scanf("%d", &head2->data);
    head2->previous = NULL;
    head2->next = NULL;
    head2 = createdll(head2);
    head2 = createdll(head2);
    head2 = createdll(head2);
    head2 = createdll(head2);
    printf("2nd linked list\n");
    printdll(head2);
    int op = 1;
    while (op != 0)
    {
        printf("--> Enter 1 for concatenation\n--> Enter 2 for intersection\n--> Enter 3 for union operation\n--> Enter 0 to Exit\n");
        scanf("%d", &op);
        if (op == 1)
        {
            head1 = concatenate(head1, head2);
            printdll(head1);
        }
        else if (op == 2)
        {
            head1 = intersect(head1, head2);
            printdll(head1);
        }
        else if (op == 3)
        {
            head1 = Union(head1, head2);
            printdll(head1);
        }
        else
        {
            break;
        }
    }

    return 0;
}