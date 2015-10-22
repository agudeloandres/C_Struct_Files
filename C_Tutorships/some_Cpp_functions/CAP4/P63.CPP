#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	char a[20],*p;
	long i,leer_long ();
	int base;

	i = leer_long(); 	/* Lee cualquier long int */
	base = 18;  		/* La base debe estar entre 2-36 */
	p = ltoa (i,a,base);
	printf ("%ld %s %s\n",i,a,p);
	getch();
}


long leer_long() {
	char a[15];

	printf ("Digite un numero de tipo long, sin errores\n");
	printf ("Esta funcion no valida los datos informacion...\n");
	gets (a);
	return ( atol(a) ); /* Retorna un numero aleatorio en caso de error */
}




