#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double x,leer_double();
	int d,leer_entero();
	char a[15],*p;

	x = leer_double();
	d = leer_entero();
	p = gcvt (x,d,a);
	printf ("%s %s\n",p,a);
	getch();
}


int leer_entero () {
	char a[15];

	printf ("Digite un numero de tipo int , sin errores\n");
	printf ("Esta funcion no valida los datos...\n");
	gets (a);
	return ( atoi(a) ); /* Retorna un numero aleatorio en caso de error */
}



double leer_double() {
	char a[15];

	printf ("Digite un numero de tipo double, sin errores\n");
	printf ("Esta funcion no valida la informacion...\n");
	gets (a);
	return ( atof(a) ); /* Retorna 0.0 en caso de error */
}


