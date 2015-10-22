#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double x,y,z;
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
	y = modf (x, &z);
	printf ("Parte entera = %lf    Parte decimal = %lf\n",z,y);
	getch();
}



