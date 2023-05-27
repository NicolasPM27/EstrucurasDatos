
curiosity: main.o clases.o funciones.o
	g++ -o curiosity main.o clases.o funciones.o

main.o: main.cpp clases.h funciones.h
	g++ -c main.cpp

clases.o: clases.cpp clases.h
	g++ -c clases.cpp

funciones.o: funciones.cpp funciones.h clases.h
	g++ -c funciones.cpp	

clean:
	rm -f curiosity *.o