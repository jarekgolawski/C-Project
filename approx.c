#include "gauss.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double* approximate(int n, double x[]) {
	matrix* A = createMatrix(4,4);
	matrix* b = createMatrix(4,1);
	matrix* result = createMatrix(4,1);
	double sum = 0;

	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			sum = 0;
			for(int k=0; k<n; k++) sum+=pow(x[2*k],i+j);
			A->data[i][j]=sum;
		}
	}

	for(int j=0; j<4; j++) {
		b->data[j][0];
		for(int i=0; i<n; i++) b->data[j][0]+=x[2*i+1]*pow(x[2*i],j);
	}

	eliminate(A,b);
	backsubst(result,A,b);

	freeMatrix(A);
	freeMatrix(b);

	double* factors = malloc(4*sizeof(double));
	for(int i=0; i<4; i++) factors[i]=result->data[i][0];

	freeMatrix(result);
	return factors;
}
