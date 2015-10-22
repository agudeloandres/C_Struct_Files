#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double x,m;
	int n;
	char a[15],*p;

	a[0] = 13;
	printf ("De un numero de tipo double\n");
	cgets (a);
	x = strtod (a+2, &p);
	while (*p != '\0') {			/* Ciclo para validar a[] */
		printf ("%c",7);  		/* Aviso de error */
		printf ("Cifra incorrecta. Favor rectifique...\n");
		cgets (a);
		x = strtod (a+2,&p);
	}
	printf ("\n");
	m = frexp (x, &n);
	printf ("%lf = %lf * 2^%d\n",x,m,n);
	getch();
}



