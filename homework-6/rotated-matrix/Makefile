CC = clang
CFLAGS = -std=gnu99 -pedantic -Wall

# Target executable
hometask: ../../include/rand_range.o rotated-matrix.o main.o
	$(CC) ../../include/rand_range.o rotated-matrix.o main.o -o hometask

# Compile rand_range.o
../../include/rand_range.o:
	cd ../../include; make rand_range.o

# Compile rotated-matrix.o
rotated-matrix.o: rotated-matrix.c rotated-matrix.h
	$(CC) -c $(CFLAGS) rotated-matrix.c

# Compile main.o
main.o: main.c rotated-matrix.h
	$(CC) -c $(CFLAGS) main.c

clean:
	rm -f ./hometask rotated-matrix.o main.o
