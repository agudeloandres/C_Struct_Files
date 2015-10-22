#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

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
void Preorden (struct ENEARIO *p) {
	struct ENEARIO *q;
	if (p != NULL) {
		printf ("%d ",p->Info);
		q = p->Hijo;
		if (q == NULL)
			; // Ninguna Instruccion
		else {
			Preorden(q);
			q = q->Hermano;
			while (q != NULL) {
				Preorden (q);
				q = q->Hermano;
			}
		}
	}
}

