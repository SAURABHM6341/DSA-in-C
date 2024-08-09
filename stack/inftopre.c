#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
int b = 0;
char stack[max];
char infix[max];
char postfix[max];
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
void push(char x)
{
    if (isfull())
    {
        printf("enter shorter expression please\n");
    }
    else
    {
        top++;
        stack[top] = x;
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
        postfix[b] = stack[top];
        b++;
        top--;
    }
}
int precedence(char symbol)
{
    if (symbol == '^')
    {
        return 3;
    }
    else if (symbol == '*' || symbol == '/')
    {
        return 2;
    }
    else if (symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void post()
{
    int i = 0;
    while (infix[i] != '\0')
    {

        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            if (precedence(infix[i]) > precedence(stack[top]) || top == -1)
            {
                push(infix[i]);
            }
            else
            {
                while (precedence(infix[i]) < precedence(stack[top]))
                {
                    pop();
                }
                if (precedence(infix[i]) == precedence(stack[top]) && infix[i] == '^')
                {
                    while (precedence(infix[i]) <= precedence(stack[top]))
                    {
                        pop();
                    }
                    push(infix[i]);
                }
                else if (precedence(infix[i]) > precedence(stack[top]) || top == -1)
                {
                    push(infix[i]);
                }
                else
                {
                    push(infix[i]);
                }
            }
        }
        else if (infix[i] == '(')
        {
            while (stack[top] != ')')
            {
                pop();
            }
            top--;
        }
        else if (infix[i] == ')')
        {
            push(infix[i]);
        }
        else
        {
            postfix[b] = infix[i];
            b++;
        }
        i++;
    }
    while (top != -1)
    {
        pop();
    }
    int k = strlen(postfix) - 1;
    while (k != -1)
    {
        printf("%c", postfix[k]);
        k--;
    }
}
int main()
{
    printf("enter the expression\n");
    char str[max];
    scanf("%s", &str);
    int j = strlen(str) - 1;
    int i = 0;
    while (j != -1)
    {
        infix[i] = str[j];
        i++;
        j--;
    }
    post();
    return 0;
}