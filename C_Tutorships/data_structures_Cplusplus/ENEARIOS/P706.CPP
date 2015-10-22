#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

void Inorden(struct ENEARIO *p) {
	struct ENEARIO *q;
	if (p != NULL) {
		q = p->Hijo;
		if (q == NULL)
			printf ("%d\n",p->Info);
		else {
			Inorden(q);
			printf ("%d\n",p->Info);
			q = q->Hermano;
			while (q != NULL) {
				Inorden (q);
				q = q->Hermano;
			}
		}
	}
}


