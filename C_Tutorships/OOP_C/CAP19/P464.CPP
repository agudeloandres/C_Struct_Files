#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "dos.h"


class POLY  {
	int n;
	int puntos [40];  // Poligono de maximo 40/2 puntos
public:
	POLY () { }
	void iniciar (int n1, int *puntos1);
	void borrarpoly();
	void dibujarpoly();
	~POLY() { }
};

void POLY::iniciar(int n1, int *puntos1) {
	int i;
	n = n1;
	for (i = 0; i < n * 2; i = i + 2) {
		puntos[i] = puntos1[i];
		puntos[i+1] = puntos1 [i+1];
	}
}
void POLY::borrarpoly() {
	int t;
	t = getcolor();
	setcolor (getbkcolor() );
	drawpoly (n, puntos);
	setcolor(t);
}
void POLY::dibujarpoly() {
	drawpoly (n,puntos);
}

int main() {
	int unidad = DETECT, modo, i ;
	int puntos [40]; // Poligonos de maximo 20 puntos
	POLY poligonos [40]; // Llama 40 veces el constructor vacio
								// Maximo 40 poligonos


	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		cout << "Error al tratar de pasar al modo grafico\n";
		getch();
		return 1;
	}
	for (i=0; i < 40; i++) {
		puntos [0] = 100 + (i+1) * 10;
		puntos [1] = 10;

		puntos [2] = puntos [0] + 50;
		puntos [3] = puntos [1] + 50;

		puntos [4] = puntos [0];
		puntos [5] = puntos [1] + 100;

		puntos [6] = puntos [0] - 50;
		puntos [7] = puntos [1] + 50;

		puntos [8] = puntos [0];
		puntos [9] = puntos [1];

		poligonos[i].iniciar (5,puntos);
	}
	for (i=0; i < 40; i++) {
		poligonos [i].dibujarpoly();
		delay (100);  // Congela 100 milisegundos el programa
		poligonos [i].borrarpoly();
	}
	closegraph();
	// Llama 40 veces el destructor vacio
	return 0;
}


