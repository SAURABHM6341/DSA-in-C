#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
char pre[max];
char inf[max];
//this code is not running perfectly;
//this code is not running perfectly;
//this code is not running perfectly;
//this code is not running perfectly;
//this code is not running perfectly;
//this code is not running perfectly;
char stack[max];
int top = -1;
int isfull()
{
    if (top == max - 1)
    {
        return 1;
    }
    return 0;
}
int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
void push(char c)
{
    if (isfull())
    {
        printf("stack is full enter the shorter expression\n");
    }
    else
    {
        top++;
        stack[top] = c;
    }
}
void pop()
{
    if (isempty())
    {
        printf("please enter some expression\n");
    }
    else
    {
        top--;
    }
}
void infix()
{
    int a;
    int f = 1;
    for (int i = strlen(pre) - 1; i >= 0; i--)
    {
        switch (pre[i])
        {
        case '+':
            a = ((int)stack[top] - 48) + ((int)stack[top - 1] - 48);
            pop();
            pop();
            push(a);
            break;
        case '-':
            a = ((int)stack[top] - 48) - ((int)stack[top - 1] - 48);
            pop();
            pop();
            push(a);
            break;
        case '*':
            a = ((int)stack[top] - 48) * ((int)stack[top - 1] - 48);
            pop();
            pop();
            push(a);
            break;
        case '/':
            a = ((int)stack[top] - 48) / ((int)stack[top - 1] - 48);
            pop();
            pop();
            push(a);
            break;
        case '^':
        if (((int)stack[top - 1] - 48)>0)
        {
            /* code */
        
            for (int i = 1; i <= ((int)stack[top - 1] - 48); i++)
            {
                f = ((int)stack[top] - 48) * f;
            }
        }
        else{
            f=1;
        }
            a=f;
            pop();
            pop();
            push(a);
            break;

        default:
            push(pre[i]);
            break;
        }
    }
    while (top != -1)
    {
        printf("answer is : %d\n", stack[top]);
        top--;
    }
}
int main()
{
    printf("enter the epression\n");
    scanf("%s", &pre);
    // printf("%d", 2 ^ 2);
    infix();
    return 0;
}
// -+5/*4^3064