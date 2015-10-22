#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "dos.h"
#include "stdlib.h"

class PUNTO {
	int x,y;
public:
	PUNTO (int xi, int yi);
	void borrar();
	void dibujar();
	void mover(int xi, int yi);
};
PUNTO::PUNTO (int xi, int yi) {
	x = xi;
	y = yi;
}
void PUNTO::borrar() {
	putpixel(x,y,getbkcolor() );
}
void PUNTO::dibujar() {
	putpixel(x,y,WHITE);
	delay (50);
}
void PUNTO::mover(int xi, int yi) {
	borrar();
	x = xi;
	y = yi;
	dibujar();
}

int main() {
	int unidad = 0,modo,i,x,y;
	PUNTO a(23,45), b(2,3), c(0,0);

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	while (!kbhit() ) {
		x = random (getmaxx() );
		y = random (getmaxy() );
		a.mover(x,y);
		x = random (getmaxx() );
		y = random (getmaxy() );
		b.mover(x,y);
		x = random (getmaxx() );
		y = random (getmaxy() );
		c.mover(x,y);
	}
	getch();
	closegraph();
	return 0;
}


