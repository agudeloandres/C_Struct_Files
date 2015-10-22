#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#define clipon 1
#define clipoff 0

int main() {
	int unidad = 0,modo;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setviewport (50,50,270,208,clipon);	// x = 0-220  y = 0-158
	moveto(10,10);
	outtext ("1234567890");
	getch();
	closegraph();
	return 0;
}


