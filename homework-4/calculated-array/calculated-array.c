#include <stdbool.h>
#include <stdio.h>

#include "../../include/rand_range.h"

#define MAX 10
#define N 1000

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int occurrences[], int numbers[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (occurrences[j] < occurrences[j + 1]) {
                swap(&occurrences[j], &occurrences[j + 1]);
                swap(&numbers[j], &numbers[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) // brake if elements wasn't swapped
            break;
    }
}

int main() {
    initRand();

    int values[N];
    int occurrences[MAX] = {0};
    int numbers[MAX] = {0};

    for (int i = 0; i < N; i++) {
        int value = randInRange(MAX);

        values[i] = value;
        occurrences[value]++; // incrementing occurrence number for given value
    }

    for (int i = 0; i < MAX; i++) {
        numbers[i] = i + 1;
    }

    bubbleSort(occurrences, numbers, MAX);

    for (int i = 0; i < MAX; i++) {
        printf("Number %d: %d times\n", numbers[i], occurrences[i]);
    }
}
