#include <stdio.h>
#include <stdlib.h>
#include "dane1.h"
#include <math.h>
#include "approx.h"

void wczytaj_dane_pocz(dane1 *dp,int argc,  char** argv) {
	FILE *in = argc > 1 ? fopen(argv[1],"r") : stdin;
	if(in==NULL) printf("Nie wczytano pliku!");
	fscanf(in,"%lf",&dp->h);
	fscanf(in,"%lf",&dp->A);
	fscanf(in,"%lf",&dp->mb);
	fscanf(in,"%lf",&dp->mw);
	fscanf(in,"%lf",&dp->cb);
	fscanf(in,"%lf",&dp->Tb);
	fscanf(in,"%lf",&dp->Tw);
	fclose(in);

	FILE *in2 = argc > 2 ? fopen(argv[2],"r") :stdin;
	if(in2==NULL) printf("Nie wczytano drugiego pliku!");
	int i=0;
	dp->cp=malloc(sizeof(double));
	while(fscanf(in2,"%lf",dp->cp+i)==1){
	       	i++;
		dp->cp = realloc(dp->cp,sizeof(double)*(i+1));
	}
        fclose(in2);	
}

void oblicz_nastepny_stan(stanList* s, dane1 *dp, double cp) {
	stanList* ns = malloc(sizeof(*ns));
	s-> nastepny = ns;
	ns-> poprzedni = s;
	ns->t= s->t+0.002;
	ns->Tb= s->Tb+0.002*(s->Tw-s->Tb)*dp->h*dp->A/(dp->mb*dp->cb);
	ns->Tw= s->Tw+0.002*(s->Tb-s->Tw)*dp->h*dp->A/(dp->mw*cp);

}

stanList* stan_poczatkowy(dane1* dane_p) {
	stanList* s0 = malloc(sizeof(*s0));
	s0->t=0;
	s0->Tb=dane_p->Tb;
	s0->Tw=dane_p->Tw;
	s0->poprzedni = NULL;
	s0->nastepny = NULL;
}

void oblicz_wszystkie_stany(stanList* s0, dane1* dp) {
	double* factors = malloc(sizeof(double)*4);
	factors = approximate(8,dp->cp);
	double cp;
	stanList* ptrS = s0;
	
	while((ptrS->Tb-ptrS->Tw)>1) {
		cp = factors[3]*pow(ptrS->Tw,3) + factors[2]*pow(ptrS->Tw,2)
	        + factors[1]*pow(ptrS->Tw,1) + factors[0];
		oblicz_nastepny_stan(ptrS,dp,cp);
		ptrS = ptrS->nastepny;
	}
	free(factors);
}

void wypisz_dane_do_pliku(stanList* s0,char* txt){
	FILE *out = fopen(txt,"w+");
	stanList* s = s0;
	while(s->nastepny!=NULL) {
		fprintf(out,"%f %f %f\n", s->t, s->Tb, s->Tw);
		s=s->nastepny;
	}
	fclose(out);
}
