#include "stdio.h"
#include "fcntl.h"
#include "conio.h"
#define PRS(x) printf ("%s\n",x)

void main() {
	char c;

	PRS("De caracteres...<R> para terminar.");
	while ( (c=getch()) != 13) 	/* La funcion getch(), no hace eco */
		fputchar (c);           /* Escribe c en el video */
}
