#include <stdio.h>

#define CAPACITY 6


void printArray(int arr[], int count) {
    int i;
    printf("[ ");
    for (i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}


int readValue(int arr[], int index) {
    return arr[index];
}


void updateValue(int arr[], int index, int newValue) {
    arr[index] = newValue;
}


int findMax(int arr[], int count) {
    int max = arr[0];
    int i;

    for (i = 1; i < count; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


void insertAt(int arr[], int *count, int index, int value) {
    int i;

    for (i = *count; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    (*count)++;
}

int main(void) {
    int marks[CAPACITY] = {55, 62, 78, 90, 48};
    int count = 5;

    printf("Student Marks - Array Demonstration\n");
    printf("-----------------------------------\n");

    printf("Initial marks: ");
    printArray(marks, count);

    printf("\nValue at index 2 (read): %d\n", readValue(marks, 2));

    updateValue(marks, 2, 85);
    printf("After updating index 2 to 85: ");
    printArray(marks, count);

    printf("\nTraversal (print all values): ");
    printArray(marks, count);

    printf("\nMaximum mark: %d\n", findMax(marks, count));

    printf("\nArray before insertion: ");
    printArray(marks, count);

    insertAt(marks, &count, 2, 70);

    printf("Array after inserting 70 at index 2: ");
    printArray(marks, count);

    return 0;
}