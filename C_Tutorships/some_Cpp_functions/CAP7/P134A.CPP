#include "stdio.h"
#include "conio.h"
#define PR(x) cprintf ("%s",x)

void main() {
	int c;

	c = getch();
	if (c == 0) {
		PR ("Tecla de control");
		c = getch();
		PR ("La funcion pulsada fue: ");
		cprintf ("%d",c);
	}
	else PR ("Tecla ASCII");
}
