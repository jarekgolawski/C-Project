wczytaj.o: wczytaj.c wczytaj.h
		gcc -c wczytaj.c
main.o: main.c 
		gcc -c main.c
main: main.o wczytaj.o
		gcc wczytaj.o main.o -o main
