#include "iostream.h"
#include "stdio.h"
#include "graphics.h"
#include "conio.h"
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
	i = getpalettesize();
	itoa(i,s,10);
	outtextxy (0,0,"Maximo Numero de Colores = ");
	outtextxy (27 * 8, 0, s);
	getch();
	closegraph();
	return 0;
}
