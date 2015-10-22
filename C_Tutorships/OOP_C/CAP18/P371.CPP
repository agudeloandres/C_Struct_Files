#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "stdlib.h"
#define clipon 1
#define clipoff 0

int main() {
	int unidad = 0,modo,x,y;
	char s[10],s1[10];

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setviewport (50,50,270,208,clipon);	// x = 0-220  y = 0-158
	moveto(10,10);
	x = getx();
	itoa (x,s,10);
	y = gety();
	itoa (y,s1,10);
	outtext ("CP = ");
	outtextxy (10 + 40, 10, s);
	outtextxy (10 + 40 + 32, 10, s1);
	getch();
	closegraph();
	return 0;
}
