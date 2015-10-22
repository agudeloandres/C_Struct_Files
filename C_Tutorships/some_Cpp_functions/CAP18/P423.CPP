#include "iostream.h"
#include "graphics.h"
#include "conio.h"

int main() {
	int unidad = 0,modo,i;
	struct palettetype far *p;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	p = getdefaultpalette();
	closegraph();
	for (i = 0; i <= p->size-1; i++) {
		cout << "Color de la posicion #";
		cout.width (3);
		cout << i << ' ';
		cout.width (3);
		cout << (int)p->colors[i] << endl;
	}
	getch();
	return 0;
}