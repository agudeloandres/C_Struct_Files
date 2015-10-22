#include "stdio.h"
#include "dir.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x)  printf ("%s",x)
#define SALTO  printf ("\n");

/* En este programa, el nombre del directorio a crear, se informa
	a traves de una linea de comandos.  */

void main(int argc, char *argv[]) {
	char *p;

	if (argc != 2) {
		PRS ("Linea de comandos errada..");
		getch(); exit (1);
	}
	PRS("Directorio a crear: ");
	PRS(argv [1]);
	SALTO;
	if (mkdir (argv [1]) == -1) {
		p = _strerror ("Error en mkdir");
		PRS(p);
		getch(); exit (1);
	}
	getch();
}
