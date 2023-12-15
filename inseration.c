#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {75, 8, 1, 16, 48, 3, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the insertionSort function
    insertionSort(arr, n);

    // Display the sorted array in descending order
    printf("Sorted array in descending order using Insertion Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
