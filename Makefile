ifeq ($(OS),Windows_NT)
	OUTFILE = snake.exe
	RM = del 
else
	OUTFILE = snake.out
	RM = rm -f
endif

build:
	g++ -std=c++20 main.cpp -o $(OUTFILE) -lsfml-graphics -lsfml-window -lsfml-system

run: build
	./$(OUTFILE)

clean:
	rm -f $(OUTFILE)