// *******************************************************************
// Este programa genera errores. El programa correcto es el p350.cpp
// *******************************************************************

#include "stdio.h"
#include "conio.h"
#include "io.h"
#include "dos.h"

/* PRUEBE ESTE PROGRAMA CON UN DISCO PROTEGIDO O SIN DISCO EN LA UNIDAD A: */

void main() {
	int id,i;
	char buffer[] = "Computadores e impresoras ";

	harderr (IO_errores);
	id = _creat("a:prueba",32);
	_write (id,(char *)buffer,10);
	_close (id);
	printf ("Oprima una tecla...\n");
	getch();
}
