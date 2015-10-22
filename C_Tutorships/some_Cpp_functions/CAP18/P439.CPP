#include "iostream.h"
#include "graphics.h"
#include "conio.h"

int main() {
	int unidad = 0,modo,fila= 200,columna = 200;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	outtextxy (columna,fila-20,"Viros Informaticos");
	setcolor (BLUE);
	getch();
	outtextxy (columna,fila,"Viros Informaticos");
	getch();
	closegraph();
	return 0;
}



