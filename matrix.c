#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

matrix* createMatrix(int r, int c) {
	matrix *m = (matrix*)malloc(sizeof(matrix));
	if (m!=NULL) {
		m->r=r;
		m->c=c;
		m->data = (double**)malloc(sizeof(double*)*r);
		for(int i=0; i<r; i++) m->data[i]=(double*)malloc(sizeof(double)*c);	
	}
	return m;
}

void freeMatrix (matrix* m) {
	for(int i=0; i<m->r; i++) free(m->data[i]);
	free(m);
}

int backsubst(matrix* a, matrix* m, matrix* b) {
	if(m->r != m->c || b->c != 1 || m->r != b->r) return 2;
	for(int i=0; i<m->c; i++) if(m->data[i][i]==0) return 1;

	for(int w = m->r-1; w >= 0; w--) {
		double sum = 0;
		for(int k = w+1; k<m->r; k++) sum+= a->data[k][0]*m->data[w][k];
		a->data[w][0] = (b->data[w][0]-sum)/m->data[w][w];
	}
	return 0;
}
