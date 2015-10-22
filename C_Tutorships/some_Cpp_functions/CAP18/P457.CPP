#include "iostream.h"
#include "graphics.h"
#include "conio.h"

int main() {
	int unidad = VGA,modo=2;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setvisualpage (0);
	settextstyle (GOTHIC_FONT,VERT_DIR,7);
	outtextxy (0,190,"Alfabetos");
	getch();
	setactivepage(1);
	outtextxy (0,50,"INGLES");
	outtextxy (400,50,"ESPANOL");
	setvisualpage(1);
	getch();
	setvisualpage (0);
	getch();
	setvisualpage(1);
	getch();
	closegraph();
	return 0;
}