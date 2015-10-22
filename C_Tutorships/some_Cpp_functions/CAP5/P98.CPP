#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double a,b,h;
	char a1[15],*p;

	a1[0] = 13;
	printf ("De el valor del primer cateto\n");
	cgets (a1);
	a = strtod (a1+2, &p);
	while (*p != '\0' || a <= 0) {
		printf ("%c",7);  		/* Aviso de error */
		printf ("Cifra incorrecta. Favor rectifique...\n");
		cgets (a1);
		a = strtod (a1+2,&p);
	}
	printf ("\n");
	printf ("De el valor del segundo cateto\n");
	cgets (a1);
	b = strtod (a1+2, &p);
	while (*p != '\0' || b <= 0) {
		printf ("%c",7);  		/* Aviso de error */
		printf ("Cifra incorrecta. Favor rectifique...\n");
		cgets (a1);
		b = strtod (a1+2,&p);
	}
	printf ("\n");
	h = hypot (a,b);
	printf ("Hipotenusa = %lf\n",h);
	getch();
}



