#include <stdio.h>
#include <stdlib.h>
//structure
struct node
{
  int data;
  struct node *next; // ye struct node type ka pointer h pointing towards this structure

} stra;
//printing linked list
void linkedlisttraversal(struct node *ptr)
{
  while (ptr != NULL)
  {
    printf("element : %d\n", ptr->data);
    ptr = ptr->next;
  }
}
//insert at first 
struct node *insertatfirst(struct node *head, int data)
{
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->next = head;
  ptr->data = data;
  return ptr;
}
//insert after a node
struct node *insertafternode(struct node *head, int data, int node)
{
  struct node *newafter = (struct node *)malloc(sizeof(struct node));
  struct node *ptr1 = head;
  int i = 1;
  while(i<=node){
    ptr1 = ptr1->next;
    i++;
  }
   struct node* ptr2 = ptr1;
  int j = 1;
  while (j<=1)
  {
    ptr2 = ptr2->next;
    j++;
  }
  newafter->next = ptr2;
  newafter->data = data;
  ptr1->next = newafter;
  return head;
}
//insert in between nodes
struct node *insertinbetween(struct node *head, int data, int position)
{
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  struct node *p = head;
  int i = 0;
  while (i != (position - 1))
  {
    p = p->next;
    i++;
  }
  struct node *s = p;
  int j = 1;
  while (j <= 1) // ise krne se s pointer p ke next wale me point kr rha ye maine kiya  kyoki mujhe ptr ke next me p ke next ka adress dena tha ye thoda ghuma ke kiya direcy bhi ho skta h just follow the follwing
  {
    s = s->next;
    j++;
  }
  ptr->data = data;
  // ptr->next = s;
  // while loop ki jgh niche wala kaam ho skta h
  ptr->next = p->next;

  p->next = ptr;
}
//insert at end of list
struct node *insertatend(struct node *head, int data)
{
  struct node *t1 = head;
  while (t1->next != NULL)
  {
    t1 = t1->next;
  }
  struct node *endelement = (struct node *)malloc(sizeof(struct node));
  endelement->data = data;
  endelement->next = NULL;
  t1->next = endelement;
  return head;
}

int main()
{
  // allocating memory for nodes in the linked list in heap we ARE doing dynamic memory allocation
  struct node *head = (struct node *)malloc(sizeof(struct node)); // time complexity of traversal of linked list is O(n)
  struct node *second = (struct node *)malloc(sizeof(struct node));
  struct node *third = (struct node *)malloc(sizeof(struct node));
  // linking 1st and 2nd nodes
  head->data = 7;
  head->next = second;
  // linking second and third nodes
  second->data = 5;
  second->next = third;
  // terminating at third
  third->data = 9;
  third->next = NULL;
  // printing the list
  linkedlisttraversal(head);
  printf("\n");
  // insertion at begining
  head = insertatfirst(head, 443);
  linkedlisttraversal(head);
  printf("\n");
  // insert_in_between
  insertinbetween(head, 4589, 2);
  linkedlisttraversal(head);
  printf("\n");
  // insert at end
  head = insertatend(head, 56781);
  linkedlisttraversal(head);
  printf("\n");
  // insert after a node
  head=insertafternode(head, 3412, 4);
  linkedlisttraversal(head);
  printf("\n");
  return 0;
}