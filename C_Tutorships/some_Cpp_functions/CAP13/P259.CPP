#include "stdio.h"
#include "alloc.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"

#define PR(x)  printf ("%s\n",x)
#define LocFar (struct Y far *) farmalloc (sizeof (struct Y) )

struct Y {
	double d[100];
	char a[4020];
};

/* farcoreleft() nos determina el tamano de la memoria dinamica (far heap) */

void main() {          		/* Se debe correr en model = large */
	struct Y far *p;
	void FAR_RAM();
	FAR_RAM();

	p = LocFar;
	if (p == NULL) {
		PR("No existe memoria dinamica lejana..");
		getch();
		exit(1);
	}

	FAR_RAM();

	farfree(p);

	FAR_RAM();

	getch();
}

void FAR_RAM() {
	unsigned long u;

	u = farcoreleft();
	printf ("Tamano del far heap = %lu\n",u);
}
