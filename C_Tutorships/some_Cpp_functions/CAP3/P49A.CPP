#include "stdio.h"
#include "string.h"
#include "conio.h"
#define PR(x) printf ("%s\n",x)

char a[] = "LENGUAJE TURBO PASCAL";
char b[] = "TURBO C++";

void main ()  {
	char c[30];

	strncpy (c,a,9);
	c [9] = '\0';   	/* Para marcar final de c[].
				   No copia el '\0', porque no se incluye
				   dentro de los 9 caracteres */
	PR(c);
	strncat (c,b,7);
	c [16] = '\0';		/* Para marcar final de c[]
				   No copia el '\0', porque no se incluye
				   dentro de los 7 caracteres */
	PR(c);
	getch();
}



