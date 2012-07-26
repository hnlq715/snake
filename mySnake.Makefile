
LIBS=
all : clean main

clean: 
	rm -f  *.o

main: mySnake.o   
	g++ -o mySnake mySnake.o 
mySnake.o: mySnake.cpp Screen.o
	g++ -c mySnake.cpp Screen.o
Screen.o: Screen.cpp LivingArea.cpp Snake.cpp
	g++ -c Snake.cpp Screen.cpp LivingArea.cpp 

snakeNodeTest.o : snakeNodeTest.cpp 
	g++ -c snakeNodeTest.cpp 

dlinkedList.o : dlinkedList.h
	g++ -c dlinkedList.h 
