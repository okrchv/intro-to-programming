#ifndef C_VECTOR_H
#define C_VECTOR_H

int* create(int size, int limit);

void push_back(int* ptr, int size, int value, int limit);

void print(const int* ptr, int size);

void destroy(int* ptr);

#endif
