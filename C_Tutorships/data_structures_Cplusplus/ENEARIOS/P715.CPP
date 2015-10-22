#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
	struct FIFO {
			struct ENEARIO *Info;
			struct FIFO *Sig;
			int Nivel;
	};

	void InitCola (struct FIFO **p) {
		*p = new FIFO;
		(*p)->Sig = *p;
	}

	int ColaVacia(struct FIFO *p) {
		return p == p->Sig;
	}

	void InsCola (struct FIFO **p, struct ENEARIO *pp,int n) {
		struct FIFO *q =  new struct FIFO;
		q->Info = pp;
		q->Nivel = n;
		q->Sig = (*p)->Sig;
		(*p)->Sig = q;
		(*p) = q;
	}

	struct ENEARIO *RetCola (struct FIFO **p,int *pp) {
		struct FIFO *q,*r;
		struct ENEARIO *Temp;
		if (!ColaVacia(*p)) {
			q = (*p)->Sig;
			r = q->Sig;
			Temp = r->Info;
			*pp = r->Nivel;
			q->Sig = r->Sig;
			if (r == *p)
				*p = q;
			delete r;
			return Temp;
		}
		else {
			printf ("Error...\n");
			return 0;
		}
	}

void Niveles (struct ENEARIO *p) {
	struct FIFO *Cola;
	struct ENEARIO *s;
	struct ENEARIO *q;
	int i=0,Ant=-1;

	InitCola(&Cola);
	InsCola (&Cola,p,1);
	while (!ColaVacia(Cola)) {
		q = RetCola(&Cola,&i);
		if (i != Ant) {
			Ant = i;
			printf ("\n");
		}
		printf ("%d ",q->Info);
		s = q->Hijo;
		while (s != NULL) {
			InsCola(&Cola,s,i+1);
			s = s->Hermano;
		}

	}

}

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

