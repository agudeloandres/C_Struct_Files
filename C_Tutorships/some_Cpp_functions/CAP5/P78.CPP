#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "errno.h"
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
	y = tan (x);
	printf ("Secante (%lf) = (1.0 / tangente (%lf)) = %lf\n",x,x,1.0 / y);
	getch();
}



