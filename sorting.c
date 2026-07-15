#include <stdio.h>

#define SIZE 7

void printArray(int arr[], int size) {
    int i;
    printf("[ ");
    for (i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("]\n");
}

void bubbleSort(int arr[], int size) {
    int i, j, temp, swapped;

    for (i = 0; i < size - 1; i++) {
        swapped = 0;
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        printf("After pass %d: ", i + 1);
        printArray(arr, size);
        if (!swapped) break;
    }
}

void insertionSort(int arr[], int size) {
    int i, j, key;

    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(void) {
    int arr1[SIZE] = {29, 10, 14, 37, 13, 5, 22};
    int arr2[SIZE] = {29, 10, 14, 37, 13, 5, 22};

    printf("Sorting Demonstration\n");
    printf("----------------------\n");

    printf("\n--- Bubble Sort (with pass-by-pass trace) ---\n");
    printf("Original array: ");
    printArray(arr1, SIZE);
    bubbleSort(arr1, SIZE);
    printf("Final sorted array: ");
    printArray(arr1, SIZE);

    printf("\n--- Insertion Sort ---\n");
    printf("Original array: ");
    printArray(arr2, SIZE);
    insertionSort(arr2, SIZE);
    printf("Final sorted array: ");
    printArray(arr2, SIZE);

    return 0;
}

