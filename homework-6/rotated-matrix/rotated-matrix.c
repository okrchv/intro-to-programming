#include <stdio.h>

#include "../../include/rand_range.h"
#include "rotated-matrix.h"

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void initMatrix(int *matrix, int size, int limit) {
    initRand();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *((matrix + i * size) + j) = randInRange(limit);

        }
    }
}

void printMatrix(const int *matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *((matrix + i * size) + j));
        }
        printf("\n");
    }
}

// reversing each row
void reverseRows(int *matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size / 2; j++) {
            swap((matrix + i * size) + j, (matrix + i * size) + (size - j - 1));
        }
    }
}

// transposing
void transposeMatrix(int *matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            swap(((matrix + i * size) + j), ((matrix + j * size) + i));
        }
    }
}
