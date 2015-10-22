#include "stdio.h"
#include "alloc.h"
#include "stdlib.h"
#include "math.h"
#include "conio.h"

#define Localizar (struct Y *) malloc (sizeof (struct Y) )

struct Y {
	double d;
	char a[40];
};

struct Z {
	double d;
	char a[40];
	float f;
	int i;
};

void main() {
	void RAM (char *);
	struct Y *q;
	struct Z *p;

	clrscr();
	RAM("Total heap");
	q = Localizar;
	RAM("Antes de realloc()");
	p = (struct Z *) realloc (q, sizeof (struct Z) );
	RAM("Despues de realloc()");
	free(p);
	RAM("Despues de free()");
	getch();
}

void RAM (char *a) {
	unsigned int u;

	u = coreleft();
	printf ("RAM (%s) = %u\n",a,u);
}