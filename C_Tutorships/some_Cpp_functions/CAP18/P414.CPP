#include "iostream.h"
#include "stdio.h"
#include "graphics.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"

int main() {
	int unidad = 0,modo,i;
	char s[10];

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		printf ("Error al tratar de pasar al modo grafico\n");
		getch();
		return 1;
	}
	setgraphmode (getmaxmode() - 1);
	i = getgraphmode();
	itoa (i,s,10);
	outtextxy (0,0,"Modo Actual = ");
	outtextxy (14 * 8,0,  s);
	getch();
	closegraph();
	return 0;
}
