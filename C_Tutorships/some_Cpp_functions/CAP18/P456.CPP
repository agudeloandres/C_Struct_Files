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
	outtextxy (0,0,"No sucede ningun cambio...");
	setactivepage(1);
	settextstyle (GOTHIC_FONT,VERT_DIR,7);
	outtextxy(0,100,"Alfabetos");
	outtextxy(400,100,"Alfabetos");
	getch();
	closegraph();
	return 0;
}


