#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "stdlib.h"  // Prototipo de atoi()
#define PR(x) printf ("%s\n",x)

void main ()  {
	char a[40],b[40];
	int n,leer_entero(),i,j,k;

	a[0] = 38;
	b[0] = 38;
	PR("De primer cadena: a[]\n");
	cgets(a);
	PR("");
	PR("De segunda cadena: b[]\n");
	cgets(b);
	PR("");
	PR("Cuantos caracteres desea comparar?");
	n = leer_entero();
	i = strncmp (a+2,b+2,n);
	j = strcmp(a+2,b+2);
	n = 30;
	k = strncmp (a+2,b+2,n);
	printf ("%d %d %d\n",i,j,k);
	getch();
}


int leer_entero () {
	char a[15];

	gets (a);
	return ( atoi(a) ); /* Retorna un numero aleatorio en caso de error */
}



