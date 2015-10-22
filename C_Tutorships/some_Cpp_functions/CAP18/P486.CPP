#include "iostream.h"
#include "graphics.h"
#include "conio.h"

int main() {
	int unidad = DETECT,modo;
	struct arccoordstype p;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	arc (200,200,0,90,100);
	getarccoords (&p);
	line (p.xstart,p.ystart,p.xend,p.yend);
	getch();
	closegraph();
	return 0;
}

