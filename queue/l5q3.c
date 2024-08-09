#include <stdio.h>
#include <stdlib.h>
 struct node{
    int data;
    struct node* next;
};
struct node* enqueue(struct node * rear, struct node*front){
struct node* newnode = (struct node*)malloc(sizeof(struct node));
printf("enter the data of newnode\n");
scanf("%d",&newnode->data);
newnode->next = NULL;
rear->next = newnode;
rear = rear->next;
// printf("%d",front->data);
return rear;
}
struct node* dequeue(struct node*front){
    struct node*temp = front;
    front = front->next;
    free(temp);

    return front;
}
void maximum(struct node*front){
   struct  node*temp = front;
    int max = temp->data;
       while (temp!=NULL)
       {
     if (max < temp->data)
        {
            max = temp->data;
            // printf("%d\n",max);
          
        }
        // printf("%d,%d\n",max,temp->data);
          temp = temp->next;
       }
       
        printf("max element : %d\n",max);
    return;
}
void minimum(struct node*front){
    struct node*temp = front;
    int min = temp->data;
    while (temp!=NULL)
    {
        if (min>temp->data)
        {
            min = temp->data;
             
        }
        temp = temp->next;
    }
        printf("minimum element : %d\n",min);
    return;
}
void display(struct node*front){
    struct node* temp = front;
    printf("queue has following data:-\n");
    while(temp!=NULL)
    {
        printf("element : %d\n",temp->data);
        temp = temp->next;
    }
    // printf("%d\n",f);
    
    return;
}
int main(){
struct node*head = (struct node*)malloc(sizeof(struct node));
printf("enter the data of element");
scanf("%d",&head->data);
head->next  = NULL;
struct node*rear = head;
struct node*front = head;
for (int i = 0; i < 5; i++)
{
rear = enqueue(rear, front);
}
display(front);
maximum(front);
minimum(front);
for (int i = 0; i < 5; i++)
{
    front = dequeue(front);
}

    return 0;
}