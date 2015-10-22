#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	char a[15],*p;
	int i,base,leer_entero();

	i = leer_entero(); 	/* Lee cualquier entero */
	base = 10;  		/* La base debe estar entre 2-36 */
	p = itoa (i,a,base);
	printf ("%s %s\n",a,p);
	getch();
}


int leer_entero () {
	char a[15];

	printf ("Digite un numero de tipo int , sin errores\n");
	printf ("Esta funcion no valida los datos...\n");
	gets (a);
	return ( atoi(a) ); /* Retorna un numero aleatorio en caso de error */
}



