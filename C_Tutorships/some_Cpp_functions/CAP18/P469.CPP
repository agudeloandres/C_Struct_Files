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
	setlinestyle(USERBIT_LINE,0x8001,THICK_WIDTH);
	line (0,0,getmaxx(),getmaxy());
	getch();
	closegraph();
	return 0;
}


