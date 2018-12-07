all: main.cc window.cc
	gcc -o lee main.cc window.cc -lsfml-system -lsfml-window -lsfml-graphics
