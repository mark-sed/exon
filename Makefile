all: build clean

build:
	g++ -c main.cpp exon.cpp window.cpp
	g++ main.o exon.o window.o -o main -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o