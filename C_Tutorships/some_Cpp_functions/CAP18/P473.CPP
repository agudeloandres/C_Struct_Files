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
	setpalette (8,YELLOW);
	setcolor(8);
	rectangle (0,0,getmaxx(),getmaxy() );
	getch();
	closegraph();
	return 0;
}


