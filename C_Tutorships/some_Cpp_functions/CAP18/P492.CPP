#include "iostream.h"
#include "graphics.h"
#include "conio.h"

int poly[10] = { 340,0,530,150,340,300,150, 150,340,0 };

int main() {
	int unidad = 0,modo;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setpalette (8,LIGHTBLUE);
	setcolor (8);
	drawpoly (sizeof (poly) / (2 * sizeof (int ) ), poly);
	getch();
	floodfill (getmaxx() / 2,getmaxy() / 2,8);
	getch();
	closegraph();
	return 0;
}


