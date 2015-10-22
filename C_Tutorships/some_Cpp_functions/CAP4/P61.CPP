#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	long x,leer_long();

	x = leer_long();
	printf ("EL numero leido es : %ld\n",x);
	getch();
}

long leer_long() {
	char a[15];

	printf ("Digite un numero de tipo long, sin errores\n");
	printf ("Esta funcion no valida los datos informacion...\n");
	gets (a);
	return ( atol(a) ); /* Retorna un numero aleatorio en caso de error */
}


