#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

int Piramide(struct ENEARIO *p) {
	struct ENEARIO *q;
	int s=0,u;
	if (p == NULL)
		return -2;
	q = p->Hijo;
	while (q != NULL) {
		s = s + q->Info;
		u = Piramide(q);
		if (u == -1)
			return -1;
		q = q->Hermano;
	}
	if (p->Info == s || s == 0)
		return 1;
	return -1;
}


