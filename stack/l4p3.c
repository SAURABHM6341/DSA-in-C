#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure to represent a stack
typedef struct
{
    int top;
    int data[MAX_SIZE];
} Stack;

// Function prototypes
void push(Stack *stack, int value);
int pop(Stack *stack);
int evaluateExpression(char *expression);
int precedence(char op);
int applyOperator(int a, int b, char op);

int main()
{
    char expression[MAX_SIZE];
    printf("Enter infix expression: ");
    fgets(expression, MAX_SIZE, stdin);
    expression[strcspn(expression, "\n")] = 0; // Removing trailing newline

    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}

// Function to evaluate infix expression
int evaluateExpression(char *expression)
{
    Stack operandStack;
    operandStack.top = -1;

    Stack operatorStack;
    operatorStack.top = -1;

    for (int i = 0; expression[i]; i++)
    {
        if (isdigit(expression[i]))
        {
            int operand = 0;
            while (isdigit(expression[i]))
            {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--; // Move back one position to account for the last digit
            push(&operandStack, operand);
        }
        else if (expression[i] == '(')
        {
            push(&operatorStack, expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (operatorStack.top != -1 && operatorStack.data[operatorStack.top] != '(')
            {
                int b = pop(&operandStack);
                int a = pop(&operandStack);
                char op = pop(&operatorStack);
                int result = applyOperator(a, b, op);
                push(&operandStack, result);
            }
            pop(&operatorStack); // Discard the '('
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            while (operatorStack.top != -1 && precedence(operatorStack.data[operatorStack.top]) >= precedence(expression[i]))
            {
                int b = pop(&operandStack);
                int a = pop(&operandStack);
                char op = pop(&operatorStack);
                int result = applyOperator(a, b, op);
                push(&operandStack, result);
            }
            push(&operatorStack, expression[i]);
        }
    }

    while (operatorStack.top != -1)
    {
        int b = pop(&operandStack);
        int a = pop(&operandStack);
        char op = pop(&operatorStack);
        int result = applyOperator(a, b, op);
        push(&operandStack, result);
    }

    return operandStack.data[operandStack.top];
}

// Function to push an element onto the stack
void push(Stack *stack, int value)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Function to get precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // for '('
}

// Function to apply operator
int applyOperator(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            printf("Division by zero error\n");
            exit(EXIT_FAILURE);
        }
        return a / b;
    }
    return 0;
}
