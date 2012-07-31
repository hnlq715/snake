CC=g++
PROGS=snake
CFLAGS=-Wall -O2 -g
LDFLAGS=-L /usr/lib -lncurses


all: $(PROGS)

snake:
	$(CC) $(CFLAGS) -o $(PROGS) \
		   mySnake.cpp \
		   Screen.cpp \
		   LivingArea.cpp \
		   Snake.cpp \
		   SnakeNode.cpp \
		   Block.cpp \
		   $(LDFLAGS)
clean:
	rm -f *.o
	rm -f *.so
	rm -f *.a
	rm -f $(PROGS)
