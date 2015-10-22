#include "dos.h"
#include "conio.h"

void main() {
	void vaya(int,int);
	vaya (20,10);
	getch();
}

void vaya (int columna, int fila) {
	_AH = 2;
	_DH = fila;	/* 0-24 */
	_DL = columna;	/* 0-79 */
	_BH = 0;
	geninterrupt (0x10);
}
