#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	char a[15],*p;
	double x,y,log2;

	printf ("Calcula el log(x) en base 2\n");
	printf ("Digite un numero de tipo double\n");
	gets (a);
	x = strtod (a, &p);
	while (*p != '\0') {
		printf ("Cifra errada. Rectifique... %c\n",7);
		gets (a);
		x = strtod (a,&p);
	}
	y = fabs (x); /* y = valor absoluto de x */
	log2 = log (y) / log (2);
	printf ("log en base 2 de (%lf) = %lf\n",y,log2);
	getch();
}



