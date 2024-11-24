#ifndef DYNAMIC_2D_ARRAY_INT_H
#define DYNAMIC_2D_ARRAY_INT_H

// Allocates a 2D array, returns NULL in case of errors
char** allocate_2d_array(int size);

// Fills the 2D array with random integers
void fill_2d_array(char** arr, int size);

// Prints the 2D array
void print_2d_array(const char** arr, int size);

// Sorts each row of the 2D array
void sort_2d_array(char** arr, int size);

void sort_2d_array_lexi(char** arr, int size);

// Frees the allocated memory for the 2D array
void free_2d_array(char** arr, int size);

#endif
