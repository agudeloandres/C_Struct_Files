#include "iostream.h"
#include "stdio.h"
#include "graphics.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"

int main() {
	int unidad = 0,modo,i;
	char *nombre,s[10];

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		printf ("Error al tratar de pasar al modo grafico\n");
		getch();
		return 1;
	}
	nombre = getdrivername();
	i = getmaxmode();
	itoa (i,s,10);
	outtextxy (0,0,"Unidad = ");  // Logitud de unidad = 72 pixels
	outtextxy (72,0,nombre);
	outtextxy (72 + strlen (nombre) * 8, 0, " Maximo modo = ");
	outtextxy (72 + strlen (nombre) * 8 + 15 * 8, 0, s);
	getch();
	closegraph();
	return 0;
}






