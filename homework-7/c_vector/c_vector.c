#include "c_vector.h"

#include <stdio.h>
#include <stdlib.h>

#include "../../include/rand_range.h"

int* create(int size, int limit) {
    initRand();

    if (size <= 0) {
        return NULL;
    }

    int* ptr = malloc(size * sizeof(int));
    if (ptr == NULL) {
        return NULL;
    }

    // random number out of -100 to 100 range
    for (int i = 0; i < size; i++) {
        ptr[i] = randInRange(limit * 2) - limit;
    }

    return ptr;
}

void push_back(int* ptr, int size, int value, int limit) {
    initRand();

    ptr = realloc(ptr, (size + value) * sizeof(int));

    for (int i = 0; i < value; i++) {
        ptr[size + i] = randInRange(limit * 2) - limit;
    }
}

void print(const int* ptr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

void destroy(int* ptr) { free(ptr); }
