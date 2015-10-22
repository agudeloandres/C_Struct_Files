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
	setpalette (8,LIGHTMAGENTA);
	setcolor (8);
	setfillstyle (LTSLASH_FILL,8);
	bar (10,110,360,150);
	getch();
	closegraph();
	return 0;
}



