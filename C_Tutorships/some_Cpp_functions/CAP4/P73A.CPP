#include "stdio.h"
#include "ctype.h"
#include "conio.h"
void main() {
	int i,c;

	c = getch();
	if (c >= 'a' && c <= 'z')
		i = _toupper (c);
	else {
		printf ("No se puede utilizar la funcion\n");
		i = _toupper (c);  /* Uso incorrecto */
		printf ("Produce resultado incorrecto\n");
	}
	printf ("%c %c\n",c,i);
	getch();
}
