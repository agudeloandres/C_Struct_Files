#include "stdio.h"
#include "alloc.h"
#include "stdlib.h"
#include "conio.h"
#include "math.h"
#define PR(x)  printf ("%s\n",x)
#define LONY (unsigned long) sizeof (struct Y)
#define LONZ (unsigned long) sizeof (struct Z)
#define LocFar (struct Y far *) farmalloc (LONY)

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

void main() {  		     /*  Se debe correr en model = large */
	struct Y far *q;
	struct Z far *p;

	clrscr();
	randomize();
	q = LocFar;
	if (q == NULL) {
		PR("No existe memoria dinamica lejana..");
		getch();
		exit(1);
	}
	printf ("Valor de q = %p\n",q);
	q->d = exp(1);
	gcvt (q->d,6,q->a);
	p = (struct Z far *) farrealloc (q, LONZ);
	printf ("Valor de p = %p\n",p);
	p->f = asin (1) * 2.0;
	p->i = rand();
	PR ("Valores de p-> (p contenido)");
	printf ("%lf %s %f %d\n",p->d,p->a,p->f,p->i);
	getch();
}
