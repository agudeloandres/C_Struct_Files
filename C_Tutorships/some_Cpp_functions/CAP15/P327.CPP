#include "dos.h"
#include "conio.h"

void main() {
	void apagar_c ();
	apagar_c();
	getch();																												 getch();
}

void apagar_c() {
	union REGS  r,r1;

	r.h.ah = 1;
	r.h.ch = 1;   // Inicia linea
	r.h.cl = 0;   // Finaliza linea
	int86 (0x10, &r, &r1);
	// El curso queda apagado porque la linea inicial es mayor
	// que la linea final
}