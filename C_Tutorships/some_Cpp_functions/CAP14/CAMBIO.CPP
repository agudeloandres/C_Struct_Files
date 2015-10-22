/******************************* programa cambio.cpp ********* */
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string .h"

void main(int argc, char *argv[]) {
	textattr (15);
	clrscr();
	if (strcmp (argv[1], "key3") != 0) {
		printf ("Debe ejecutar el programa raiz\n%d\n",argc);
		getch();
		exit(1);
	}
	printf ("Programa cambio.exe\n");
	getch();
	exit(1);
}

