#include "iostream.h"
#include "graphics.h"
#include "conio.h"

class E  {
	int x,y,rx,ry;
	int color;
public:
	E(int x1, int y1, int rx1, int ry1, int color1);
	void esconder();
	void aparecer();
	void mover(int x1, int y1, int rx1, int ry1);
};

E::E(int x1, int y1, int rx1, int ry1, int color1) {
	this->x = x1;
	this->y = y1;
	this->rx = rx1;
	this->ry = ry1;
	color = color1;
}
void E::esconder() {
	int t;
	t = getcolor();
	setcolor (getbkcolor() );
	ellipse (this->x, this->y, 0, 360, this->rx, this->ry);
	setcolor(t);
}
void E::aparecer() {
	int t;
	t = getcolor();
	setcolor (color );
	ellipse (this->x, this->y, 0, 360, this->rx, this->ry);
	setcolor(t);
}
void E::mover(int x1,int y1,int rx1, int ry1) {
	int t;

	esconder();
	this->x = x1;
	this->y = y1;
	this->rx = rx1;
	this->ry = ry1;
	aparecer();
}

int main() {
	int unidad = DETECT, modo, i ;
	E a(30,100,50,30,LIGHTMAGENTA);
	E b(30,150,50,30,LIGHTBLUE);
	E c(30,200,50,30,LIGHTGRAY);

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	i = 30;
	while (!kbhit () ) {
		a.mover(30+i,100,50,30);
		b.mover(30+i,150,50,30);
		c.mover(30+i,200,50,30);
		i+=2;
		if (i+50 > getmaxx()  )
			i = 0;
	}
	closegraph();
	return 0;
}


