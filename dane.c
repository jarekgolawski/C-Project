#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dane.h"

#define BUFSIZE 8192

void wczytaj_dane(int argc, char** argv, dane d) {
	char line[80];

	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

	if( in == NULL ) {
		fprintf( stderr, "%s, błąd: nie mogę odczytać pliku %s\n", argv[0], argv[1] );
	}
	
	printf("Jestem w funkcji");
}
