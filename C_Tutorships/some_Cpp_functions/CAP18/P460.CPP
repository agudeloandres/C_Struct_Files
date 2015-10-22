#include "iostream.h"
#include "stdlib.h"
#include "graphics.h"
#include "conio.h"

void *getmemoria(int n) {
	return new char [n+1];
}

int main() {
	int unidad = 0,modo,n;
	char s[10];
	void *getmemoria(int),*p;

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
	p = getmemoria (n);		// No esta dentro de las librerias del c++

	//   ... Procesos adicionales

	delete p;

	// Es obligatorio liberar la memoria asignada

	getch();
	closegraph();
	return 0;
}

