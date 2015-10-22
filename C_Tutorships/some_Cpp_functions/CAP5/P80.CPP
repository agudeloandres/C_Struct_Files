#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double x,y;
	char a[15],*p;

	printf ("De tangente de un angulo medido en radianes\n");
	gets (a);
	x = strtod (a, &p);
	while (*p != '\0') {			/* Ciclo para validar a[] */
		printf ("%c",7);  		/* Aviso de error */
		printf ("De tangente de un angulo medido en radianes\n");
		gets (a);
		x = strtod (a,&p);
	}
	/* Dato de tipo double 	correcto */
	y = 1.570796327 - atan (x);
	if (errno == EDOM)
		printf ("El angulo no esta en el dominio de la funcion\n");
	else printf ("Arcocotangente de x es : %lf\n",y);
	getch();
}



