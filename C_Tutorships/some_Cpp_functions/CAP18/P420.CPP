#include "iostream.h"
#include "stdio.h"
#include "graphics.h"
#include "conio.h"
#include "stdlib.h"

int main() {
	int unidad = 0,modo,i;
	char s[10];
	struct palettetype palette;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		printf ("Error al tratar de pasar al modo grafico\n");
		getch();
		return 1;
	}

	palette.size = 4;
	palette.colors [0] = YELLOW;
	palette.colors [1] = WHITE;
	palette.colors [2] = GREEN;
	palette.colors [3] = RED;
	setallpalette(&palette);
	getch();

	getpalette (&palette);
	closegraph();
	for (i = 0; i <= palette.size - 1; i++) {
		cout << "Color de la posicion #";
		cout.width (3);
		cout << i << ' ';
		cout.width (3);
		cout << (int)palette.colors[i] << endl;
	}
	getch();
	return 0;
}








