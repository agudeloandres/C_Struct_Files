#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	char a[15],*p;
	double valor,x,y;

	printf ("Vamos a elevar x a la y, utilizando log() y exp()\n");
	printf ("Digite un numero x.\n");
	gets (a);
	x = strtod (a, &p);
	while (*p != '\0') {
		printf ("Cifra errada. Rectifique... %c\n",7);
		gets (a);
		x = strtod (a,&p);
	}
	printf ("Digite un numero y.\n");
	gets (a);
	y  = strtod (a, &p);
	while (*p != '\0') {
		printf ("Cifra errada. Rectifique... %c\n",7);
		gets (a);
		y = strtod (a,&p);
	}
	valor = exp (y * log (x));
	printf ("%lf elevado a la %lf es igual a %lf\n",x,y,valor);
	getch();
}



