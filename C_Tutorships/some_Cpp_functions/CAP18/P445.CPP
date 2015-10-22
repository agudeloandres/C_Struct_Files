#include "iostream.h"
#include "graphics.h"
#include "conio.h"

int main() {
	int x,y,i,j,unidad=DETECT,modo;
	char sx[10],sy[10];
	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	outtextxy (0,0,"Para la ejecucion del programa");
	outtextxy (0,10,"Favor colocar la punta de un lapiz");
	outtextxy (0,20,"en la parte inferior de la letra \'L\' ");
	outtextxy (0,30,"Favor, Oprima una tecla");
	getch();
	cleardevice();
	for (i = LEFT_TEXT; i <=  RIGHT_TEXT; i++) {
		settextjustify (LEFT_TEXT,TOP_TEXT);
		outtextxy (300,0,"CP ");
		switch (i) {
			case 0 : outtextxy (350,0,"a la izquierda del texto"); break;
			case 1 : outtextxy (350,0,"en el centro del texto"); break;
			case 2 : outtextxy (350,0,"a la derecha del texto"); break;
		}
		for (j = BOTTOM_TEXT; j <= TOP_TEXT; j++) {
			settextjustify (i,j);
			outtextxy (220,220,"LITERAL");
			getch();
			cleardevice();
		}
	}
	getch();
	return 0;
}


