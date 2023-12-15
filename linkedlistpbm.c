#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a term in a polynomial
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node for a polynomial term
struct Node* createTerm(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to add a term to a polynomial represented by a linked list
struct Node* addTerm(struct Node* poly, int coeff, int exp) {
    // Create a new term node
    struct Node* newTerm = createTerm(coeff, exp);

    // If the polynomial is empty, make the new term the head
    if (poly == NULL) {
        return newTerm;
    }

    // Traverse the polynomial
}