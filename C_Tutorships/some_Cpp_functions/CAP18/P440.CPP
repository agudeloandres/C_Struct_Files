#include "iostream.h"
#include "graphics.h"
#include "conio.h"

int main() {
	int unidad = 0,modo;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}

	moveto(100,100);
	moverel (10,10);
	outtext ("Viros informaticos");
	getch();
	closegraph();
	return 0;
}


