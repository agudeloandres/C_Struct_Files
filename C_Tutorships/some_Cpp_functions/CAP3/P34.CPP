#include "stdio.h"
#include "string.h"
#define PR(x) printf ("%s\n",x)
#include "conio.h"
void main ()  {
	char a[30];

	PR("De cadena para probar la funcion");
	gets (a);
	strrev (a);
	PR("Cadena invertida");
	PR(a);
	getch();
}
