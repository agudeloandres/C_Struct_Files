#include "stdio.h"
#include "conio.h"

void main() {
	clrscr();
   void marco(int,int,int,int);
	marco (2,2,79,23);
	getch();
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

