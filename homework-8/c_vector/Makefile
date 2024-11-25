CC ?=clang
CXX ?= clang++
CFLAGS ?= -Wall -pedantic
CXXFLAGS ?= -std=c++14 $(shell pkg-config --cflags gtest)
GTEST_LDFLAGS ?= -std=c++14 $(shell pkg-config --libs gtest) -lgtest_main

hometask: ../../include/rand_range.o main.o c_vector.o
	$(CC) ../../include/rand_range.o main.o c_vector.o -o hometask

# Compile rand_range.o
../../include/rand_range.o:
	cd ../../include; make rand_range.o

c_vector.o: c_vector.c c_vector.h
	$(CC) $(CFLAGS) -c c_vector.c

main.o: main.c c_vector.h
	$(CC) $(CFLAGS) -c main.c

# Target for asserts testing
test_c_vector: test_c_vector.o c_vector.o
	$(CC) $(CFLAGS) -o test_c_vector test_c_vector.o c_vector.o

test_c_vector.o: test_c_vector.c c_vector.h
	$(CC) $(CFLAGS) -c test_c_vector.c

# Target for Google Test
test_gtest: test_gtest.o c_vector.o
	$(CXX) $(GTEST_LDFLAGS) -o test_gtest test_gtest.o c_vector.o

test_gtest.o: test_gtest.c c_vector.h
	$(CXX) $(CXXFLAGS) -c test_gtest.c

clean:
	rm -f c_vector.o main.o test_c_vector.o hometask test_c_vector test_gtest.o test_gtest
