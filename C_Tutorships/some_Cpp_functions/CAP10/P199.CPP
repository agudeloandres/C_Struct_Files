#include "stdio.h"
#include "fcntl.h"
#define PRS(x) printf ("%s\n",x)
#include "conio.h"
#include "stdlib.h"
void main() {
	FILE *p;
	char c;


	if ( (p = fopen ("prueba","w") ) == NULL) {
		PRS ("Error en apertura\n");
		getch(); exit(1);
	}

	PRS("De caracteres...<R> para terminar.");
	while ( (c=getche()) != 13)
		fputc (c,p);

	if (fclose (p) == EOF) {
		PRS("Error al cerrar el archivo");
		getch(); exit (1);
	}
}
