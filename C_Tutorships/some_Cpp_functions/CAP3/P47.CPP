#include "stdio.h"
#include "string.h"
#define PR(x) printf ("%s\n",x)
#include "conio.h"
void main ()  {
	char a[20],*p,*q,b[20],aux[20];

	PR("De primera cadena");
	gets (a);
	strcpy (aux,a);
	PR("De segunda cadena");
	gets (b);
	p = strncat (a,b,5);
	PR(p);
	PR(a);
	PR("");
	q = strncat (aux,b,10);
	PR(q);
	PR(aux);
	getch();
}



