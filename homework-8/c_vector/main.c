#include <stdio.h>

#include "../../include/rand_range.h"
#include "c_vector.h"

#define VALUE_LIMIT 100
#define GROW_SIZE 3

void fill_random_values(vector_t* vec, int amount) {
    for (int i = 0; i < amount; i++) {
        // random number out of -100 to 100 range
        int value = randInRange(VALUE_LIMIT * 2) - VALUE_LIMIT;

        push_back(vec, value);
    }
}

int main(void) {
    initRand();

    int init_size;

    printf("Enter the initial size of the array: ");
    scanf("%d", &init_size);
    fflush(stdin);

    vector_t* vec = create(init_size);

    fill_random_values(vec, init_size);

    printf("\nOriginal array: ");
    print(vec);

    fill_random_values(vec, GROW_SIZE);

    printf("\nArray after adding new elements: ");
    print(vec);

    printf("\nSize: %d", size(vec));

    printf("\nCapacity: %d", capacity(vec));

    printf("\nArray elements after pop_back: ");
    pop_back(vec);
    print(vec);

    printf("\nArray elements after clear: ");
    clear(vec);
    print(vec);

    destroy(vec);

    return 0;
}
