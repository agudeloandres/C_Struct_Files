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
	setpalette (8,LIGHTBLUE);
	setcolor (8);
	setfillstyle (CLOSE_DOT_FILL,8);
	pieslice (getmaxx() / 2,getmaxy() / 2,30,60,100);
	if (graphresult() == -6) {
		cout << "Error! -> ";
		cout << grapherrormsg  ( graphresult() );
		getch();
		return 1;
	}
	getch();
	closegraph();
	return 0;
}


