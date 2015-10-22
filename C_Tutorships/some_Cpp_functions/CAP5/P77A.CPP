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
	y = cos (x) * cos (x) + sin (x) * sin (x);
	if (y != 1.0)
		printf ("La trigonometria es falsa!\n");
	else printf ("No he descubierto nada. Se cumple a identidad.\n");
	getch();
}



