#include "iostream.h"
#include "graphics.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"

class A {
	char *cadena;
	int *datos[5];
public:
	A(char *cad,int e, int d, int t);
	void imprimir();
	int altura();
	int ancho();
	~A();
};
A::A(char *cad,int e, int d, int t) {
		int i;
		cadena = new char [strlen (cad) + 1];
		strcpy (cadena,cad);
		for (i=0; i < 5; i++)
			datos [i] = new int;
		*datos [0] = e;
		*datos [1] = d;
		*datos [2] = t;
		*datos [3] = textheight(cadena); // Altura Original
		*datos [4] = textwidth(cadena);  // Largo Original
}
void A::imprimir() {
	char s1[10],s2[10];
	settextstyle (*datos[0], *datos[1], *datos [2]);
	outtextxy (0,0,cadena);
	itoa (altura(),s1,10);
	itoa (ancho(),s2,10);
	char *titulo;
	titulo = new char [strlen (s1) + strlen (s2) + 2];
	strcpy (titulo,s1);
	strcat (titulo," ");
	strcat (titulo,s2);
	outtextxy (200,200,titulo);
	delete titulo;
}
int A::altura() {
	return *datos [3];
}
int A::ancho() {
	return *datos [4];
}
A::~A() {
	int i;
	for (i=0; i < 5; i++)
		delete datos [i];
	delete cadena;
	settextstyle (0,0,1);
	outtext ("Destruyendo");
	moveto (0,gety() + 10);
}

int main() {
	{
		int unidad = 0,modo;

		initgraph (&unidad,&modo,"c:\\bc\\bgi");
		if (graphresult() != 0) {
			cout << "Error al tratar de pasar al modo grafico\n";
			getch();
			return 1;
		}
		A b ("Lenguaje",GOTHIC_FONT,1,10);
		A c ("Turbo",SANS_SERIF_FONT,0,5);
		A d ("Pascal",DEFAULT_FONT,0,10);

		b.imprimir();
		getch();

		clearviewport();
		c.imprimir();
		getch();

		clearviewport();
		d.imprimir();
		getch();
      clearviewport();
	}

	// Al salir del bloque anterior
	// Se invoca automaticamente 3 veces el
	// Destructor

	
	getch();
	closegraph();
	return 0;
}


