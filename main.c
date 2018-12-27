#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wczytaj.h"

int main(int argc, char** argv) {

FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

   if( in == NULL ) {
       fprintf( stderr, "%s, błąd: nie mogę odczytać pliku %s\n", argv[0], argv[1] );
       return EXIT_FAILURE;
       }

   printf("Przed\n");
	   double* wczytane;
	wczytane = wczytaj_dane(in);
	printf("%f\n",wczytane[0]);
	printf("%f\n",wczytane[0]);
	printf("%f\n",wczytane[1]);
	printf("Po\n");
}
