#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	char a[15],*p,*q;
	long x,n;
	unsigned int i,R;

	printf ("De un numero unsigned int..\n");
	gets (a);
	x = strtol (a, &p,0);
	while (*p != '\0' ||  x < 0L || x > 65535L) {
		printf ("Cifra errada. Rectifique... %c\n",7);
		gets (a);
		x = strtol (a,&p,0);
	}
	printf ("\n");
	printf ("De el numero de veces que desea rotar la cifra\n");
	gets (a);
	n = strtol (a, &p,0);
	while (*p != '\0' ||  n < -32768L || n > 32767L) {
		printf ("Cifra errada. Rectifique... %c\n",7);
		gets (a);
		n = strtol (a,&p,0);
	}
	printf ("\n");
	i = x;		   /* Convierte un long a un unsigned int  */
	R = _rotl (i, (int)n);  /* Rota i n veces hacia la izquierda */
	printf ("%#X, rotado %d vez(ces) hacia",i, (int)n);
	printf (" la izquierda es : %#X\n",R);
	getch();
}



