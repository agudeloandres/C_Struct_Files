#include "iostream.h"
#include "graphics.h"
#include "conio.h"

int main() {
	int unidad = 0,modo,i;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	for (i = EMPTY_FILL;  i <= CLOSE_DOT_FILL; i++) {
		clearviewport();
		setpalette (3,RED);
		setcolor(3);
		rectangle (100,100,getmaxx(),getmaxy()   );
		setpalette (4,GREEN);
		setcolor(4);
		rectangle (50,50,200,300);
		setpalette (15,LIGHTGRAY);
		setcolor (15);
		setfillstyle (i,15);
		floodfill(101,101,4);
		getch();
	}
	closegraph();
	return 0;
}


