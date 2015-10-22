#include "iostream.h"
#include "stdio.h"
#include "graphics.h"
#include "conio.h"
#include "string.h"

int main() {
	int unidad = 0,modo,menor,mayor,i;
	char *p;
	char *s[5];


	for (i=0; i < 5; i++)
		s[i] = new char [20];


	initgraph (&unidad,&modo,"c:\\bc\\bgi");
	if (graphresult() != 0) {
		printf ("Error al tratar de pasar al modo grafico\n");
		getch();
		return 1;
	}

	getmoderange (unidad,&menor,&mayor);


	for (i = menor; i <= mayor; i++) {
	  p = getmodename (i);
	  strcpy (s[i],p);
	}

	for (i = menor; i <= mayor; i++) {
		outtextxy (0,i * 10, s[i] );
	}

	getch();
	closegraph();
	for (i=0; i < 5; i++)
		delete s[i];
	return 0;
}


