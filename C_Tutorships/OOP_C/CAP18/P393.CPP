#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "stdlib.h"
int main() {
	int unidad = 0,modo;
	unsigned int i;
	char s[10];

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	putpixel (100,100,YELLOW);
	i = getpixel (100,100);
	itoa (i,s,10);
	outtext(s);
	getch();
	closegraph();
	return 0;
}


