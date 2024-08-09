#include <stdio.h>
#include <stdlib.h>
#define max 5
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
    if (front == (rear + 1) % max)
    {
        return 1;
    }
    return 0;
}
void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
   else if (isfull())
    {
        printf("queue is full more element cannot be enqueued\n");
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = x;
    }
}
void display(){
    if (isempty())
    {
        printf("queue is empty\n");
    }
    else
    {
        while (front!=rear)
        {
            printf("element : %d\n",queue[front]);
            front = (front+1)%max;
        }
         printf("element : %d\n",queue[front]);
    }
    
    
}
void dequeue(){
if (isempty())
{
    printf("queue is empty\n");
}
if (front==rear)
{
    front =-1;
    rear =-1;
}

else
{
    // printf("%d\n",queue[front]);
    front = (front+1)%max;
}


}
int main()
{
    enqueue(5);
    enqueue(4);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(7);
    dequeue();
    dequeue();
    display();
    return 0;
}