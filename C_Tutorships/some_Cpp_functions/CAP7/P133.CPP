#include "stdio.h"
#include "conio.h"
#define PR(x) cprintf ("%s",x)

void main() {
	int c;

	c = getch();
	if (c == 0)
		PR ("Tecla de control");
	else PR ("Tecla ASCII");
}
