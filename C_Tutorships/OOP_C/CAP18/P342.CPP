#include "iostream.h"
#include "stdio.h"
#include "graphics.h"
#include "conio.h"

void main() {
	int unidad,modo;
	detectgraph (&unidad,&modo);
	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	getch();
}
