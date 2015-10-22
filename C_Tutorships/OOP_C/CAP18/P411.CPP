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
	setpalette (8,RED);
	setcolor(8);
	setlinestyle(CENTER_LINE,0,0);;
	linerel (100,100);
	getch();
	closegraph();
	return 0;
}


