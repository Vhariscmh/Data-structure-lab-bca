#include <stdio.h>
#include <stdlib.h>

// Maximum size of the circular queue
#define MAX_SIZE 5

// Structure to represent a circular queue
struct CircularQueue {
    int front, rear;
    int capacity;
    int* array;
};

// Function to initialize a new circular queue
struct CircularQueue* createCircularQueue(int capacity) {
    struct CircularQueue* cqueue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    cqueue->capacity = capacity;
    cqueue->front = cqueue->rear = -1;
    cqueue->array = (int*)malloc(capacity * sizeof(int));
    return cqueue;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* cqueue) {
    return ((cqueue->rear + 1) % cqueue->capacity == cqueue->front);
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* cqueue) {
    return (cqueue->front == -1 && cqueue->rear == -1);
}

// Function to enqueue (insert) an element into the circular queue
void enqueue(struct CircularQueue* cqueue, int item) {
    if (isFull(cqueue)) {
        printf("Queue is full. Cannot enqueue %d.\n", item);
        return;
    }

    if (isEmpty(cqueue)) {
        cqueue->front = cqueue->rear = 0;
    } else {
        cqueue->rear = (cqueue->rear + 1) % cqueue->capacity;
    }

    cqueue->array[cqueue->rear] = item;
    printf("Enqueued %d. Front: %d, Rear: %d\n", item, cqueue->front, cqueue->rear);
}

// Function to dequeue (delete) an element from the circular queue
void dequeue(struct CircularQueue* cqueue) {
    if (isEmpty(cqueue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    int item = cqueue->array[cqueue->front];
    printf("Dequeued %d. Front: %d, Rear: %d\n", item, cqueue->front, cqueue->rear);

    if (cqueue->front == cqueue->rear) {
        // Last element is dequeued, reset front and rear
        cqueue->front = cqueue->rear = -1;
    } else {
        // Move front to the next element
        cqueue->front = (cqueue->front + 1) % cqueue->capacity;
    }
}

// Function to display the elements in the circular queue
void displayCircularQueue(struct CircularQueue* cqueue) {
    if (isEmpty(cqueue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue: ");
    int i = cqueue->front;
    do {
        printf("%d ", cqueue->array[i]);
        i = (i + 1) % cqueue->capacity;
    } while (i != (cqueue->rear + 1) % cqueue->capacity);
    printf("\n");
}

int main() {
    // Create a circular queue with a maximum capacity of MAX_SIZE
    struct CircularQueue* cqueue = createCircularQueue(MAX_SIZE);

    // Enqueue elements into the circular queue
    enqueue(cqueue, 61);
    displayCircularQueue(cqueue);

    enqueue(cqueue, 16);
    displayCircularQueue(cqueue);

    enqueue(cqueue, 8);
    displayCircularQueue(cqueue);

    enqueue(cqueue, 27);
    displayCircularQueue(cqueue);

    // Dequeue four elements from the circular queue
    dequeue(cqueue);
    displayCircularQueue(cqueue);

    dequeue(cqueue);
    displayCircularQueue(cqueue);

    dequeue(cqueue);
    displayCircularQueue(cqueue);

    dequeue(cqueue);
    displayCircularQueue(cqueue);

    return 0;
}
