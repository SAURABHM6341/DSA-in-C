#include <stdio.h>
#include <stdlib.h>
#define max 10
int stack[max];
int top = -1;
void push()
{
    if (top == max - 1)
    {
        printf("stack overflow\n");
    }
    else
    {
        printf("enter the no. of element you want to push\n");
        int a;
        scanf("%d", &a);
        for (int i = 1; i <= a; i++)
        {
            printf("enter the element you want to push\n");
            int x;
            scanf("%d", &x);
            top++;
            stack[top] = x;
        }
    }
}
void pop()
{
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("popped element is %d\n", stack[top]);
        top--;
    }
}
void display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("element %d : %d\n", i, stack[i]);
    }
}
void peek()
{
    printf("which number's element you want to know\n");
    int f;
    scanf("%d", &f);
    printf("number is %d\n", stack[top + 1 - f]);
}
int main()
{
    while (1)
    {
        printf("type 1 for push operation\n");
        printf("type 2 for pop operation\n");
        printf("type 3 for peek operation\n");
        printf("type 4 to display all element of stack\n");
        printf("type 5 to quit\n");
        int x;
        scanf("%d", &x);
        if (x == 1)
        {
            push();
        }
        else if (x == 2)
        {
            pop();
        }
        else if (x == 3)
        {
            peek();
        }
        else if (x == 4)
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