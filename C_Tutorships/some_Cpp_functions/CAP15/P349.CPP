#include "dos.h"
#include "stdio.h"
#include "conio.h"

// *******************************************
// Los programas que trabajan el vector de interrupciones,
// se deben compilar sin la opcion test stack overflow
// activa (Alt-O-C-E)
// Ejecute este programa desde el ambiente DOS.
// *******************************************

void interrupt (*f)(...);
void interrupt g(...);

void interrupt g(...) {
	printf ("Reemplaza el vector\n");
}


int main() {
	f = getvect (0x5);
	setvect (0x5,g);
	printf ("Oprima una tecla\n");
	getch();
	printf ("Termina Normalmente\n");
	setvect (0x5,f);
	return 0;
}


