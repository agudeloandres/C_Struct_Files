#include "iostream.h"
#include "stdio.h"
#include "graphics.h"
#include "conio.h"
#include "string.h"

int main() {
	int unidad = 0,modo;
	char titulo [36],*nombre;

	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		printf ("Error al tratar de pasar al modo grafico\n");
		getch();
		return 1;
	}
	nombre = getdrivername();
	strcpy (titulo,"Unidad Graficadora = ");
	strcat (titulo,nombre);
	outtext (titulo);
	getch();
	closegraph();
	printf ("Modo Texto");
	getch();
	return 0;
}
