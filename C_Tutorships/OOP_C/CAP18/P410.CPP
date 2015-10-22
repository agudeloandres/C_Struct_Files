#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

int main() {
	int unidad = 0,modo;
	char sl[10],sp[10],st[10];
	linesettingstype p;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setlinestyle(USERBIT_LINE,0x8001,THICK_WIDTH);
	getlinesettings (&p);
	itoa (p.linestyle,sl,10);
	itoa (p.upattern,sp,16);  // Base hexa
	itoa (p.thickness,st,10);
	char *titulo;
	titulo = new char [strlen (sl) + strlen (sp) + strlen (st) + 3];
	strcpy (titulo,sl);
	strcat (titulo," ");
	strcat (titulo,sp);
	strcat (titulo," ");
	strcat (titulo,st);

	outtextxy (0,0,titulo);
	delete titulo;
	getch();
	closegraph();
	return 0;
}


