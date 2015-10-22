#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double x,y,R;
	char a[15],*p;

	printf ("De la longitud de los catetos del triangulo\n");
	printf ("Primer cateto\n");
	gets (a);
	x = strtod (a, &p);
	while (*p != '\0') {			/* Ciclo para validar a[] */
		printf ("%c",7);  		/* Aviso de error */
		gets (a);
		x = strtod (a,&p);
	}
	/* Dato de tipo double 	correcto */
	printf ("Segundo cateto\n");
	gets (a);
	y = strtod (a, &p);
	while (*p != '\0') {			/* Ciclo para validar a[] */
		printf ("%c",7);  		/* Aviso de error */
		gets (a);
		y = strtod (a,&p);
	}
	/* Dato de tipo double 	correcto */
	R =  atan2 (y, x) + atan2 (x, y); /* La respuesta siempre es pi/2 */
	printf ("%lf\n",R);
	getch();
}



