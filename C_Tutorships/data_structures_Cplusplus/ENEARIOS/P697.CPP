#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

struct ENEARIO {
	int Info;
	struct ENEARIO *Hijo;
	struct ENEARIO *Hermano;
};


struct ENEARIO *Construir(int x) {
	struct ENEARIO *t = NULL,*N,*q;
	N = new struct ENEARIO;
	N->Info = x;
	N->Hermano = N->Hijo = NULL;
	for (int i=1; i <= x / 2; i++) {
		if (x % i == 0) {
			q  = Construir (i);
			if (N->Hijo == NULL) {
				N->Hijo = q;
			}
			else {
				t->Hermano = q;
			}
			t = q;
		}
	}
	return N;
}

