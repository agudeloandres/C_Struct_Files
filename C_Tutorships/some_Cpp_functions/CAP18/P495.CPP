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
	setfillstyle (CLOSE_DOT_FILL,8);
	fillpoly (sizeof (poly) / (2 * sizeof (int) ), poly);
	if (graphresult() == -6) {
		cout << "Error! -> ";
		cout << grapherrormsg (graphresult() );
		getch();
		return 1;
	}
	getch();
	closegraph();
	return 0;
}
