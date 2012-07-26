CC=g++
PROGS=snake
CFLAGS=-O2
LDFLAGS=-L /usr/lib -lncurses


all: $(PROGS)

snake:
	$(CC) $(CFLAGS) -o mySnake \
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
