FILES=main.cpp exon.cpp window.cpp logging.cpp gfx.cpp
FLAGS=-Wall

all: build clean

build:
	g++ $(FLAGS) -c $(FILES)
	g++ *.o -o main -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o