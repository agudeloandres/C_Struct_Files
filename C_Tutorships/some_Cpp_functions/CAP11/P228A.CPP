#include "stdio.h"
#include "dir.h"
#include "dos.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

#define PRS(x)  printf ("%s",x)
#define SALTO  printf ("\n")

void main() {
	char b[100],*q;

	strcpy (b,"c:\\turboc");
	if (chdir (b) == -1) {
		q = _strerror ("Error en chdir()");
		PRS(q);
		getch(); exit (1);
	}
	strcpy (b,"a:\\prueba");
	if (chdir (b) == -1) {
		q = _strerror ("Error en chdir()");
		PRS(q);
		getch(); exit (1);
	}
	PRS("Oprima una tecla ");
	getch();
}


