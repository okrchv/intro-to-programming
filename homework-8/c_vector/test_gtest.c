#include <gtest/gtest.h>

#include "c_vector.h"

// Test for creating a vector, pushing elements, and checking size and capacity changes
TEST(VectorTest, CreatePushPopAndCapacity) {
    // Create a vector with initial capacity of 3
    vector_t* vec = create(3);

    // Initial state checks
    EXPECT_NE(vec, nullptr);      // Ensure the vector is created
    EXPECT_EQ(vec->capacity, 6);  // Capacity should be 6
    EXPECT_EQ(vec->size, 0);      // Initial size should be 0

    // Push elements into the vector
    push_back(vec, 10);
    push_back(vec, 20);
    push_back(vec, 30);
    EXPECT_EQ(vec->size, 3);        // Size should be 3 after 3 pushes
    EXPECT_EQ(vec->values[0], 10);  // First element should be 10
    EXPECT_EQ(vec->values[1], 20);  // Second element should be 20
    EXPECT_EQ(vec->values[2], 30);  // Third element should be 30
    EXPECT_EQ(vec->capacity, 6);    // Capacity should still be 6

    // Push more elements to trigger reallocation
    push_back(vec, 40);
    push_back(vec, 50);
    push_back(vec, 60);
    push_back(vec, 70);
    EXPECT_EQ(vec->size, 7);  // Size should be 7 after pushing 4 more elements
    EXPECT_EQ(vec->capacity, 12);  // Capacity should double to 12

    // Pop elements from the vector
    pop_back(vec);
    EXPECT_EQ(vec->size, 6);       // Size should be 6 after pop
    EXPECT_EQ(vec->capacity, 12);  // Capacity should still be 12

    pop_back(vec);
    pop_back(vec);
    EXPECT_EQ(vec->size, 4);      // Size should be 4 after popping 3 elements
    EXPECT_EQ(vec->capacity, 6);  // Capacity should shrink to 6

    // Clean up
    destroy(vec);
}

// Test for clearing the vector and resetting size
TEST(VectorTest, ClearAndSizeReset) {
    vector_t* vec = create(5);

    // Push some elements
    push_back(vec, 10);
    push_back(vec, 20);
    push_back(vec, 30);
    EXPECT_EQ(vec->size, 3);  // Size should be 3 before clearing

    // Clear the vector
    clear(vec);
    EXPECT_EQ(vec->size, 0);       // Size should be reset to 0 after clearing
    EXPECT_EQ(vec->capacity, 10);  // Capacity should remain unchanged

    // Clean up
    destroy(vec);
}

// Test for invalid vector creation (negative or zero capacity)
TEST(VectorTest, CreateWithInvalidCapacity) {
    vector_t* vec;

    vec = create(0);
    EXPECT_EQ(vec, nullptr);  // Should return NULL for invalid capacity (0)

    vec = create(-5);
    EXPECT_EQ(vec, nullptr);  // Should return NULL for invalid capacity (negative)
}
