#include "dos.h"
#include "stdio.h"
#include "conio.h"

void main() {
	unsigned int far *p;
	unsigned int seg,des;
	char *s = "Una cadena en memoria";

	/* Primer ejemplo */

	p = (unsigned int *)MK_FP (0xb000,0);
	printf ("p = %Fp\n",p);
	seg = FP_SEG (p);
	des = FP_OFF (p);
	printf ("Seg:Des = %X:%X\n",seg,des);

	/* Segundo ejemplo */

	seg = FP_SEG (s);
	des = FP_OFF (s);
	printf ("La cadena \'%s\' esta almacenada en:\n",s);
	printf ("Segmento  %X  Desplazamiento %X\n",seg,des);

	getch();
}