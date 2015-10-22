#include "iostream.h"
#include "stdlib.h"
#include "graphics.h"
#include "conio.h"

void *getmemoria(int n) {
	return new char [n+1];
}

int main() {
	int unidad = 0,modo,n;
	void *getmemoria(int),*p;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	n = imagesize (0,0,8,8);

	if (n == 0) {
		outtextxy (0,10,"n es cero");
		return 1;
	}
	if (graphresult() == -11) {
		outtextxy (0,20,"Error en imagesize() ");
		return 2;
	}
   outtextxy(0,0,"C");
	p = getmemoria (n);
	getimage (0,0,8,8,p);
	getch();
	setpalette (3,RED);
	setcolor (3);
	outtextxy(10,10,"C");
	getch();
	putimage (0,250,p,COPY_PUT);
	getch();
	closegraph();
	return 0;
}
