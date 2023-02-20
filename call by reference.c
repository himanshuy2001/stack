#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

int is_full(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack *stack, int item) {
    if (is_full(stack)) {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }

    stack->top++;
    stack->data[stack->top] = item;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }

    int item = stack->data[stack->top];
    stack->top--;

    return item;
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    while (!is_empty(&stack)) {
        int item = pop(&stack);
        printf("%d\n", item);
    }

    return 0;
}
