#include "bios.h"
#include "stdio.h"
#include "conio.h"

#define PR(x) printf ("%s\n",x)

void main() {   		/* Inicializa la impresora */

	biosprint (1, 0, 0);
	PR("Oprima una tecla");
	getch();
}