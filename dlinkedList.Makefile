all : clean main

clean: 
	rm -f  *.o

main: dlinkedListTest.o dlinkedList.h  

	g++ -o dlinkedListTest  dlinkedListTest.o dlinkedList.h 

dlinkedListTest.o : dlinkedListTest.cpp 
	g++ -c dlinkedListTest.cpp 

dlinkedList.o : dlinkedList.h
	g++ -c dlinkedList.h
