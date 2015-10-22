#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double x,y;
	char a[15],*p;

	printf ("De angulo medido en radianes\n");
	gets (a);
	x = strtod (a, &p);
	while (*p != '\0') {			/* Ciclo para validar a[] */
		printf ("%c",7);  		/* Aviso de error */
		printf ("De angulo medido en radianes\n");
		gets (a);
		x = strtod (a,&p);
	}
	/* Dato de tipo double 	correcto */
	y = sin (x);  				/* Calcula seno de x */
	printf ("seno (%10.6lf) = %10.6lf\n",x,y);
	getch();
}



