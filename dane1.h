#ifndef DANE_1_H_
#define DANE_1_H_

typedef struct dane1 {
	double h;
	double A;
	double mb;
	double mw;
	double cb;
	double Tb;
	double Tw;
	double* cp;
} dane1;

typedef struct stan{
	double t;
	double Tb;
	double Tw;
	struct stan* poprzedni;
	struct stan* nastepny;
} stanList;

void wczytaj_dane_pocz(dane1*,int,char**);
void oblicz_nastepny_stan(stanList*,dane1*, double);
stanList* stan_poczatkowy(dane1*);
void oblicz_wszystkie_stany(stanList*,dane1*);
void wypisz_dane_do_pliku(stanList*,char*);
#endif
