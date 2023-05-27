NReinas: main.o NReinas.o
	g++ -o NReinas main.o NReinas.o

main.o: main.cpp NReinas.h
	g++ -c main.cpp

NReinas.o: NReinas.cpp NReinas.h
	g++ -c NReinas.cpp

clean:
	rm -f *.o NReinas