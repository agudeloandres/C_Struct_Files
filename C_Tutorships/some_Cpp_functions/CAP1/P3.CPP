#include "stdio.h"  // printf()
#include "conio.h"	// getch()
#include "stdlib.h"  // exit()
// El tipo void indica que la funcion no devuelve nada
// En C++ los comentarios de una linea se
// indican con dos slash seguidos

/*
		Los comentarios de varias lineas, se inician
		con un slash seguido de asterisco y
		finaliza con un asterisco seguido de un slash
*/

// En C++ todas las funciones deben tener prototipo

void main() {
	void p_clave();   // En c++ debe existir Prototipo
	p_clave();			// Llamada
}


void p_clave () {
	int i;
	char pal [9],c;

	pal [0] = 's';
	pal [1] = 'i';
	pal [2] = 's';
	pal [3] = 'e';
	pal [4] = 'p';
	pal [5] = 'u';
	pal [6] = 'e';
	pal [7] = 'd';
	pal [8] = 'e';
	for (i=0; i < 9;i++) {
		c = getch();     /* No hace eco */
		printf ("*");
		if (c != pal [i]) {
			printf ("\nClave erronea. Oprima <R>..\n");
			getch();
			exit(1);
		}
	}
	printf ("\nClave correcta. Oprima <R>..\n");
	getch();
}
