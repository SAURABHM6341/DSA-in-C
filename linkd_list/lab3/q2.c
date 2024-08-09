#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *next;
    struct node *previous;
};
struct node *createdll(struct node *head)
{
    struct node *temp = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the data of element \n");
    scanf("%s", &newnode->data);
    newnode->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode->previous = temp;
    temp->next = newnode;
    return head;
}
struct node*printdll(struct node * head){
struct node*temp = head;
while(temp != NULL){
    printf("%c\n",temp->data);
    temp = temp->next;
}
    return 0;
}
struct node* palindrome(struct node* head){
    // printf("saurabh");
    int i =0;
    struct node *tempf = head;
    struct node *templ = tempf;
    while(templ->next != NULL){ 
        templ = templ->next;
        i++;
    }
    int b =i;
    // printf("\n%c\n",templ->data);
    int a =0;
    while (i>(b/2))
    {
            if (templ->data == tempf->data)
            {
                a++;
            }
        tempf= tempf->next;
        templ = templ->previous;
        i--;
        
    }
    if (a>=b/2)
    {
        printf("it is palindrome\n");
    }
    else
    {
        printf("not a palindrome\n");
    }
    
    
    
    return 0;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    int b;
    printf("enter the length of word\n");
    scanf("%d",&b);
    printf("enter the data of element\n");
    scanf("%s", &head->data);
    head->next = NULL;
    head->previous = NULL;
    for (int i = 1; i <= b-1; i++)
    {
        head = createdll(head);
    }
    printf("entered linked list is \n");
    printdll(head);
    palindrome(head);

    return 0;
}