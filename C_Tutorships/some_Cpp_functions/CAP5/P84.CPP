#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {              /* Para este ejemplo, usamos la funcion cgets() */
	char a[15],*p,*q;
	double coseno_h, x;

	a[0]=8;
	printf ("De un angulo medido en radianes.....\n");
	cgets (a);
	x = strtod (a+2, &p);
	while (*p != '\0') {
		printf ("Cifra errada. Rectifique... %c\n",7);
		cgets (a);
		x = strtod (a+2,&p);
	}
	printf ("\n");
	coseno_h = cosh (x);
	printf ("Coseno hiperbolico (%lf) = %lf\n",x,coseno_h);
	printf ("Secante hiperbolica (%lf) = %lf\n",x,1.0 / coseno_h);
	getch();
}



