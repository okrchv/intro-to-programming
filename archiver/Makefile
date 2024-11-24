CC ?=clang
CFLAGS = -I/usr/local/opt/libarchive/include
LDFLAGS = -L/usr/local/opt/libarchive/lib

archiver: archiver.o main.o
	$(CC) $(LDFLAGS) -larchive archiver.o main.o -o archiver

archiver.o: archiver.c archiver.h
	$(CC) -c $(CFLAGS) archiver.c

main.o: main.c archiver.h
	$(CC) -c $(CFLAGS) main.c

clean:
	rm -f archiver.o main.o archiver
