#include "iostream.h"
#include "graphics.h"
#include "conio.h"

class R  {
	int x1,y1;
	int x2,y2;
	int color;
public:
	void iniciar(int x11, int y11, int x22, int y22, int c);
	void esconder();
	void aparecer();
	void mover(int x11, int y11, int x22, int y22);
};

void R::iniciar(int x11, int y11, int x22, int y22, int c) {
	x1 = x11;
	y1 = y11;
	x2 = x22;
	y2 = y22;
	color = c;
}
void R::esconder() {
	int t;
	t = getcolor();
	setcolor (getbkcolor() );
	rectangle (x1, y1, x2, y2);
	setcolor(t);
}
void R::aparecer() {
	int t;
	t = getcolor();
	setcolor (color );
	rectangle (x1, y1, x2, y2);
	setcolor(t);
}
void R::mover(int x11, int y11, int x22, int y22) {
	int t;

	esconder();

	x1 = x11;
	y1 = y11;
	x2 = x22;
	y2 = y22;

	aparecer();
}

int main() {
	int unidad = DETECT, modo, i ;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	R a;
	a.iniciar (10,50,20,100,GREEN);

	// Otras instrucciones

	i = 0;
	while (!kbhit() ) {
		a.mover (10 + i,50,20+i,100);
		i++;
		if (i + 40 > getmaxx() )
			i = 0;
	}
	closegraph();
	return 0;
}


