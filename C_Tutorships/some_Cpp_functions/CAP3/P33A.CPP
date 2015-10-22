#include "stdio.h"
#include "string.h"
#define PR(x) printf ("%s\n",x)
#include "conio.h"
void main() {
	char *p;
	char a[20];

	a[0] = 18;
	PR("De cadena para probar la funcion");
	cgets (a);
	PR("");
	p = strrchr (a+2,'A');
	if (p == NULL)
		PR("EL caracter no se encuentra en la cadena");
	else {
		printf ("EL ultimo caracter \'A\' ");
		printf ("esta en la posicion %d\n",p - (a+2));
	}
	getch();
}
