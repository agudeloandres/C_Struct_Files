#include "stdio.h"
#include "ctype.h"
#include "conio.h"
void main()  {
	int c;

	c = getch();
	if (isdigit (c))
		printf ("Es un caracter numerico\n");
	else printf ("No es un caracter numerico\n");
	getch();
}



