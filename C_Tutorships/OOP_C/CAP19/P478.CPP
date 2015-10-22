#include "iostream.h"
#include "graphics.h"
#include "conio.h"

class A {
	int x,y;
public:
	A() {}
	void init (int xi, int yi);
	int ejex();
	int ejey();
	~A() {}
};

void A::init(int xi, int yi) {
		x = xi;
		y = yi;
}
int A::ejex() { return x; }
int A::ejey() { return y; }

class B {
	A p;
	int radio;
	int color;
public:
	B (int xi, int yi, int radioi, int colori);
	void datos (int *q, int *r);
	void dibujar(A);
	~B() {}
};
B::B (int xi, int yi, int radioi, int colori) {
	p.init (xi,yi);
	radio = radioi;
	color = colori;
}
void B::datos (int *q, int *r) {
	*q = p.ejex();
	*r = p.ejey();
}
void B::dibujar(A objeto) {
	int t,cx,cy;
	datos (&cx, &cy);
	t = getcolor();
	setcolor (color);
	circle (cx, cy, radio);
	circle (objeto.ejex(), objeto.ejey(),10);
	setcolor (t);
}

int main() {
	int unidad = 0,modo;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	B c (getmaxx() / 2, getmaxy() / 2, 100, YELLOW);

	A d;
	d.init(getmaxx() / 4, getmaxy() / 4);

	c.dibujar(d);

	getch();
	closegraph();
	return 0;
}


