#include "dos.h"
#include "errno.h"
#include "conio.h"
#include "stdio.h"

void main() {
	int i,j;
	void lea_c (int *p, int *q);
	textattr (0x70);  	/* Invertido */
	gotoxy(1,2);
	cprintf ("Alfa y Beta");
	textattr (0xf);		/* Normal */
	gotoxy (2,2);
	lea_c (&i,&j);
	textattr (j);
	gotoxy (10,10);
	cprintf ("%c",i);
	getch();
}

void lea_c (int *p, int *q) {
	union REGS r;

	r.h.ah = 8;
	r.h.bh = 0;
	int86 (0x10, &r, &r);
	*p = r.h.al;   	/* Caracter */
	*q = r.h.ah;	/* Atributo */
}

