#include "stdio.h"
#include "conio.h"
#define PR(x) cprintf ("%s",x)

void main() {
	int c;

	clrscr ();
	c = getch();
	while (c == 0) {
		c = getch();
		switch (c) {
			case 72 : gotoxy (wherex(),wherey() - 1); break;
			case 80 : gotoxy (wherex(),wherey() + 1); break;
			case 77 : gotoxy (wherex() + 1,wherey()); break;
			case 75 : gotoxy (wherex() - 1,wherey()); break;
			default : ;
		}
		c = getch();
	}
	c = getch();
}
