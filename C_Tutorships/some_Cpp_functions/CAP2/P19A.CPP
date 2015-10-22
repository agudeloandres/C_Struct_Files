#include "stdio.h"
#include "ctype.h"
#include "conio.h"
void main()  {
	int c;

	c = getch();
	if (isalnum (c))
		printf ("Es un caracter alfanumerico\n");
	else printf ("No es un caracter alfanumerico\n");
	getch();
}



