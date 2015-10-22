#include "dos.h"
#include "conio.h"
#undef poke

void main() {
	unsigned seg,desplaza;
	int i;

	seg = 0xb000;			/* Donde inicia memoria de video */
					/* para un video monocromo */

	desplaza = 0x0 + 10;		/* Desplazamiento de 10 posiciones */

	poke (seg, desplaza, 0x7041);   /* Se escribe el caracter 'A', en */
					/* invertido */
	getch();
}




