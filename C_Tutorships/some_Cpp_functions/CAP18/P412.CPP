#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"

int main() {
	int unidad = 0,modo,i;
	char s[10];

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	i = getgraphmode();
	itoa (i,s,10);
	char *titulo = new char [strlen ("Modo actual = ") + strlen (s) + 1];
	strcpy (titulo,"Modo actual = ");
	strcat (titulo,s);
	outtext (titulo);
	getch();
	delete titulo;
	closegraph();
	return 0;
}

