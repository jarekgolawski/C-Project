#ifndef DANE_H_
#define DANE_H_

typedef struct dane_jeden{
	double wsp; // wspolczynnik przewodnictwa cieplnego
	double mp; // masa preta
	double cpow; // calkowita powierzchnia preta
	double cwp; // cieplo wlasciwe preta
	double mc; // masa cieczy chlodzacej
	double rt; // roznica temperatur definiujaca koniec symulacji
} dane;

void wczytaj_dane(int argc, char **argv, dane d);

#endif
