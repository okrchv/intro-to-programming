#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "c_vector.h"

void test_create() {
    // Test creation of vector with valid capacity
    vector_t* vec = create(5);
    assert(vec != NULL);  // The vector should be created successfully
    assert(vec->capacity ==
           10);  // The capacity should be twice the initial capacity
    assert(vec->size == 0);  // The initial size should be 0
    destroy(vec);

    // Test creation with non-positive capacity
    vec = create(0);
    assert(vec == NULL);  // The vector should return NULL for invalid capacity

    vec = create(-5);
    assert(vec == NULL);  // The vector should return NULL for negative capacity
}

void test_push_back() {
    vector_t* vec = create(3);
    push_back(vec, 10);
    push_back(vec, 20);
    assert(vec->size == 2);        // The size should be 2 after two pushes
    assert(vec->values[0] == 10);  // The first element should be 10
    assert(vec->values[1] == 20);  // The second element should be 20
    assert(vec->capacity == 6);    // The capacity should be 6

    // Add more elements to trigger reallocation
    push_back(vec, 30);
    push_back(vec, 40);
    push_back(vec, 50);
    assert(vec->size == 5);      // The size should be 5 after 5 pushes
    assert(vec->capacity == 6);  // The capacity should still be 6

    push_back(vec, 60);
    push_back(vec, 70);
    assert(vec->size == 7);       // The size should now be 7
    assert(vec->capacity == 12);  // The capacity should have increased to 12
                                  // after reaching the limit
    destroy(vec);
}

void test_pop_back() {
    vector_t* vec = create(5);
    push_back(vec, 10);
    push_back(vec, 20);
    push_back(vec, 30);
    assert(vec->size == 3);       // The size should be 3 after 3 pushes
    assert(vec->capacity == 10);  // The capacity should be 10

    // Pop an element
    pop_back(vec);
    assert(vec->values[1] == 20);  // The second element should be 20
    assert(vec->size == 2);        // The size should be 2 after pop
    assert(vec->capacity == 5);    // The capacity should be 5

    // Pop another element
    pop_back(vec);
    assert(vec->values[0] == 10);  // The first element should be 10
    assert(vec->size == 1);        // The size should be 1 after another pop
    assert(vec->capacity == 2);    // The capacity should be 2

    // Pop the last element
    pop_back(vec);
    assert(vec->size == 0);      // The size should be 0 after last pop
    assert(vec->capacity == 1);  // The capacity should still be 1
    destroy(vec);
}

void test_clear() {
    vector_t* vec = create(5);
    push_back(vec, 10);
    push_back(vec, 20);
    push_back(vec, 30);
    assert(vec->size == 3);  // The size should be 3 before clearing
    clear(vec);
    assert(vec->size == 0);  // The size should be 0 after clearing
    destroy(vec);
}

void test_size_and_capacity() {
    vector_t* vec = create(5);
    assert(size(vec) == 0);       // The size should initially be 0
    assert(capacity(vec) == 10);  // The capacity should initially be 10

    push_back(vec, 10);
    assert(size(vec) == 1);       // The size should be 1 after 1 push
    assert(capacity(vec) == 10);  // The capacity should still be 10

    push_back(vec, 20);
    push_back(vec, 30);
    push_back(vec, 40);
    push_back(vec, 50);
    push_back(vec, 60);
    assert(size(vec) == 6);       // The size should be 6 after 6 pushes
    assert(capacity(vec) == 10);  // The capacity should still be 10
    destroy(vec);
}

int main() {
    test_create();
    test_push_back();
    test_pop_back();
    test_clear();
    test_size_and_capacity();
    printf("All tests passed!\n");
    return 0;
}
