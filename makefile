dane.o: dane.c dane.h
	gcc -c dane.c
main.o: main.c 
	gcc -c main.c
main: main.o dane.o
	gcc dane.o main.o -o main
test: main
	./main dane
