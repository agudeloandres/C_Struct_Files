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
	setpalette (3,YELLOW);
	setcolor (3);
	settextstyle (GOTHIC_FONT ,VERT_DIR,3);
	outtextxy (100,0,"ESTRUCTURAS DE DATOS EN PASCAL");
	getch();
	return 0;
}


