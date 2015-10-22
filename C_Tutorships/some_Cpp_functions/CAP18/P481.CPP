#include "iostream.h"
#include "graphics.h"
#include "conio.h"

int main() {
	int unidad = 0,modo;
	fillsettingstype p;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setpalette (15,RED);
	setfillstyle (INTERLEAVE_FILL,15);

	getfillsettings (&p);

	restorecrtmode();

	cout << p.pattern << endl;
	cout << p.color << endl;	// Retorna el numero de la celda...

	getch();
	closegraph();
	return 0;
}



