#include "iostream.h"
#include "graphics.h"
#include "conio.h"

int main() {
	int unidad = 0,modo;
	char p[8] = { 0xAB,0xAA,0xAC,0xAA,0x12,0x34,0x45,0x56 };

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setpalette (3,RED);
	setcolor(3);
	rectangle (100,100,getmaxx(),getmaxy() );
	getch();
	setpalette (4,GREEN);
	setcolor(4);
	rectangle (50,50,200,300);
	getch();
	setpalette (15,BLUE);
	setfillpattern (p,15);
	floodfill (101,101,4);
	getch();
	closegraph();
   return 0;
}
