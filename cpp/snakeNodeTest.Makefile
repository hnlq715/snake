all : clean main

clean: 
	rm -f  *.o

main: snakeNodeTest.o dlinkedList.h  

	g++ -o snakeNodeTest  snakeNodeTest.o dlinkedList.h 

snakeNodeTest.o : snakeNodeTest.cpp 
	g++ -c snakeNodeTest.cpp 

dlinkedList.o : dlinkedList.h
	g++ -c dlinkedList.h
