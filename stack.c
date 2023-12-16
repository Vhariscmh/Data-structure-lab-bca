#include <stdio.h>
#define MAX_SIZE 10

// Structure to represent a stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
    } else {
        stack->top++;
        stack->arr[stack->top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    int poppedValue;
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Assuming -1 represents an error or an invalid value
    } else {
        poppedValue = stack->arr[stack->top];
        stack->top--;
        return poppedValue;
    }
}

// Function to display the elements of the stack
void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Popped element: %d\n", pop(&stack));

    display(&stack);

    return 0;
}

