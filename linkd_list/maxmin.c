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
    // printf("%d",a);
    temp=head; 
    int b =a-1;
    
    // printf("%d",temp->data);
    for (int i = 1; i <= b; i++)
    {
        struct node *next1 = temp->next;
        // printf("%d\n",temp->data);
        for (int j = 1; j <=a-1; j++)
        {
            
        if (temp->data > next1->data)
        {
            int r = next1->data;
            next1->data = temp->data;
            temp->data = r;
        }
        // printf("%d\n",next1->data);
        // if (j!=a-1)
        // {
        next1 = next1->next;
        // }
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
    head->previous = NULL;
    head->next = NULL;
    head = createdll(head);
    head = createdll(head);
    head = createdll(head);
    head = createdll(head);
    printdll(head);
    printf("sorted linked list is :-\n");
    sort(head);
    printdll(head);
    struct node* temp1= head;
    while (temp1->next !=NULL)
    {
        temp1 = temp1->next;
    }
    printf("Max element is : %d\n",head->data);
    printf("Min element is : %d\n",temp1->data);
    return 0;
}