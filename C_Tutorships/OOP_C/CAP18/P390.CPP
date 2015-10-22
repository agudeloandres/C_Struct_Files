#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "stdlib.h"

int main() {
	int unidad = 0,modo;
	struct textsettingstype p;
	char sfuente[10],sdireccion[10],stamano[10],shoriz[10],svert[10];

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	settextjustify (LEFT_TEXT,CENTER_TEXT);
	settextstyle (GOTHIC_FONT,HORIZ_DIR,3);
	gettextsettings (&p);
	itoa (p.font,sfuente,10);
	itoa (p.direction,sdireccion,10);
	itoa (p.charsize,stamano,10);
	itoa (p.horiz,shoriz,10);
	itoa (p.vert,svert,10);
	settextstyle (DEFAULT_FONT,HORIZ_DIR,0);
	outtextxy (0,10,sfuente);
	getch();
	outtextxy (0,20,sdireccion);
	getch();
	outtextxy (0,30,stamano);
	getch();
	outtextxy (0,40,shoriz);
	getch();
	outtextxy (0,50,svert);
	getch();
	closegraph();
	return 0;
}



