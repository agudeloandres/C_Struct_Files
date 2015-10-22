#include "stdio.h"
#include "dos.h"
#include "conio.h"

int F(void) {
	printf ("Programa cancelado por el usuario\n");
	printf ("Por favor hacer copia del archivo \'archi.txt\'\n");
	printf ("Oprima una tecla...\n");
	getch();
	return (0);  	/* 0 Aborta el programa */

			/* Un valor diferente de cero, reasume la */
			/* La ejecucion del programa */

}


void main() {
	int F(void);
	int i;

	ctrlbrk (F);   		/* Habilita a la funcion F(),
				para ser ejecutada cuando se opriman
				las teclas Ctrl-C */

/* Para salir de este loop, se deben oprimir
				las teclas Ctrl-C */
	for (i=0;;i++) {
		printf ("%3d Ejecutando ciclo infinito...\n",i);
	}

}


