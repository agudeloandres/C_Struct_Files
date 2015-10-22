#include "iostream.h"
#include "stdio.h"
#include "graphics.h"
#include "conio.h"

int main() {
	int unidad = 0,modo;
	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		printf ("Error al tratar de pasar al modo grafico\n");
		getch();
		return 1;
	}
	outtext ("Modo Grafico...");   	// Mas adelante se estudia.
												// Escribe en modo grafico
	getch();
	closegraph();  						// Vuelve al modo texto
	printf ("Modo Texto");
	getch();
	return 0;
}
