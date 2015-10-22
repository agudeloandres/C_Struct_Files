#include "iostream.h"
#include "graphics.h"
#include "stdio.h"
#include "conio.h"

int main() {
	int unidad = 0,modo;
	char p[8] = { 0xAB,0xAA,0xAC,0xAA,0x12,0x34,0x45,0x56 };
	char q[8];

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setpalette (3,BLUE);
	setfillpattern (p,3);

	/*	Otras instrucciones */

	getfillpattern (q);
	restorecrtmode();
	for (int i = 0; i < 8; i++)
		printf ("%d\n",(unsigned char) q[i]);
	getch();
	return 0;
}


