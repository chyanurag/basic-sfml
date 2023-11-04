all: main.o
	g++ main.o -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -o main
main.o : main.cc
	g++ -c main.cc
