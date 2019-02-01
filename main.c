#include <stdio.h>
#include <stdlib.h>
#include "dane1.h"


int main(int argc, char** argv) {
	
	dane1 dane_p;
	wczytaj_dane_pocz(&dane_p,argc,argv);
	stanList* s0 = stan_poczatkowy(&dane_p);
	oblicz_wszystkie_stany(s0,&dane_p);
	wypisz_dane_do_pliku(s0,"wyniki.txt");
	system("gnuplot -p plot.txt");
}
