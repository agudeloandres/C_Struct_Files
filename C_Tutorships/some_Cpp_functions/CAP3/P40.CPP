#include "stdio.h"
#include "string.h"
#define PR(x) printf ("%s\n",x)
#include "conio.h"
#include "alloc.h"
char *a[] = {
	"uno",
	"dos",
	"tres",
	"cuatro"
};

void main()  {
	char *b[4];
	unsigned char i;

	for (i=0; i < 4; i++)    /* Duplica todas las cadenas */
		b[i] = strdup (a[i]);

	for (i=0; i < 4; i++)    /* Escribe todas las cadenas */
		PR(b[i]);
	for (i=0; i < 4; i++)    /* LIBERA todas las cadenas */
		free(b[i]);

	getch();

}



