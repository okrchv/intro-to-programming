#include <stdio.h>
#include <stdlib.h>

#include "dynamic_2d_array.h"

int main() {
    int size;

    // Ask user for the size of the NxN array
    printf("Enter the number of rows in the 2D array: ");
    scanf("%d", &size);
    fflush(stdin);

    // Allocate the 2D array
    char **array = allocate_2d_array(size);

    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Fill the array with random numbers
    fill_2d_array(array, size);

    // Print the original array
    printf("\nOriginal array:\n");
    print_2d_array((const char **)array, size);

    // Sort the array
    //
    // Sort characters within each row
    // sort_2d_array(array, size);

    // OR

    // Sort the rows
    sort_2d_array_lexi(array, size);

    // Print the sorted array
    printf("\nSorted array:\n");
    print_2d_array((const char **)array, size);

    // Free the array
    free_2d_array(array, size);

    return 0;
}
