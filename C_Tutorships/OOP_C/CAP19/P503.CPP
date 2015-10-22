#include "iostream.h"
#include "conio.h"
#include "stdlib.h"
#include "stdio.h"
#include "graphics.h"

class BASE {
public:
	BASE () {}
	virtual void dibujar() { }
	~BASE() {}
};

class T : public BASE {
	int x,y,radio;
public:
	T (int totali) :  BASE() {
		x = y = radio = totali;
	}
	virtual void dibujar() {
		clearviewport();
		circle (x,y,radio);
	}
	~T() {}
};

class P : public BASE {
	int x,y,radio;
public:
	P (int totali) :  BASE() {
		x = y = radio = totali;
	}
	virtual void dibujar() {
		clearviewport();
		circle (x,y,radio);
	}
	~P() {}
};


class E : public BASE {
	int x,y,radio;
public:
	E (int totali) :  BASE() {
		x = y = radio = totali;
	}
	virtual void dibujar() {
		clearviewport();
		circle (x,y,radio);
	}
	~E() {}
};


int main() {
	int unidad = 0,modo;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	BASE *q;
	T a(100);
	P b(200);
	E c(50);
	char dato = getch();
	while (dato == 'a' || dato == 'b' || dato == 'c') {
		switch (dato) {
			case 'a' : q = &a; break;
			case 'b' : q = &b; break;
			case 'c' : q = &c; break;
		}
		q->dibujar ();
		getch();
		clearviewport();
		outtextxy (0,0,"Teclee a,b o c para continuar. <R> para fin");
		dato = getch();
	}
	closegraph();
	return 0;
}

