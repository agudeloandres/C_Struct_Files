#include "stdio.h"
#include "conio.h"
#define CPR(x) cprintf ("%s",x)
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
	void marco(int,int,int,int);
	void piso_color(int,int);

	piso_color (BLACK,WHITE);
	clrscr();
	piso_color (WHITE,BLACK);
	CPR("ACTUALIZACION");
	gotoxy (21,1);
	CPR("INGRESOS");
	gotoxy (36,1);
	CPR("FACTURACION");
	gotoxy (53,1);
	CPR("REPORTES");
	gotoxy (68,1);
	CPR("TERMINAR");
	c = getch();
	switch(c) {
		case 'a' :
		case 'A' : 	piso_color (BLACK,WHITE);
				marco (3,3,19,20);
				break;
		case 'i' :
		case 'I' :      piso_color (BLACK,WHITE);
				marco (22,3,34,20);
				break;
		case 'f' :
		case 'F' : 	piso_color (BLACK,WHITE);
				marco (37,3,51,20);
				break;
		case 'r' :
		case 'R' : 	piso_color (BLACK,WHITE);
				marco (54,3,66,20);
				break;
		case 't' :
		case 'T' : 	piso_color (BLACK,WHITE);
				marco (69,3,78,6);
				break;

		default : ;
	}
	getch();
}

void piso_color (int piso,int color) {
	textbackground (piso);	/* Color del piso */
	textcolor (color);	/* Color de la letra */
}
