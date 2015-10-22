#include "stdio.h"
#include "conio.h"
#include "stdlib.h"


struct ENEARIO {
	int Info;
	struct ENEARIO *Hijo;
	struct ENEARIO *Hermano;
};

struct ENEARIO *Construir(struct ENEARIO *s,int h) {
	struct ENEARIO *Temp = NULL,*p,*q;
	char Aux[10];
	p = new struct ENEARIO;
	if(s == NULL)
		printf ("De la informacion del nodo raiz\n");
	else printf ("De la informacion del hijo %d del nodo %d\n",h,s->Info);
	gets (Aux);
	p->Info = atoi(Aux);
	p->Hermano = p->Hijo = NULL;
	printf ("De el numero de hijos del nodo %d\n",p->Info);
	gets (Aux);
	int NHijos = atoi(Aux);

	for (int i=1; i <= NHijos; i++) {
			q  = Construir (p,i);
			if (p->Hijo == NULL)
				p->Hijo = q;
			if (Temp == NULL)
				Temp = q;
			else {
				Temp->Hermano = q;
				Temp = q;
			}
	}
	return p;
}
/*
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

*/

int Hojas(struct ENEARIO *p) {
	struct ENEARIO *q;
	int Acum;
	if (p == NULL)
		return 0;
	else {
		q = p->Hijo;
		if (q == NULL)
			return 1;
		else {
			Acum = 0;
			while (q != 0) {
				Acum = Acum + Hojas(q);
				q = q->Hermano;
			}
			return Acum;
		}
	}
}

