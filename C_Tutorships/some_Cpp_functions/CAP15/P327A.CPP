#include "dos.h"
#include "conio.h"
void main() {
	void apagar_c ();
	apagar_c ();
	getch();
}

void apagar_c() {
	union REGS  r;

	r.h.ah = 1;
	r.h.ch = 4;
	r.h.cl = 3;
	int86 (0x10, &r, &r);
	// en ch esta el inicio de la linea
	// en cl esta el fin de la linea
	// si ch > cl se apaga el cursor, de lo contrario se prende
}