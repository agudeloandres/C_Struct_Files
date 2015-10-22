#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

// Posorden() Recursivo
void Posorden(struct ENEARIO *p) {
	struct ENEARIO *q;
	if (p!= NULL) {
		q = p->Hijo;
		while (q != NULL) {
			Posorden(q);
			q = q->Hermano;
		}
		printf ("%d ",p->Info);
	}
}

