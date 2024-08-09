#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}
// int push(struct stack*ptr){
//     if (isfull(ptr))
//     {
//         printf("stack is full\n");
//     }
//     else{
//         ptr->top++;
//     }
    
//     return top;
// }

int main()
{
    struct stack *s;
    s->size = 80;
    s->top = -1;
    s = (struct stack*)malloc(s->size * sizeof(struct stack));
    if (isempty(s))
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("stack is not empty");
    }

    return 0;
}