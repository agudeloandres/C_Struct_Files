#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double x,y,residuo;
	char a[15],*p;

	printf ("De el numerador\n");
	gets (a);
	x = strtod (a, &p);
	while (*p != '\0') {			/* Ciclo para validar a[] */
		printf ("%c",7);  		/* Aviso de error */
		printf ("Cifra incorrecta. Favor rectifique...\n");
		gets (a);
		x = strtod (a,&p);
	}
	printf ("De el denominador\n");
	gets (a);
	y = strtod (a, &p);
	while (*p != '\0') {			/* Ciclo para validar a[] */
		printf ("%c",7);  		/* Aviso de error */
		printf ("Cifra incorrecta. Favor rectifique...\n");
		gets (a);
		y = strtod (a,&p);
	}
	residuo = fmod (x,y);
	printf ("El residuo de %lf/%lf = %lf\n",x,y,residuo);
	getch();
}



