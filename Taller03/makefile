taller3: main.o funciones.o
	g++ -o taller3 main.o funciones.o

main.o: main.cpp funciones.h
	g++ -c main.cpp

funciones.o: funciones.cpp funciones.h
	g++ -c funciones.cpp

clean:
	rm -f *.o taller3