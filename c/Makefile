CC=gcc
PROGS=test_list.exe
CFLAGS=-Wall -O0 -g
LDFLAGS=-L /usr/lib -lncurses


all: $(PROGS)

list.o: list.c list.h
	$(CC) -c $(CFLAGS) $< -o $@

test_list.exe: list.o list_test.c
	$(CC) $(CFLAGS) $< list_test.c -o $@

clean:
	rm -f *.o
	rm -f *.so
	rm -f *.a
	rm -f $(PROGS)
	rm -f *.core
	rm -f *.stackdump

