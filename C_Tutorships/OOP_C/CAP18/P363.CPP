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

	outtext ("UNIVERSIDAD");
	getch();
	setpalette (15,YELLOW);				// Cambia de color a UNIVERSIDAD
	getch();
	i = getmaxcolor();         		// Almacena en i 15
	itoa (i,s,10);
	outtextxy (0,10,s);     			// Escribe 15
	getch();
	i = i - 4;
	setcolor (--i);						// Cambia el calor a LIGHTGREEN  (10)
												// Pero no cambia nada sobre el video

	outtextxy (0,20,"UNIVERSIDAD");	// Escribe UNIVERSIDAD en LIGHTGREEN
	getch();
	return 0;
}


