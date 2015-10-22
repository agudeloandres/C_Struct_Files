#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

int main() {
	int i,j,n,unidad=DETECT,modo;
	char sx[10],sy[10],sn[10];

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setpalette (3,YELLOW);
	setcolor (3);
	char *p;
	for (n = 1; n <= 5; n++) {
		settextstyle (4,HORIZ_DIR,n);
		i = textheight ("E");
		j = textwidth ("E");
		itoa (i,sx,10);
		itoa (j,sy,10);
		itoa (n,sn,10);
		p = new char [strlen(sn) + strlen (sx) + strlen (sy) + 3];
		strcpy (p,sn);
		strcat (p," ");
		strcat (p,sx);
		strcat (p," ");
		strcat (p,sy);
		outtextxy (0,n * 30,p);
	}
	getch();
	return 0;
}



