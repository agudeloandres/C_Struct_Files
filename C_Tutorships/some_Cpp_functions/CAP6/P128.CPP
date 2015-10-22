#include "stdio.h"
#include "conio.h"

void main ()  {
	int c;

	printf ("Modo Original. Oprima <R>\n");
	textmode (BW40);
	printf ("Video blanco y negro 40 columnas. Oprima <R>\n");
	getch();
	textmode (C40);
	printf ("Video en color, 40 columnas. Oprima <R>\n");
	getch();
	textmode (BW80);
	printf ("Video blanco y negro, 80 columnas. Oprima <R>\n");
	getch();
	textmode (C80);
	printf ("Video en color, 80 columnas. Oprima <R>\n");
	getch();
	textmode (MONO);
	printf ("Video monocromatico de 80 columnas. Oprima <R>\n");
	getch();
	textmode (LASTMODE);
	printf ("Regresa al modo anterior. Oprima <R>\n");
	getch();
}