#include <stdio.h>

#define SIZE 20

int linearSearch(int arr[], int size, int target, int *comparisons) {
    int i;
    *comparisons = 0;
    for (i = 0; i < size; i++) {
        (*comparisons)++;
        if (arr[i] == target) return i;
    }
    return -1;
}

int binarySearch(int arr[], int size, int target, int *comparisons) {
    int low = 0, high = size - 1, mid;
    *comparisons = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        (*comparisons)++;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(void) {
    int arr[SIZE] = {2, 5, 8, 12, 16, 19, 23, 28, 31, 35,
                      40, 44, 48, 53, 57, 61, 66, 70, 75, 79};
    int target = 66;
    int linResult, linComparisons;
    int binResult, binComparisons;
    int i;

    printf("Searching Demonstration\n");
    printf("------------------------\n");
    printf("Sorted array (%d items): [ ", SIZE);
    for (i = 0; i < SIZE; i++) printf("%d ", arr[i]);
    printf("]\n");
    printf("Target value: %d\n\n", target);

    linResult = linearSearch(arr, SIZE, target, &linComparisons);
    binResult = binarySearch(arr, SIZE, target, &binComparisons);

    if (linResult != -1)
        printf("Linear Search: found at index %d, comparisons = %d\n", linResult, linComparisons);
    else
        printf("Linear Search: not found, comparisons = %d\n", linComparisons);

    if (binResult != -1)
        printf("Binary Search: found at index %d, comparisons = %d\n", binResult, binComparisons);
    else
        printf("Binary Search: not found, comparisons = %d\n", binComparisons);

    return 0;
}

