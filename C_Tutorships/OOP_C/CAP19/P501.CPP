#include "iostream.h"
#include "graphics.h"
#include "conio.h"

class A  {
	int x,y;
public:
	A(int xi,int yi);
	int ejex() { return x; }
	int ejey() { return y; }
};
class B : public A {
	int anguloi,angulof,radio;
public:
	B(int xi,int yi,int ai,int af,int radioi);
	void dibujar();
	int fanguloi() { return anguloi; }
	int fangulof() { return angulof; }
	int fradio() { return radio; }
};
class C : public B {
	int rx,ry;
public:
	C(int xi,int yi,int ai,int af,int radioi,int rxi,int ryi);
	void dibujar();
};

A::A(int xi,int yi) {
	x = xi;
	y = yi;
}

B::B(int xi,int yi,int ai,int af,int radioi) :  A(xi,yi) {
	anguloi = ai;
	angulof = af;
	radio = radioi;
}

void B::dibujar() {
	arc (ejex(), ejey(), anguloi,angulof,radio);
}

C::C(int xi,int yi,int ai,int af,int radioi,int rxi,int ryi)
			: B (xi,yi,ai,af,radioi) {
	rx = rxi;
	ry = ryi;
}

void C::dibujar() {
	ellipse (ejex(), ejey(), fanguloi(), fangulof(),rx,ry);
}

int main() {
	int unidad = 0,modo;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	C objeto (getmaxx() / 2, getmaxy() / 2,0,180,100,100,70);
	objeto.dibujar();
	getch();
	closegraph();
	return 0;
}


