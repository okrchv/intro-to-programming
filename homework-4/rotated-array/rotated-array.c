#include <stdio.h>

#include "../../include/rand_range.h"

#define N 4

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    initRand();
    int mat[N][N];

    printf("Original Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = randInRange(10);
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    // reversing each row
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N / 2; j++) {
                swap(&mat[i][j], &mat[i][N - j - 1]);
            }
        }

    // transposing
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(&mat[i][j], &mat[j][i]);
        }
    }

    printf("Rotated Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
