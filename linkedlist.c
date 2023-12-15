#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
struct Node* insertNode(struct Node* head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Traverse to the end and add the new node
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}

// Function to delete a node with a given value from the linked list
struct Node* deleteNode(struct Node* head, int key) {
    // If the list is empty, nothing to delete
    if (head == NULL) {
        return head;
    }

    // If the head node needs to be deleted
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Search for the node to be deleted
    struct Node* current = head;
    struct Node* prev = NULL;
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If the node with the given value is not present
}
