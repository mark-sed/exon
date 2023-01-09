FILES=main.cpp exon.cpp window.cpp logging.cpp

all: build clean

build:
	g++ -c $(FILES)
	g++ *.o -o main -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o