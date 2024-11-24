#include <stdio.h>

#include "c_vector.h"

#define LIMIT 100
#define ADD_VALUE 5

int main(void) {
    int size;

    printf("Enter the initial size of the array: ");
    scanf("%d", &size);
    fflush(stdin);

    int* arr = create(size, LIMIT);

    printf("\nOriginal array:\n");
    print(arr, size);

    push_back(arr, size, ADD_VALUE, LIMIT);

    printf("\nArray after adding new elements:\n");
    print(arr, size + ADD_VALUE);

    return 0;
}
