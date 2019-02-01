#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct matrix {
	int r;
	int c;
	double **data;
} matrix;

matrix *createMatrix(int,int);
void freeMatrix(matrix*);
int backsubst(matrix*,matrix*,matrix*);
#endif
