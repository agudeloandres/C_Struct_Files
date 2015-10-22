#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	char a[15],*p,*q;
	long x,y;
	ldiv_t i;

	printf ("De el numerador...\n");
	gets (a);
	x = strtol (a, &p,0);
	while (*p != '\0') {
		printf ("Cifra errada. Favor rectifique... %c\n",7);
		gets (a);
		x = strtol (a,&p,0);
	}
	printf ("De el denominador...\n");
	gets (a);
	y = strtol (a, &p,0);
	while (*p != '\0') {
		printf ("Cifra errada. Favor rectifique... %c\n",7);
		gets (a);
		y = strtol (a,&p,0);
	}
	i = ldiv (x, y); /* Los parametros deben ser long int */
	printf ("Cociente = %ld   Residuo = %ld\n",i.quot, i.rem);
	getch();
}



