#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	char a[15],*p;
	double x,y;

	printf ("Digite un numero de tipo double\n");
	gets (a);
	x = strtod (a, &p);
	while (*p != '\0') {
		printf ("Cifra errada. Rectifique... %c\n",7);
		gets (a);
		x = strtod (a,&p);
	}
	y = ceil (x);/* y=al menor entero >= al valor almacenado en x */
	printf ("%lf aproximado hacia arriba al proximo entero = %lf\n",x,y);
	getch();
}



