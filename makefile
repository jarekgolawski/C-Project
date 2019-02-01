main: dane1.o main.o matrix.o gauss.o approx.o
	gcc dane1.o main.o matrix.o gauss.o approx.o -lm -o main
main.o: main.c
	gcc -c main.c
dane1.o: dane1.c
	gcc -c dane1.c
test: main
	./main dane1
matrix.o: matrix.c
	gcc -c matrix.c
gauss.o: gauss.c
	gcc -c gauss.c
approx.o: approx.c
	gcc -c approx.c -lm
