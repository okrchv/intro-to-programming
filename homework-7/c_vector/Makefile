CC ?=clang
COMPILER_FLAGS ?= -Wall -std=gnu99 -pedantic

hometask: ../../include/rand_range.o main.o c_vector.o
	$(CC) ../../include/rand_range.o main.o c_vector.o -o hometask

# Compile rand_range.o
../../include/rand_range.o:
	cd ../../include; make rand_range.o

c_vector.o: c_vector.c c_vector.h
	$(CC) $(COMPILER_FLAGS) -c c_vector.c

main.o: main.c c_vector.h
	$(CC) $(COMPILER_FLAGS) -c main.c

clean:
	rm -f c_vector.o main.o hometask
