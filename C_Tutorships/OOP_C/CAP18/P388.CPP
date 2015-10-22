#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

int main() {
	int x,y,i,j,n,unidad,modo;
	char sx[10],sy[10],sn[10];


	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setpalette (3,YELLOW);
	setcolor (3);
	settextstyle (GOTHIC_FONT,HORIZ_DIR,3);
	i = textheight ("E");
	j = textwidth ("ESTRUCTURAS DE DATOS EN PASCAL");
	itoa(i,sx,10);
	itoa(j,sy,10);
	settextstyle (DEFAULT_FONT,HORIZ_DIR,1);
	char *p;
	int k = strlen (sx) +  strlen (sy) + 2;
	p = new char [k];
	strcpy (p,sx);
	strcat (p," ");
	strcat (p,sy);
	outtext (p);
	delete p;
	getch();
	closegraph();
	return 0;
}


