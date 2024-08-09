#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack structure
struct Stack
{
    int *items;
    int top;
};

// Function to create a stack
struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->items = (int *)malloc(capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value)
{
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->items[stack->top--];
    }
    return -1; // return -1 if stack is empty
}

// Function to evaluate postfix expression
int evaluatePostfix(char *expression)
{
    struct Stack *stack = createStack(100); // Assuming maximum expression length is 100
    for (int i = 0; expression[i] != '\0'; i++)
    {
        char ch = expression[i];
        if (isdigit(ch))
        {
            push(stack, ch - '0'); // Convert character to integer and push onto stack
        }
        else
        {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            switch (ch)
            {
            case '+':
                push(stack, operand1 + operand2);
                break;
            case '-':
                push(stack, operand1 - operand2);
                break;
            case '*':
                push(stack, operand1 * operand2);
                break;
            case '/':
                push(stack, operand1 / operand2);
                break;
            }
        }
    }
    int result = pop(stack);
    free(stack->items);
    free(stack);
    return result;
}

int main()
{
    char expression[100]; // Assuming maximum expression length is 100
    printf("Enter a postfix expression: ");
    scanf("%s", expression);
    int result = evaluatePostfix(expression);
    printf("Result of evaluation: %d\n", result);
    return 0;
}
