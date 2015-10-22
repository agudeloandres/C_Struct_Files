#include "iostream.h"
#include "graphics.h"
#include "conio.h"

int main() {
	int unidad = 0,modo;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setpalette (9,RED);
	setcolor (9);
	setfillstyle (HATCH_FILL,9);
	fillellipse (getmaxx() / 2,getmaxy() / 2,300,150);
	getch();
	closegraph();
	return 0;
}


