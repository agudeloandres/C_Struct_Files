
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "stdlib.h"


/* LAS FUNCIONES DEBEN ESTAR DEFINIDAS ANTES DEL main() */


void F1(void) {
	printf ("Primera\n");
}

void F2(void) {
	printf ("Segunda\n");
}

void F3(void) {
	printf ("Tercera\n");
}

void main() {
	void F1(), F2(),F3();
	atexit (F1);
	atexit (F2);
	atexit (F3);
	exit (0);
}
