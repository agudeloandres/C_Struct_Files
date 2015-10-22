#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	char a[15],*p,*q;
	long x;
	int i;
	double R;

	printf ("De un numero entero\n");
	gets (a);
	x = strtol (a, &p,0);
	while (*p != '\0' ||  x < -32768 || x > 32767 ) {
		printf ("Cifra errada. Rectifique... %c\n",7);
		gets (a);
		x = strtol (a,&p,0);
	}
	printf ("\n");
	i = x;		/* Convierte un long a un int  */
			/* La funcion exige la potencia de tipo int */
	R = pow10 (i);
	printf ("10 elevado a la %d es: %lf\n",i,R);
	getch();
}



