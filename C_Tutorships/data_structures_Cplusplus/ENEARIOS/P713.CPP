#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

	struct LIFO {
		struct ENEARIO *Info;
		struct LIFO *Sig;
	};

	void InitPila (struct LIFO **p) {
		*p = NULL;
	}

	int PilaVacia(struct LIFO *p) { return p == NULL; }

	void InsPila (struct LIFO **p,struct ENEARIO *pp) {
		struct LIFO *q =  new struct LIFO;
		q->Info = pp;
		q->Sig = *p;
		*p = q;
	}

	struct ENEARIO *RetPila (struct LIFO **p) {
		if (!PilaVacia(*p)) {
			struct ENEARIO *Temp = (*p)->Info;
			struct LIFO *q = *p;
			*p = (*p)->Sig;
			delete q;
			return Temp;
		}
		else {
			printf ("Error...\n");
			return NULL;
		}
	}



struct ENEARIO {
	int Info;
	struct ENEARIO *Hijo;
	struct ENEARIO *Hermano;
};

void Posorden(struct ENEARIO *p) {
	struct LIFO *p1;
	struct ENEARIO *q;
	InitPila(&p1);
	while (p != NULL) {
		InsPila(&p1,p);
		p = p->Hijo;
	}
	while (!PilaVacia(p1)) {
		q = RetPila(&p1);
		printf ("%d ",q->Info);
		q = q->Hermano;
		while (q != NULL) {
			InsPila (&p1,q);
			q = q->Hijo;
		}
	}
}


