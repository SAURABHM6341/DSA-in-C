#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int data;
    struct queue *next;
};
struct queue *enqueue(struct queue *rear)
{
    struct queue *newnode = (struct queue *)malloc(sizeof(struct queue));
    newnode->next = NULL;
    printf("enter the data of new element \n");
    scanf("%d",&newnode->data);
    rear->next = newnode;
    rear = newnode;

    return rear;
}
struct queue* display(struct queue*front){
    struct queue*ptr = front;
    while (ptr!=NULL)
    {
        printf("element : %d\n",ptr->data);
        ptr = ptr->next;
    }
    return front;
}
struct queue *dequeue(struct queue *front)
{
struct queue*temp = front;
front = front->next;
free(temp);
    return front;
}

int main()
{
    struct queue *front = (struct queue *)malloc(sizeof(struct queue));
    front->next = NULL;
    struct queue *rear = front;
    while (1)
    {
        printf("for enqueue type 1\nfor dequeue type 2\nfor displaying type 3\ntype 4 to exit\n");
        int a;
        scanf("%d", &a);

        if (a == 1)
        {
            int b;
            printf("how many element you want to enqueue\n");
            scanf("%d",&b);
            if (front->next == NULL)
            {
                printf("enter the data of newcomer\n");
                scanf("%d", &front->data);

            }
            for (int  i = 1; i <=b-1; i++)
            {            
               rear =  enqueue(rear);
            }
        }
        else if (a == 2)
        {
           front = dequeue(front);
        }
        else if (a == 3)
        {
           front = display(front);
        }
        else
        {
            break;
        }
    }

    return 0;
}