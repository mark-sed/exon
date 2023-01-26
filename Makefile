FILES=main.cpp exon.cpp window.cpp logging.cpp gfx.cpp input.cpp
FLAGS=-Wall -std=c++17
PATHS=libs/curlpp/include

all: build clean

build:
	g++ $(FLAGS) -c $(FILES) -I $(PATHS)
	g++ *.o -o main -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o
