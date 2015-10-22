#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "stdlib.h"

#define TRUNCAR 1

int main() {
	int unidad = 0,modo;
	struct viewporttype  p;
	char s1[10],s2[10],s3[10],s4[10];

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setviewport (100,234,345,400,TRUNCAR);
	getviewsettings (&p);
	itoa (p.left,s1,10);
	itoa (p.top,s2,10);
	itoa (p.right,s3,10);
	itoa (p.bottom,s4,10);
	outtextxy (0,10,s1);
	outtextxy (0,20,s2);
	outtextxy (0,30,s3);
	outtextxy (0,40,s4);
	if (p.clip == 1)
		outtextxy (0,50,"Respeta margenes");
	else outtextxy (0,50,"No respeta margenes");
	getch();
	return 0;
}


