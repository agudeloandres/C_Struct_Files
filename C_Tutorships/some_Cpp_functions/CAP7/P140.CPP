#include "stdio.h"
#include "conio.h"
#define CPR(x) cprintf ("%s",x)

char *op[] = {
	"Ingreso Libreria ",
	"Retiro Libreria  ",
	"Cambio de Datos  ",
	"Estado de cuenta ",
	"Consulta Libreria"
};

void main ()  {
	int i,j,c;
	void marco (int , int , int , int );
	void piso_color(int,int);
	piso_color (BLACK,WHITE);
	clrscr();
	marco (10,10,27,14);
	for (i=1; i < 5; i++) {
		gotoxy (1,i+1);
		CPR(op[i]);
	}
	piso_color (WHITE,BLACK);
	gotoxy (1,1);
	CPR (op [0]);
	gotoxy (1,1);
	c = getch();
	while (c == 0) {
		c = getch();
		switch (c) {
			case 80: piso_color (BLACK,WHITE);
				 CPR (op [wherey() - 1]);
				 piso_color (WHITE,BLACK);
				 if (wherey() == 5)
					gotoxy (1,1);
				 else gotoxy (1,wherey() + 1);
				 CPR (op [wherey() - 1]);
				 gotoxy (1,wherey());
				 break;
			case 72: piso_color (BLACK,WHITE);
				 CPR (op [wherey() - 1]);
				 piso_color (WHITE,BLACK);
				 if (wherey() == 1)
					gotoxy (1,5);
				 else gotoxy (1,wherey() - 1);
				 CPR (op [wherey() - 1]);
				 gotoxy (1,wherey());
				 break;
		}
		c = getch();
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

