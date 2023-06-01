taller4: main.o nodo.o quadTree.o
	g++ main.o nodo.o quadTree.o -o taller4

main.o: main.cpp nodo.h quadTree.h
	g++ -c main.cpp

nodo.o: nodo.cpp nodo.h
	g++ -c nodo.cpp

quadTree.o: quadTree.cpp quadTree.h nodo.h
	g++ -c quadTree.cpp

clean: 
	rm -f *.o taller4			