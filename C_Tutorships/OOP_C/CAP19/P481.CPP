#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "string.h"

class A {
	int *q,*r;
	char nombre_objeto[3];
public:
	A() {
		strcpy (nombre_objeto,"SN");
		outtext ("const. obj. ");
		outtext (nombre_objeto);
		getch();
	}
	A(char *nombre) {
		strcpy (nombre_objeto,nombre);
      outtext ("const. obj. ");
		outtext (nombre_objeto);
		getch();
	}
	void init (int xi, int yi);
	int ejex();
	int ejey();
	~A();
};

void A::init(int xi, int yi) {
	q = new int (xi);
	r = new int (yi);
}
int A::ejex() { return *q; }
int A::ejey() { return *r; }

A::~A() {
	outtext ("dest. obj ");
	outtext(nombre_objeto );
	delete q;
	delete r;
}
class B {
	A p;
	int radio;
	int color;
public:
	B (int xi, int yi, int radioi, int colori);
	void datos (int *q, int *r);
	void dibujar(A );
	~B() {
		outtext ("Lib. obj. B ");
	}
};
B::B (int xi, int yi, int radioi, int colori) {
	outtext ("Construye objeto de tipo B ");
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
	{
		int unidad = 0,modo;

		initgraph (&unidad,&modo,"c:\\bc\\bgi");
		if (graphresult() != 0) {
			cout << "Error al tratar de pasar al modo grafico\n";
			getch();
			return 1;
		}
		B c (getmaxx() / 2, getmaxy() / 2, 100, YELLOW);

		A d("d");
		d.init(getmaxx() / 4, getmaxy() / 4);

		c.dibujar(d);

		getch();
		clearviewport();
	}
	// En este lugar ejecuta 3 veces el destructor ~A()
	// En una de estas llamadas libera
	// el objeto escondido que se genera en la llamada
	// a la rutina c.dibujar()
	getch();
	closegraph();
	return 0;
}


