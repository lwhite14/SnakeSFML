all: run

build:
	g++ -std=c++20 main.cpp -o snake.out -lsfml-graphics -lsfml-window -lsfml-system

run: build
	./snake.out

clean:
	rm -f snake.out