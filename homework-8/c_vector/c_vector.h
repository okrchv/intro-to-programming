#ifndef C_VECTOR_H
#define C_VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Vector {
    int size;
    int capacity;
    int* values;
} vector_t;

vector_t* create(int size);

void push_back(vector_t* vec, int value);

void pop_back(vector_t* vec);

void clear(vector_t* vec);

int size(const vector_t* vec);

int capacity(const vector_t* vec);

void print(const vector_t* vec);

void destroy(vector_t* vec);

#ifdef __cplusplus
}
#endif

#endif
