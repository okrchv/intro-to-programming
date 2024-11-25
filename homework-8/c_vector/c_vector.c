#include "c_vector.h"

#include <stdio.h>
#include <stdlib.h>

vector_t* create(int init_capacity) {
    if (init_capacity <= 0) {
        return NULL;
    }

    vector_t* vec = malloc(sizeof(vector_t));

    vec->size = 0;
    vec->capacity = init_capacity * 2;
    vec->values = malloc(vec->capacity * sizeof(int));

    if (!vec->values) {
        fprintf(stderr, "Failed to allocate memory\n");
        return NULL;
    }

    return vec;
}

void realloc_values(vector_t* vec, int new_capacity) {
    int* new_values = realloc(vec->values, new_capacity * sizeof(int));

    if (new_values == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return;
    }

    vec->values = new_values;
    vec->capacity = new_capacity;
}

// Time complexity: O(1) amortized; O(n) worst-case (due to reallocation);
void push_back(vector_t* vec, int value) {
    if (vec->size == vec->capacity) {
        realloc_values(vec, vec->capacity * 2);
    }

    vec->values[vec->size] = value;
    vec->size++;
}

// Time complexity: O(1) amortized; O(n) worst-case (due to reallocation);
void pop_back(vector_t* vec) {
    if (vec->size == 0) return;

    vec->size--;

    int new_capacity = vec->capacity / 2;
    if (vec->size < new_capacity) {
        realloc_values(vec, new_capacity);
    }
}

int size(const vector_t* vec) { return vec->size; }

int capacity(const vector_t* vec) { return vec->capacity; }

void clear(vector_t* vec) { vec->size = 0; }

void print(const vector_t* vec) {
    for (int i = 0; i < vec->size; i++) {
        printf("%d ", vec->values[i]);
    }
}

void destroy(vector_t* vec) {
    free(vec->values);
    free(vec);
}
