#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "stdlib.h"

int main() {
	int unidad = 0,modo;
	char sx[10],sy[10];

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	settextstyle (GOTHIC_FONT,HORIZ_DIR,0);
	itoa (textheight("F"),sx,10);
	itoa (textwidth("F"),sy,10);
	outtextxy (0,20,sx);
	outtextxy (0,50,sy);
	setusercharsize (3,2,7,4);
	itoa (textheight("F"),sx,10);
	itoa (textwidth("F"),sy,10);
	settextstyle (DEFAULT_FONT ,HORIZ_DIR,1);
	outtextxy (200,30,sx);
	outtextxy (200,50,sy);
	getch();
	closegraph();
	return 0;
}



