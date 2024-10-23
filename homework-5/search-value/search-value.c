#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/rand_range.h"

#define N 10
#define MAX 1000

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) // brake if elements wasn't swapped
            break;
    }
}

int binarySearchRecursive(int arr[], int value, int firstIndex, int lastIndex) {
    if (firstIndex <= lastIndex) {
        int midIndex = firstIndex + (lastIndex - firstIndex) / 2;

        if (arr[midIndex] == value)
            return midIndex;

        if (arr[midIndex] > value)  {
            return binarySearchRecursive(arr, value, firstIndex, midIndex - 1);
        }

        if (arr[midIndex] < value)  {
            return binarySearchRecursive(arr, value, midIndex + 1, lastIndex);
        }
    }

    return -1;
}

int binarySearchLoop(int arr[], int value, int firstIndex, int lastIndex) {
    while (firstIndex <= lastIndex) {
        int midIndex = firstIndex + (lastIndex - firstIndex) / 2;

        if (arr[midIndex] == value)
            return midIndex;

        if (arr[midIndex] < value)  {
             firstIndex = midIndex + 1;
        } else {
             lastIndex = midIndex - 1;
        }
    }

    return -1;
}

int main() {
    initRand();

    int values[N];
    int searchedValue;

    printf("Original array:\n");
    for (int i = 0; i < N; i++) {
        values[i] = randInRange(MAX);
        printf("%d ", values[i]);
    }
    printf("\n");

    printf("Please choose num to search for:\n");
    if (scanf(" %d", &searchedValue) != 1) {
        printf("Error: Invalid input.");
        exit(1);
    }
    fflush(stdin);

    bubbleSort(values, N);

    printf("Sorted array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");

    int recursiveBS = binarySearchRecursive(values, searchedValue, 0, N - 1);
    int loopBS = binarySearchLoop(values, searchedValue, 0, N - 1);

    int result = recursiveBS;
    // int result = loopBS;
    if (result == -1) {
        printf("Element is not presented in array.");
    }
    else {
        printf("Element is presented at index: %d", result);
    }
    return 0;
}
