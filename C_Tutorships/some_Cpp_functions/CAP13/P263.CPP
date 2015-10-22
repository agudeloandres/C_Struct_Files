#include "stdio.h"
#include "alloc.h"
#include "stdlib.h"
#include "conio.h"
#include "math.h"
#define LocFar (struct Y far *) malloc (sizeof (struct Y) )

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

void main() {                      /* Se debe correr en model = large */
	struct Y far *q;
	struct Z far *p;
	void RAM (char *);
	clrscr();
	RAM("Total far heap");
	q = LocFar;
	RAM("Antes de farrealloc()");
	p = (struct Z far *) realloc (q, sizeof (struct Z) );
	RAM("Despues de far realloc()");
	farfree(p);
	RAM("Despues de farfree()");
	getch();
}

void RAM (char *a) {
	unsigned long u;

	u = farcoreleft();
	printf ("RAM (%s) = %lu\n",a,u);
}