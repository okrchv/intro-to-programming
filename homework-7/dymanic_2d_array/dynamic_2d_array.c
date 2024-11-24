#include "dynamic_2d_array.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Allocates 2D array
char** allocate_2d_array(int size) {
    char** arr = (char**)malloc(size * sizeof(char*));
    if (arr == NULL) {
        return NULL;
    }

    return arr;
}

// Fill the 2D array
void fill_2d_array(char** arr, int size) {
    char* buffer;
    size_t bufsize = 32;
    size_t characters;

    for (int i = 0; i < size; i++) {
        buffer = (char*)malloc(bufsize * sizeof(char));

        printf("Enter string for row %d: ", i + 1);
        characters = getline(&buffer, &bufsize, stdin);

        arr[i] = (char*)malloc(characters * sizeof(char));

        memcpy(arr[i], buffer, characters * sizeof(char));

        free(buffer);
        buffer = NULL;
    }
}

// Print the 2D array
void print_2d_array(const char** arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s", arr[i]);
    }
}

void swap_val(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void swap_ptr(char* x, char* y) {
    char* temp = x;
    x = y;
    y = temp;
}

// Sort characters within each string
void sort_2d_array(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        int length = strlen(arr[i]);

        // Bubble sort to sort characters in the string
        for (int j = 0; j < length - 1; j++) {
            for (int k = 0; k < length - j - 1; k++) {
                if (arr[i][k] > arr[i][k + 1]) {
                    swap_val(&arr[i][k], &arr[i][k + 1]);
                }
            }
        }
    }
}

// Sort the rows based on lexicographical order
void sort_2d_array_lexi(char** arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                swap_ptr(arr[j], arr[j + 1]);
            }
        }
    }
}

// Free the 2D array
void free_2d_array(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
}
