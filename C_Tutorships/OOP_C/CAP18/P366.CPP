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
	setviewport (50,10,90,300,clipon);
	outtext ("1234567890");
	getch();
	closegraph();
	return 0;
}




