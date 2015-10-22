#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

void main ()  {
	int c;
	void marco (int a, int b, int c, int d);
	struct text_info p;
	void escriba_datos();
	void piso_color(int,int);
	marco (2,3,70,18);
	gotoxy (13,7);
	piso_color (BLACK,WHITE);
	gettextinfo (&p);
	clrscr();
	gotoxy (1,1);
	cprintf ("Columna izquierda de la ventana activa %d",p.winleft);
	gotoxy (1,2);
	cprintf ("Columna derecha de la ventana activa   %d",p.winright);
	gotoxy (1,3);
	cprintf ("Fila superior de la ventana activa     %d",p.wintop);
	gotoxy (1,4);
	cprintf ("Fila inferior de la ventana activa     %d",p.winbottom);
	gotoxy (1,5);
	cprintf ("Color de fondo y color de la letra     %d",p.attribute);
	gotoxy (1,6);
	cprintf ("Penultimo atributo del video           %d",p.normattr);
	gotoxy (1,7);
	cprintf ("Modo del texto actual                  %d",p.currmode);
	gotoxy (1,8);
	cprintf ("Numero de filas    del video           %d",p.screenheight);
	gotoxy (1,9);
	cprintf ("Numero de columnas del video           %d",p.screenwidth);
	gotoxy (1,10);
	cprintf ("Columna donde esta el cursor           %d",p.curx);
	gotoxy (1,11);
	cprintf ("Fila donde esta el cursor              %d",p.cury);
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
	clrscr();
}

