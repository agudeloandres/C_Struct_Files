#include "bios.h"
#include "conio.h"
#include "stdio.h"
#define PR(x) printf ("%s\n",x)

void main() {
	int i;

	while (bioskey (1) != 0)  /* Desocupa el buffer del teclado */
		bioskey (0);
	i = bioskey (2);
	if ( (i & 0x80) == 0x80) PR("Insert Prendido");
	if ( (i & 0x40) == 0x40) PR("Caps Prendido");
	if ( (i & 0x20) == 0x20) PR("Num Lock Prendido");
	if ( (i & 0x10) == 0x10) PR("Scroll Lock Prendido");
	if ( (i & 0x08) == 0x08) PR("Alt Oprimido");
	if ( (i & 0x04) == 0x04) PR("Ctrl Oprimido");
	if ( (i & 0x02) == 0x02) PR("Shift Left Oprimido");
	if ( (i & 0x01) == 0x01) PR("Shift Right Oprimido");
	getch();
}