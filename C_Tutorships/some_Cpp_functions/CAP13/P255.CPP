#include "stdio.h"
#include "alloc.h"
#include "stdlib.h"
#include "math.h"
#include "conio.h"

#define PR(x)  printf ("%s\n",x)
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

void main() {    		/* Se debe correr en model = large  */
	struct Y *q;
	struct Z *p;

	clrscr();
	randomize();
	q = Localizar;
	if (q == NULL) {
		PR("No existe memoria dinamica..");
		getch();
		exit(1);
	}
	printf ("Valor de q = %p\n",q);
	q->d = exp(1);
	gcvt (q->d,6,q->a);  /* Convierte e, a cadena */
	PR ("Valores de q-> (q contenido)");
	printf ("%lf %s\n",q->d,q->a);
	p = (struct Z *) realloc (q, sizeof (struct Z) );
	printf ("Valor de p = %p\n",p);
	p->f = asin (1) * 2.0;
	p->i = rand();
	PR ("Valores de p-> (p contenido)");
	printf ("%lf %s %f %d\n",p->d,p->a,p->f,p->i);
	getch();
}
