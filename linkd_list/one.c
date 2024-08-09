#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node*next;//ye struct node type ka pointer h pointing towards this structure
    
}stra;
void linkedlisttraversal(struct node*ptr){
while (ptr!=NULL)
{
    printf("element : %d\n", ptr->data);
ptr = ptr->next;
}

}

int main()
{    
    //allocating memory for nodes in the linked list in heap we ARE doing dynamic memory allocation 
    struct node *head = (struct node*)malloc(sizeof(struct node));//time complexity of traversal of linked list is O(n)
    struct node *second = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));
//linking 1st and 2nd nodes
    head->data = 7;
    head->next = second;
//linking second and third nodes
    second->data =5; 
    second->next =third; 
//terminating at third
    third->data = 9;
    third->next = NULL;
    //printing the list
    linkedlisttraversal(head);
    return 0;
}