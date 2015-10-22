#include "iostream.h"
#include "graphics.h"
#include "conio.h"

int main() {
	int unidad = 0,modo,i;
	struct palettetype palette;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}

	outtext ("PRUEBA");
	getch();
	setpalette(0,YELLOW);     	// Fondo amarillo
	setpalette(15,RED);        // Letra roja
	getch();
	setpalette(15,BLUE);			// Letra azul
	setpalette(0,RED);			// Fondo rojo
	getch();
	closegraph();
	return 0;
}

