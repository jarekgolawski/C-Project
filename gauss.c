#include "gauss.h"

int eliminate(matrix* m, matrix* b) {
	for (int i=0; i<m->r; i++) if(m->data[i][i]==0) return 1;
	
	for (int i=0; i<m->r-1; i++) {
		for (int j=i+1; j<m->r; j++) {
			double n = m->data[j][i]/m->data[i][i];
			for (int z=i; z<m->r; z++) m->data[j][z]-=n*m->data[i][z];
			b->data[j][0]-=n*b->data[i][0];
		}
	}
	return 0;
}


