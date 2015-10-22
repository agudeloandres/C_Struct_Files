#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "stdlib.h"

int main() {
	int unidad = 0,modo,i;
	char s[10];
	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}

	i = getmaxy();
	itoa (i,s,10);
	outtext ("MAXIMO VALOR DE y = ");
	outtextxy (160,0, s);
	getch();
	closegraph();
	return 0;
}



