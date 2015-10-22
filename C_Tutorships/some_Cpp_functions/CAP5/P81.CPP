#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	char a[15],*p,*q;
	long x;
	int i;

	printf ("De un numero entero\n");
	gets (a);
	x = strtol (a, &p,0);
	while (*p != '\0' ||  x < -32768 || x > 32767 ) {
		printf ("Cifra errada. Rectifique... %c\n",7);
		gets (a);
		x = strtol (a,&p,0);
	}
	printf ("\n");
	if ( (int)x == -32768) {
		printf("La funcion abs(), no esta definida ");
	  -	printf ("para este valor\n");
		getch();
	}
	else {
		i = abs ( (int) x);
		printf ("Valor absoluto de %d es %d\n",(int)x,i);
		getch();
	}
}



