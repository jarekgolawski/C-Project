#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wczytaj.h"

#define BUFSIZE 8192

double* wczytaj_dane(FILE *in) {
	char line[80];

/*	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

	if( in == NULL ) {
		fprintf( stderr, "%s, błąd: nie mogę odczytać pliku %s\n", argv[0], argv[1] );
		return EXIT_FAILURE;
	}*/

	double dane[6];
	for(int i=0; i<6; i++){
	fgets(line, BUFSIZE, in);
	dane[i] = atof(line);
	}

	double* wyslij_dane = dane;
	return wyslij_dane;
}
