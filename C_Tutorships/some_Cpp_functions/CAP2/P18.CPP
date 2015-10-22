#include "stdio.h"
#include "ctype.h"
#include "conio.h"
void main()  {
	int c;
	printf ("Oprima un caracter..\n");
	c = getch();
	if (isalpha (c))
		printf ("Es alfabetico\n");
	else printf ("No es un caracter alfabetico\n");
	getch();
}



