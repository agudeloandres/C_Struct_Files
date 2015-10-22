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

int Gordura(struct ENEARIO *p) {
	int MasGordo=-1;
	struct FIFO *Cola;
	struct ENEARIO *s;
	struct ENEARIO *q;
	int i=0,Ant=-1,Cont=1;

	InitCola (&Cola);
	InsCola (&Cola,p,1);
	while (!ColaVacia(Cola)) {
		q = RetCola(&Cola,&i);
		if (i != Ant) {
			if (MasGordo < Cont)
				MasGordo = Cont;
			Cont = 0;
			Ant = i;
			printf ("\n");
		}
		Cont++;
		s = q->Hijo;
		while (s != NULL) {
			InsCola(&Cola,s,i+1);
			s = s->Hermano;
		}
	}
	return (MasGordo < Cont) ? Cont : MasGordo;
}

