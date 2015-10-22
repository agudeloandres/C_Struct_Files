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

	outtext ("BOGOTA : COLOMBIA");
	setpalette (3,GREEN);
	getch();
	setpalette (7,BLUE);
	getch();
	setbkcolor (3);
	getch();
	setcolor   (7);
	getch();

	closegraph();
	return 0;
}





