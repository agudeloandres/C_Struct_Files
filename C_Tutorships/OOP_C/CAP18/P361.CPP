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
	setpalette (3,2);   	// color GREEN
	setbkcolor (3);      // Cambia el color del background a GREEN
	getch();
	closegraph();
	return 0;
}


