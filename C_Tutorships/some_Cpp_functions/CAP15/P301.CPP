#include "bios.h"
#include "stdio.h"
#include "conio.h"

#define PR(x) printf ("%s\n",x)

void main() {   		/* Analiza stado de la impresora */
	int i;

	clrscr();
	i = biosprint (2, 0, 0);
	if ( (i & 0x80) == 0x80) PR("Unidad Libre");
	if ( (i & 0x40) == 0x40) PR("Unidad Reconocida");
	if ( (i & 0x20) == 0x20) PR("Impresora sin papel");
	if ( (i & 0x10) == 0x10) PR("Unidad Seleccionada");
	if ( (i & 0x08) == 0x08) PR("Error en unidad");
	if ( (i & 0x01) == 0x01) PR("Unidad Desconectada");
	getch();
}