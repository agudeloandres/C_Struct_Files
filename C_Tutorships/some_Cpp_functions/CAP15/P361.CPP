#include "dos.h"
#include "stdio.h"
#include "conio.h"
#undef pokeb

void main() {
	unsigned seg,desplaza;
	char prueba[10];
	int i;

	printf ("Antes de ejecutar este programa, desactive la tecla CAPS\n");
	printf ("Oprima una tecla...\n");
	getch();

	seg = 0x0040;
	desplaza = 0x0017;
	pokeb (seg, desplaza, 0x40);

	printf ("Escriba una cadena de caracteres\n");
	prueba [0] = 8;
	cgets (prueba);
	printf ("\n");
	printf ("%s\n",prueba+2);
	getch();
}




