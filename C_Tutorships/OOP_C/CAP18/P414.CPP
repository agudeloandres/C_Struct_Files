#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "stdio.h"

int main() {
	int unidad = 0,modo;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	setpalette (3,RED);
	setcolor(3);
	rectangle (100,100,getmaxx(),getmaxy()  );
	getch();
	setpalette (4,GREEN);
	setcolor(4);
	rectangle (50,50,200,300);
	getch();
	floodfill (101,101,4);
	if (graphresult()  == grNoFloodMem ) {
		restorecrtmode();
		printf ("%s ","Error en floodfill() -> ");
		printf ("%s\n", grapherrormsg (graphresult()  )  );
		getch();
		return 1;
	}
	getch();
	closegraph();
	return 0;
}


