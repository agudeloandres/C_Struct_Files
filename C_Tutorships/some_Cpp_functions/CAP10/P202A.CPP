#include "stdio.h"
#include "fcntl.h"
#include "conio.h"
#include "stdlib.h"
#define PRS(x) printf ("%s\n",x)


void main() {
	FILE *p;
	int c;

	if ( (p = fopen ("prueba","r") ) == NULL) {
		PRS ("Error en apertura\n");
		getch(); exit(1);
	}
	c = fgetc(p);
	while (!feof (p) ) {   /* Chequea el final de archivo */
		printf ("%c",c);
                c = fgetc (p);
	}
	fclose (p);
	getch();
}
