#include "stdio.h"
#include "alloc.h"
#include "string.h"
#include "conio.h"
#include "stdlib.h"
#define PR(x)  printf ("%s\n",x)
#define Localizar (struct Y *) malloc (sizeof (struct Y) )

struct Y {
	double d[100];
	char a[4020];
};

/* coreleft() nos determina el tamano de la memoria dinamica (heap) */

void main() {
	struct Y *p;
	unsigned u;

	u = coreleft();
	printf ("Tamano del heap = %u\n",u);

	p = Localizar;
	if (p == NULL) {
		PR("No existe memoria dinamica..");
		getch();
		exit(1);
	}

	u = coreleft();
	printf ("Tamano del heap = %u\n",u);

	free(p);

	u = coreleft();
	printf ("Tamano del heap = %u\n",u);

	getch();
}
