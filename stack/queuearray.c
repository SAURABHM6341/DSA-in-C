#include <stdio.h>
#include <stdlib.h>
#define max 50
int queue[max];
int front = -1;
int rear = -1;
int isempty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull()
{
    if (rear == max - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue()
{
    if (isfull())
    {
        printf("sorry! more elements cannot be enqueued\n");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front++;
        }
        printf("how many elements you want to push\n");
        int a;
        scanf("%d",&a);
        for (int i = 1; i <= a; i++)
        {
            rear++;
            printf("enter the no. you want to push\n");
            scanf("%d", &queue[rear]);
        }
    }
}
void dequeue()
{
    if (isempty())
    {
        printf("no elements are present in queue\n");
    }
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
}
void display()
{
    while (front != rear + 1)
    {
        printf("element : %d\n", queue[front]);
        front++;
    }
}
int main()
{
    while (1)
    {
    printf("for enqueue type 1\nfor dequeue type 2\nfor displaying type 3\ntype 4 to exit\n");
    int a;
    scanf("%d", &a);

        if (a == 1)
        {
            enqueue();
        }
        else if (a == 2)
        {
            dequeue();
        }
        else if (a == 3)
        {
            display();
        }
        else
        {
            break;
        }
    }

    return 0;
}