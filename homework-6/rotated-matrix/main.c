#include <stdio.h>

#include "rotated-matrix.h"

#define N 4
#define MAX 10

int main() {
    int matrix[N][N];

    initMatrix((int *)matrix, N, MAX);

    printf("Original matrix:\n");
    printMatrix((int *)matrix, N);

    reverseRows((int *)matrix, N);
    transposeMatrix((int *)matrix, N);

    printf("Rotated matrix:\n");
    printMatrix((int *)matrix, N);

    return 0;
}
