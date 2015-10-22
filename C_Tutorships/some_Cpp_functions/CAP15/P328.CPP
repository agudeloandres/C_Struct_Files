#include "dos.h"
#include "errno.h"
#include "conio.h"
#include "stdio.h"
void main() {
	int i;
	void impresora (int *p);

	impresora (&i);
	if ( (i & 0x20) != 0x20)
		printf ("La impresora esta lista...\n");
	else printf ("Favor colocar papel a la impresora...\n");
	getch();
}


void impresora (int *p) {
	union REGS r;

	r.h.ah = 0;
	r.h.al = 0;
	r.x.dx = 0;
	r.x.cflag = 0;
	int86 (0x17, &r, &r);
	*p = r.h.ah;
}

