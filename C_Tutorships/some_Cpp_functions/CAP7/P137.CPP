#include "stdio.h"
#include "conio.h"

void main() {
	int c,x=3,y=5,x1=60,y1=20;
	void marco (int a, int b, int c, int d);
	void mover_cursor();
	clrscr ();
	marco (x,y,x1,y1); /* Pueden ser cualquier valor */
	mover_cursor();
}

void mover_cursor() {
	struct text_info p;
	int A,B,c;

	gettextinfo (&p);
	A = p.winbottom - p.wintop + 1;
	B = p.winright - p.winleft + 1;
	c = getch();
	while (c == 0) {
		c = getch();
		switch (c) {
			case 72 : 	if (wherey() == 1)
						gotoxy (wherex(), A);
					else gotoxy (wherex(),wherey() - 1);
					break;
			case 80 : 	if (wherey() == A)
						gotoxy (wherex(), 1);
					else gotoxy (wherex(),wherey() + 1);
					break;
			case 77 : 	if (wherex() == B)
						gotoxy (1, wherey());
					else  gotoxy (wherex() + 1,wherey());
					break;
			case 75 : 	if (wherex() == 1)
						gotoxy (B, wherey());
					else gotoxy (wherex() - 1,wherey());
					break;
			default : ;
		}
		c = getch();
	}
	c = getch();
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
}


