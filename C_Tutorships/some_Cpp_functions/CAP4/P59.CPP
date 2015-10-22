#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double x,leer_double();

	x = leer_double();
	printf ("EL numero leido es : %lf\n",x);
	getch();
}

double leer_double() {
	char a[15];

	printf ("Digite un numero de tipo double, sin errores\n");
	printf ("Esta funcion no valida la informacion...\n");
	gets (a);
	return ( atof(a) ); /* Retorna 0.0 en caso de error */
}


