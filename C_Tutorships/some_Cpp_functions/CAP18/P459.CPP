#include "iostream.h"
#include "stdlib.h"
#include "graphics.h"
#include "conio.h"

int main() {
	int unidad = 0,modo,n;
	char s[10];

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	n = imagesize (20,30,40,130);
	if (n == 0) {
		outtextxy (0,10,"n es cero");
		return 1;
	}
	if (graphresult() == -11) {
		outtextxy (0,20,"Error en imagesize() ");
		return 2;
	}
	itoa(n,s,10);
	outtextxy (0,0,"Numero de bytes: ");
	outtextxy (136,0,s);
	getch();
	return 0;
}
