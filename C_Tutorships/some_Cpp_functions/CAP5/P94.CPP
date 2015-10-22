#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	char a[15],*p,*q;
	long x,y;
	div_t i;

	printf ("De el numerador...\n");
	gets (a);
	x = strtol (a, &p,0);
	while (*p != '\0' ||  x < -32768 || x > 32767 ) {
		printf ("Cifra errada. Favor rectifique... %c\n",7);
		gets (a);
		x = strtol (a,&p,0);
	}
	printf ("De el denominador...\n");
	gets (a);
	y = strtol (a, &p,0);
	while (*p != '\0' ||  x < -32768 || x > 32767 ) {
		printf ("Cifra errada. Favor rectifique... %c\n",7);
		gets (a);
		y = strtol (a,&p,0);
	}
	i = div ( (int)x, (int)y ); /* Los parametros deben ser enteros */
	printf ("Cociente = %d   Residuo = %d\n",i.quot, i.rem);
	getch();
}



