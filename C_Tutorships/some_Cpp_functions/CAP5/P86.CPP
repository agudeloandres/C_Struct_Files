#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {  /* Para este ejemplo, usamos la funcion cgets() */
	char a[20],*p;
	double seno_h,x,y;

	a[0]=18;
	printf ("De un angulo medido en radianes.....\n");
	cgets (a);
	x = strtod (a+2, &p);
	while (*p != '\0') {
		printf ("Cifra errada. Rectifique... %c\n",7);
		cgets (a);
		x = strtod (a+2,&p);
	}
	printf ("\nFORMULA: Seno hiperbolico (x) = (e ^ x - e ^(-x) ) / 2\n");
	seno_h = (exp (x) - exp (-x)) / 2.0;
	printf ("Seno hiperbolico (%lf) = %lf\n",x,seno_h);
	getch();
}



