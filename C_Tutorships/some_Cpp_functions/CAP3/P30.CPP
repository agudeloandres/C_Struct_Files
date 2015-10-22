#include "stdio.h"
#include "string.h"
#define PR(x) printf ("%s\n",x)
#include "conio.h"
void main ()  {
	char a[40],b[40];

	a[0] = 38;
	b[0] = 38;
	printf ("De primer cadena: a[]\n");
	cgets(a);
	printf("\n");
	printf ("De segunda cadena: b[]\n");
	cgets(b);
	printf("\n");
	if (strcmp (a+2,b+2) > 0)
		PR("La cadena a[] es mayor que la cadena b[]");
	else if (strcmp (a+2,b+2) < 0)
		PR("La cadena a[] es menor que la cadena b[]");
	else PR("La cadena a[] es igual a la cadena b[]");
	getch();
}
