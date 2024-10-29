#include <stdio.h>

#include "../../include/rand_range.h"

#define N 10

int main() {
    initRand();

    int mat[N][N];
    int zeroRow[N] = {0};
    int zeroColumn[N] = {0};

    // printf("Origin Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = randInRange(10);
            // printf("%d ", mat[i][j]);
            if (mat[i][j] == 0) {
                zeroRow[i]++;
                zeroColumn[j]++;
            }
        }
        // printf("\n");
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (zeroRow[i] || zeroColumn[j]) {
                mat[i][j] = 0;
            }
        }
    }

    printf("Zero Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
