#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct Stack {
    struct Node* top;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
    printf("%d pushed to stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

// Function to return the top element of the stack without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->top->data;
}

// Function to display the elements of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* current = stack->top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to reverse the elements of the stack
void reverse(struct Stack* stack) {
    struct Node *prev = NULL, *current = stack->top, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    stack->top = prev;
    printf("Stack reversed.\n");
}

// Function to find the maximum element in the stack
int maximum(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    struct Node* current = stack->top;
    int max = current->data;
    while (current != NULL) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

// Function to find the minimum element in the stack
int minimum(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    struct Node* current = stack->top;
    int min = current->data;
    while (current != NULL) {
        if (current->data < min) {
            min = current->data;
        }
        current = current->next;
    }
    return min;
}

int main() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;

    // Pushing elements onto the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    // Displaying elements f the stack
    display(stack);

    // Popping an element from the stack
    printf("Popped element: %d\n", pop(stack));

    // Displaying elements of the stack after pop
    display(stack);

    // Peeking at the top element of the stack
    printf("Top element of the stack: %d\n", peek(stack));

    // Reversing the elements of the stack
    reverse(stack);

    // Displaying elements of the stack after reverse
    display(stack);

    // Finding the maximum element in the stack
    printf("Maximum element in the stack: %d\n", maximum(stack));

    // Finding the minimum element in the stack
    printf("Minimum element in the stack: %d\n", minimum(stack));

    free(stack); // Freeing the dynamically allocated memory for the stack

    return 0;
}
