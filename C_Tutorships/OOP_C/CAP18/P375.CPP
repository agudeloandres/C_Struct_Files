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
	moveto(20,20);
	outtext ("p  r  u  e  b  a");
	setviewport (100,100,400,400, 1 );
	getch();
	cleardevice();
	getch();
	closegraph();
	return 0;
}
