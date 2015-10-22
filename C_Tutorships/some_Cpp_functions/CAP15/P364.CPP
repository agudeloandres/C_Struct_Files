#include "dos.h"
#include "stdio.h"
#include "conio.h"

void main() {
	struct SREGS D;

	segread (&D);
	printf ("Las dos lineas siguientes deben ser iguales...\n");
	printf ("%#X %#X %#X %#X\n",D.es, D.cs, D.ss, D.ds);
	printf ("%#X %#X %#X %#X\n",_ES, _CS, _SS, _DS);
	getch();
}




