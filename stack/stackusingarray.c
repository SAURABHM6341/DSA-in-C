#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    int *arr;
};
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}
int isfull(struct stack *ptr)
{
    if ((ptr->size) - 1 == ptr->top)
        return 1;
    return 0;
}
void peek(struct stack*ptr){
    printf("enter the position of element you want\n");
    int i;
    scanf("%d",&i);
    i= (ptr->top)-i+1;
    printf("requested stack element is %d\n",ptr->arr[i]);
}
struct stack*pop(struct stack*ptr){
    printf("%d is popped out from stack\n",ptr->arr[ptr->top]);
    ptr->top--;
    return ptr;
}
void display(struct stack*ptr){
    int a = ptr->top;
    while (a!=-1)
    {
        printf("element : %d\n",ptr->arr[a]);
        a--;
    }
    
}
struct stack *push(struct stack*ptr,int d){
    (ptr->top)++;
    ptr->arr[ptr->top] = d;
    return ptr;
}
int main()
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 8;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    while (1)
    {
        if (isfull(s))
        {
            printf("stack overflow\n");
            break;
        }
        
        int a;
        printf("enter the data of new element \n");
        scanf("%d",&a);
        s = push(s,a);
    }
    printf("more elements cannot be pushed because stack is full\n");
    display(s);
    peek(s);
    while (1)
    {
        if (isempty(s))
        {
            printf("underflow condition\n");
            break;
        }
        
        s=pop(s);
    }
    return 0;
}