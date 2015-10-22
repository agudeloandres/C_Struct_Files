#include "iostream.h"
#include "graphics.h"
#include "conio.h"

class Circulo  {
	int x,y,r;
	int color;
public:
	Circulo(int x1, int y1, int r1, int color1);
	void esconder();
	void aparecer();
	void mover(int x1, int y1, int r1);
	~Circulo() {
		cout << "Se llama automaticamente por ser\n";
		cout << "Objetos en memoria dinamica...\n";
	}
};

Circulo::Circulo(int x1, int y1, int r1, int color1) {
	x = x1;
	y = y1;
	r = r1;
	color = color1;
}
void Circulo::esconder() {
	int t;
	t = getcolor();
	setcolor (getbkcolor() );
	circle (x,y,r);
	setcolor(t);
}
void Circulo::aparecer() {
	int t;
	t = getcolor();
	setcolor (color );
	circle (x,y,r);
	setcolor(t);
}
void Circulo::mover(int x1,int y1,int r1) {
	int t;

	esconder();

	x = x1;
	y = y1;
	r = r1;

	aparecer();
}

int main() {
	int unidad = DETECT, modo, i ;
	Circulo *a,*b,*c;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}

	a = new Circulo (30,100,30,WHITE);
	b = new Circulo (30,100,30,YELLOW);
	c = new Circulo (30,100,30,GREEN);
	i = 1;
	while (!kbhit () ) {
		a->mover(30+i,100,30);
		b->mover(30+i,150,30);
		c->mover(30+i,200,30);
		i++;
		if (i+50 > getmaxx()  )
			i = 0;

	}
	clearviewport();
	delete a;
	delete b;
	delete c;
	getch();  	// Esta instruccion lee la tecla oprimida
					// para salir del while

	getch();		// Esta instruccion congela el programa
	closegraph();
	return 0;
}


