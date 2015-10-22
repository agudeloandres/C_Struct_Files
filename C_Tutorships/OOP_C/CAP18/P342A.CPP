#include "iostream.h"
#include "stdio.h"
#include "graphics.h"
#include "conio.h"

void main() {
	int unidad = 0,modo;
	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	// ....
	getch();
	closegraph();  // Vuelve al modo texto
	getch();
}
