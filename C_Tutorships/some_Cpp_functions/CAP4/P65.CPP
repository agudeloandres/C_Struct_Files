#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double x,leer_double();
	int n,signo,d,leer_entero();
	char *p;

	x = leer_double(); 		/* Lee un dato de tipo double */
					/* Ver funcion leer_double() */
	d = leer_entero();		/* Lee un dato de tipo entero */
					/* Ver funcion leer_entero() */
	p = ecvt (x,d,&n,&signo);
	printf ("%s %d %d\n",p,n,signo);
	getch();
}


double leer_double() {
	char a[15];

	printf ("Digite un numero de tipo double, sin errores\n");
	printf ("Esta funcion no valida la informacion...\n");
	gets (a);
	return ( atof(a) ); /* Retorna 0.0 en caso de error */
}



int leer_entero () {
	char a[15];

	printf ("Digite un numero de tipo int , sin errores\n");
	printf ("Esta funcion no valida los datos...\n");
	gets (a);
	return ( atoi(a) ); /* Retorna un numero aleatorio en caso de error */
}


