#include "stdio.h"
#include "ctype.h"
#include "conio.h"
#include "stdlib.h"
void main() {
	int x,leer_entero();

	x = leer_entero();
	printf ("%d\n",toascii(x));
	getch();
}

int leer_entero () {
	char a[15];

	printf ("Digite un numero de tipo int , sin errores\n");
	printf ("Esta funcion no valida los datos...\n");
	gets (a);
	return ( atoi(a) ); /* Retorna un numero aleatorio en caso de error */
}





