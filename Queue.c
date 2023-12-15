#include <stdio.h>
#include <stdlib.h>

// Maximum size of the queue
#define MAX_SIZE 5

// Structure to represent a linear queue
struct Queue {
    int front, rear;
    int capacity;
    int* array;
};

// Function to initialize a new queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", item);
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear++;
    queue->array[queue->rear] = item;
    printf("Enqueued %d. Front: %d, Rear: %d\n", item, queue->front, queue->rear);
}

// Function to dequeue (delete) an element from the queue
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    int item = queue->array[queue->front];
    printf("Dequeued %d. Front: %d, Rear: %d\n", item, queue->front, queue->rear);

    if (queue->front == queue->rear) {
        // Last element is dequeued, reset front and rear
        queue->front = queue->rear = -1;
    } else {
        // Move front to the next element
        queue->front++;
    }
}

// Function to display the elements in the queue
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    // Create a queue with a maximum capacity of MAX_SIZE
    struct Queue* queue = createQueue(MAX_SIZE);

    // Enqueue elements into the queue
    enqueue(queue, 61);
    displayQueue(queue);

    enqueue(queue, 16);
    displayQueue(queue);

    enqueue(queue, 8);
    displayQueue(queue);

    enqueue(queue, 27);
    displayQueue(queue);

    // Dequeue three elements from the queue
    dequeue(queue);
    displayQueue(queue);

    dequeue(queue);
    displayQueue(queue);

    dequeue(queue);
    displayQueue(queue);

    return 0;
}
