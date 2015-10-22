#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double x,R;
        long i;
	char a[15],*p;

	a[0] = 13;
	printf ("De un dato de tipo double\n");
	cgets (a);
	x = strtod (a+2, &p);
	while (*p != '\0' || a <= 0) {
		printf ("%c",7);  		/* Aviso de error */
		printf ("Cifra incorrecta. Favor rectifique...\n");
		cgets (a);
		x = strtod (a+2,&p);
	}
	printf ("\n");
	printf ("De un dato de tipo entero\n");
	cgets (a);
	i = strtol (a+2, &p, 10);
	while (*p != '\0' || i < -32768 || i > 32767) {
		printf ("%c",7);  		/* Aviso de error */
		printf ("Cifra incorrecta. Favor rectifique...\n");
		cgets (a);
		i = strtol (a+2,&p, 10);
	}
	printf ("\n");
	R = ldexp (x,(int)i);
	printf ("R = %30.15lf\n",R);
	getch();
}



