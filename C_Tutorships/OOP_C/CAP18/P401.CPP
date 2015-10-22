#include "iostream.h"
#include "stdlib.h"
#include "graphics.h"
#include "conio.h"

void *getmemoria(int n) {
	return new char [n+1];
}

int main() {
	int unidad = 0,modo,n,i,j;
	char s[10];
	void *getmemoria(int),*p;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	settextstyle (GOTHIC_FONT,HORIZ_DIR,0);
	setusercharsize (7,1,7,1);
	i = textheight ("C");
	j = textwidth ("C");
	outtext("Maria");
	n = imagesize (0,0,145,196);
	if (n == 0) {
		outtextxy (0,10,"n es cero");
		return 1;
	}
	if (graphresult() == -11) {
		outtextxy (0,20,"Error en imagesize() ");
		return 2;
	}
	p = getmemoria (n);		// No esta dentro de las librerias del c++
	getimage (0,0,145,196,p);

	//   ... Procesos adicionales

	delete p;

	// Es obligatorio liberar la memoria asignada

	getch();
	closegraph();
	return 0;
}








