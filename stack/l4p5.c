#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack structure
struct Stack
{
    char *items;
    int top;
};

// Function to create a stack
struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->items = (char *)malloc(capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char c)
{
    stack->items[++stack->top] = c;
}

// Function to pop an element from the stack
char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->items[stack->top--];
    }
    return '\0'; // return null character if stack is empty
}

// Function to check if the given expression is properly parenthesized
bool isParenthesized(char *expression)
{
    struct Stack *stack = createStack(100); // Assuming maximum expression length is 100
    for (int i = 0; expression[i] != '\0'; i++)
    {
        char ch = expression[i];
        if (ch == '(')
        {
            push(stack, ch);
        }
        else if (ch == ')')
        {
            if (isEmpty(stack))
            {
                free(stack->items);
                free(stack);
                return false; // Closing parenthesis without a corresponding opening parenthesis
            }
            pop(stack);
        }
    }
    bool result = isEmpty(stack); // If stack is empty, expression is properly parenthesized
    free(stack->items);
    free(stack);
    return result;
}

int main()
{
    char expression[100]; // Assuming maximum expression length is 100
    printf("Enter an expression: ");
    scanf("%s", expression);
    if (isParenthesized(expression))
    {
        printf("The expression is properly parenthesized.\n");
    }
    else
    {
        printf("The expression is not properly parenthesized.\n");
    }
    return 0;
}
