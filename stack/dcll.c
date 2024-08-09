#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *previous;
};
struct node *insertcll(struct node *head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data of newnode\n");
    scanf("%d", &newnode->data);
    newnode->next = head;
    struct node *temp = head;
    temp = temp->next;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newnode->previous = temp;
    temp->next = newnode;
    head->previous = newnode;
    return head;
}
struct node *deletecll(struct node *head)
{
    struct node *temp = head;
    struct node *temp1 = head;
    temp = temp->next;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = head->next;
    head->previous = temp;
    temp->next = head;
    free(temp1);
    return head;
}
struct node *reverse(struct node *head)
{
    struct node *current = head->next;

    // struct node *nex = current->next;
    // struct node*tt = head;
    while (current != head)
    {
        struct node *temp = current->next;
        current->next = current->previous;
        current->previous = temp;
        current = temp;
    }
    struct node *temp = current->next;
    current->next = current->previous;
    current->previous = temp;
    head = head->next;
    return head;
}
void display(struct node *head)
{
    struct node *temp = head;
    do
    {
        printf("element : %d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    printf("how many nodes you want  to make?\n");
    int a;
    scanf("%d", &a);
    printf("enter the data of newnode\n");
    scanf("%d", &head->data);
    head->next = head;
    head->previous = head;
    for (int i = 1; i <= a - 1; i++)
    {
        head = insertcll(head);
    }
    // printf("%d\n",head->next->next->data);
    display(head);
    printf("after deleting 1st node new cll is \n");
    head = deletecll(head);
    display(head);
    head = reverse(head);
    printf("after reversing the cll\n");
    display(head);
    return 0;
}