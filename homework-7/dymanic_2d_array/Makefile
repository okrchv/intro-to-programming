CC ?=clang
COMPILER_FLAGS ?= -Wall -std=gnu99 -pedantic

hometask: main.o dynamic_2d_array.o
	$(CC) main.o dynamic_2d_array.o -o hometask

dynamic_2d_array.o: dynamic_2d_array.c dynamic_2d_array.h
	$(CC) $(COMPILER_FLAGS) -c dynamic_2d_array.c

main.o: main.c dynamic_2d_array.h
	$(CC) $(COMPILER_FLAGS) -c main.c

clean:
	rm -f dynamic_2d_array.o main.o hometask
