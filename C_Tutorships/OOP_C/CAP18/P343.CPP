#include "iostream.h"
#include "stdio.h"
#include "graphics.h"
#include "conio.h"

void main() {
	int unidad = 0,modo;
	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	outtext ("Modo Grafico...");   	// Mas adelante se estudia.
												// Escribe en modo grafico
	getch();
	closegraph();  						// Vuelve al modo texto
	printf ("Modo Texto");
	getch();
}
