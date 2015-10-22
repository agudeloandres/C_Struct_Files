#include "stdio.h"
#include "conio.h"

void main()
{
	char a[10],b[10];

	printf ("\n");
	printf ("De cadena\n");
	gets (a);
	printf ("De cadena\n");
	b[0] = 5; 	/*  Maximo 5 caracteres, incluyendo NULL */
	cgets (b);
	cputs (a); 	/* Leido con gets() */
	printf ("\n");
	cputs (b+2); 	/* Leido con cgets() */
	printf ("\n");
	cputs ("Por favor oprima una tecla, para terminar...");
	getch();
}