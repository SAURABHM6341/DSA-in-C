#include <stdio.h>
#include <stdlib.h>
#define size 7
int queue[size];
int f = -1;
int r = -1;
int isempty()
{
    if (f == -1 && r == -1)
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
    if (r == size - 1)
    {
        return 1;
    }
    return 0;
}
void enqueue(int x)
{
    if (f == -1 && r == -1)
    {
        f++;
        r++;
        queue[r] = x;
    }
    else if (isfull())
    {
        printf("queue is full more element cannot be pushed\n");
    }
    else
    {
        r++;
        queue[r] = x;
    }
}
int dequeue()
{
    int last = queue[f];
    if (f == -1 && r == -1)
    {
        printf("stack is empty, operation cancelled\n");
        return -1;
    }
    else if (r == f)
    {
        r = -1;
        f = -1;
        return last;
    }
    else
    {
        f++;
        return last;
    }
}
int main()
{
    int i = 6;
    int u;
    int visited[] = {0, 0, 0, 0, 0, 0, 0};
    int graph[7][7] = {
        {0, 1, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0}};
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i); // enqueue i for exploration
    while (!isempty())
    {
        u = dequeue();
        for (int j = 0; j < 7; j++)
        {
            if (graph[u][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}