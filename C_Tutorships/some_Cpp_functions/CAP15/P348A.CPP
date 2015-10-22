#include "dos.h"
#include "bios.h"
#include "stdio.h"
#include "conio.h"

void interrupt (*f)(...);
void interrupt (*h)(...);

void interrupt g(...);    // Prototipo

void main() {
	int i = 0;
	f = getvect (0x1b);
	setvect (0x1b,g);

	/* Instrucciones del programa.... */

	while (i++ < 20) {
		  h = getvect (0x1b);
		  h();
	}
	setvect (0x1b,f);
	printf ("Terminacion Normal..");
	getch();
}

void interrupt g(...) {
	printf ("Reemplaza a la funcion 0x1b\n");
}