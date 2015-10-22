#include "dos.h"
#include "conio.h"

void main () {

	void i_cadena(char *cad) ;
	void i_cadena1(char *cad) ;
	void vaya (int columna, int fila) ;
	void borre_pantalla() ;

	borre_pantalla();		/* geninterrupt() */
	vaya (10,10);
	i_cadena ("Computador e impresora$"); /* intdosx() */
	vaya (10,11);
	i_cadena1("Computador e impresora$"); /* intr() */
	getch();
}

void i_cadena(char *cad) {
	union REGS r;
	struct SREGS s;

	r.h.ah = 0x9;
	s.ds = FP_SEG (cad);
	r.x.dx = FP_OFF (cad);
	intdosx (&r, &r, &s);
}
void i_cadena1(char *cad) {
	struct REGPACK r;

	r.r_ax = 0x0900;
	r.r_ds = FP_SEG (cad);
	r.r_dx = FP_OFF (cad);
	intr (0x21, &r);
}


void vaya (int columna, int fila) {
	_AH = 2;
	_DH = fila;	/* 0-24 */
	_DL = columna;	/* 0-79 */
	_BH = 0;
	geninterrupt (0x10);
}


void borre_pantalla() {
	_AH = 0x6;
	_AL = 0;

	/* Tamano de la ventana */

	_CH = 0;
	_DH = 24;
	_CL = 0;
	_DL = 79;

	_BH = 0x70;	/* Borra en invertido */
	geninterrupt (0x10);
}
