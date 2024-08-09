#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}
void moveDisk(char source, char destination, int disk) {
    printf("Move disk %d from %c to %c\n", disk, source, destination);
}
void towerOfHanoi(int num_disks, struct Stack* source, struct Stack* auxiliary, struct Stack* destination) {
    int total_moves = (1 << num_disks) - 1; // Total number of moves required
    char s = 'A', a = 'B', d = 'C'; // Source, Auxiliary, and Destination towers
    if (num_disks % 2 == 0) {
        char temp = a;
        a = d;
        d = temp;
    }
    for (int i = num_disks; i >= 1; i--)
        push(source, i);
    for (int i = 1; i <= total_moves; i++) {
        char source_tower = ((i & i - 1) % 3 == 0) ? s : (((i & i - 1) % 3 == 1) ? a : d);
        char dest_tower = ((i & i - 1) % 3 == 0) ? (((i & i - 1) >> 1) % 3 == 0) ? a : d : s;
        if (!isEmpty(source) && (isEmpty(destination) || source->array[source->top] < destination->array[destination->top]))
            moveDisk(source_tower, dest_tower, pop(source));
        else
            moveDisk(dest_tower, source_tower, pop(destination));
    }
}
int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    struct Stack* source = createStack(MAX_SIZE);
    struct Stack* auxiliary = createStack(MAX_SIZE);
    struct Stack* destination = createStack(MAX_SIZE);
    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    towerOfHanoi(num_disks, source, auxiliary, destination);
    free(source->array);
    free(source);
    free(auxiliary->array);
    free(auxiliary);
    free(destination->array);
    free(destination);
    return 0;
}
