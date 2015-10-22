#include "iostream.h"
#include "graphics.h"
#include "conio.h"

int main() {
	int unidad = DETECT,modo;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setpalette (8,LIGHTBLUE);
	setcolor (8);
	circle (getmaxx() / 2,getmaxy() / 2,200);
	getch();
	floodfill (getmaxx() / 2,getmaxy() / 2,8);
	getch();
	closegraph();  //  Libera la memoria dinamica
	return 0;
}
