#include <stdio.h>
#include <stdlib.h>
#define size 8;
int queue[8];
int f = -1;
int r  = -1;
void enqueue(int x){
    if (f==-1&&r==-1)
    {
        f++;
        r++;
        queue[r] = x;
        
        printf("%d is now in queue\n",queue[r]);
    }
    else if(r==7){
printf("queue is full more element cannot be pushed\n");
    }
    else
    {
        r++;
        queue[r] = x;
        // printf("%d\n",r);
        printf("%d is now in queue\n",queue[r]);
        
    }
    return;
}
void dequeue(){
    if (f==-1&&r==-1)
    {
        printf("stack is empty, operation cancelled\n");
    }
    else if (r==f)
    {
        printf("last element of queue is %d\n",queue[f]);
        // printf("%d",f);
        r=-1;
        f=-1;
    }
    else
    {
        printf("%d has been removed from queue\n",queue[f]);
        // printf("%d",f);
        // printf("%d",r);
        f++;

    }
    return;
}
int main(){
int d = 13;
    dequeue();
    for (int  i = 0; i <= (8-1); i++)
    {
        enqueue(d);
        d+=8;
    }
    enqueue(d+15);
    for (int  j = 0;   j < 8; j++)
  {
        dequeue();
    }
    
}