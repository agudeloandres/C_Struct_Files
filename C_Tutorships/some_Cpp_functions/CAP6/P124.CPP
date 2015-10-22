#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

#define arrizq 201
#define arrder 187
#define abajizq 200
#define abajder 188
#define vert 186
#define horiz 205

#define PR(x) cprintf ("%c",x)

void marco (int a, int b, int c, int d) {
	int i;

	window (1,1,80,25);      	/* Activa la ventana mayor
					para dibujar el marco */
	gotoxy (a-1,b-1);
	PR (arrizq);
	for (i=a; i <= c; i++)
		PR(horiz);
	PR(arrder);
	for (i=b; i <= d; i++) {
		gotoxy (c+1,i);
		PR(vert);
	}
	gotoxy (a-1,d+1);
	PR(abajizq);
	for (i=a; i <= c; i++)
		PR(horiz);
	PR(abajder);
	for (i=b; i <= d; i++) {
		gotoxy (a-1,i);
		PR(vert);
	}
	window (a,b,c,d);		/* Activa la ventana dentro del
					marco */
}


void main ()  {
	int c;
	char b[4000];
	void marco (int,int,int,int);
	void escriba_datos();
	void piso_color(int,int);
	piso_color (BLACK,WHITE);
	clrscr();
	marco (37,3,51,20);
	escriba_datos();
	gettext(36,2,52,21,b);
	puttext (18,2,34,21,b);
	getch();

}

void escriba_datos () {
	int i,j;

	for (i=0; i < 300; i++ ) {
		j = random (128);
		if (j > 31)
			cprintf ("%c",j);
	}
}

void piso_color (int piso,int color) {
	textbackground (piso);	/* Color del piso */
	textcolor (color);	/* Color de la letra */
}
