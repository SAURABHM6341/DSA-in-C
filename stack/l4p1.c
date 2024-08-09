#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100 // Maximum size of the stack

// Stack structure
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if stack is full
int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to check if stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow.\n");
        return;
    }
    stack->items[++stack->top] = value;
    printf("%d pushed to stack.\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow.\n");
        return INT_MIN; // Return minimum integer value in case of underflow
    }
    return stack->items[stack->top--];
}

// Function to return the top element of the stack without removing it
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return INT_MIN; // Return minimum integer value in case of empty stack
    }
    return stack->items[stack->top];
}

// Function to display the elements of the stack
void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

// Function to reverse the elements of the stack
void reverse(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    int temp[MAX_SIZE];
    int i = 0;
    while (!isEmpty(stack)) {
        temp[i++] = pop(stack);
    }
    for (int j = 0; j < i; j++) {
        push(stack, temp[j]);
    }
    printf("Stack reversed.\n");
}

// Function to find the maximum element in the stack
int maximum(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return INT_MIN; // Return minimum integer value in case of empty stack
    }
    int max = INT_MIN;
    for (int i = 0; i <= stack->top; i++) {
        if (stack->items[i] > max) {
            max = stack->items[i];
        }
    }
    return max;
}

// Function to find the minimum element in the stack
int minimum(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return INT_MAX; // Return maximum integer value in case of empty stack
    }
    int min = INT_MAX;
    for (int i = 0; i <= stack->top; i++) {
        if (stack->items[i] < min) {
            min = stack->items[i];
        }
    }
    return min;
}

int main() {
    struct Stack stack;
    initialize(&stack);

    // Pushing elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    // Displaying elements of the stack
    display(&stack);

    // Popping an element from the stack
    printf("Popped element: %d\n", pop(&stack));

    // Displaying elements of the stack after pop
    display(&stack);

    // Peeking at the top element of the stack
    printf("Top element of the stack: %d\n", peek(&stack));

    // Reversing the elements of the stack
    reverse(&stack);

    // Displaying elements of the stack after reverse
    display(&stack);

    // Finding the maximum element in the stack
    printf("Maximum element in the stack: %d\n", maximum(&stack));

    // Finding the minimum element in the stack
    printf("Minimum element in the stack: %d\n", minimum(&stack));

    return 0;
}
