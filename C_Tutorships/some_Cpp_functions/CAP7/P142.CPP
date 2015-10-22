#include "stdio.h"
#include "conio.h"
#define CPR(x) cprintf ("%s",x)
void main ()  {
	int c;
	void marco (int a, int b, int c, int d);
	void ref2 (int ,int ,int ,char *);
	void ref1 (int ,int ,int ,char *);
	void piso_color(int,int);
	struct text_info p;

	piso_color (BLACK,WHITE);
	clrscr();
	window (1,1,80,25);
	piso_color (WHITE,BLACK);
	CPR("Archivos de datos");
	gotoxy (21,1);
	piso_color (BLACK,WHITE);
	CPR("Actualizacion");
	gotoxy (36,1);
	piso_color (BLACK,WHITE);
	CPR("Facturacion");
	gotoxy (53,1);
	CPR("Listados");
	gotoxy (68,1);
	CPR("Terminar");
	piso_color (BLACK,WHITE);
	gotoxy (1,1);
	c = getch();
	while (c == 0) {
		c = getch();
		switch (c) {
			case 77 : switch (wherex()) {
					case 1:  ref1(1,BLACK,WHITE,
							"Archivos de datos");
						 ref2(21,WHITE,BLACK,
							"Actualizacion");
						 break;
					case 21: ref1(21,BLACK,WHITE,
							"Actualizacion");
						 ref2 (36,WHITE,BLACK,
							"Facturacion");
						 break;
					case 36: ref1(36,BLACK,WHITE,
							"Facturacion");
						 ref2(53,WHITE,BLACK,
							"Listados");
						 break;
					case 53: ref1(53,BLACK,WHITE,
							"Listados");
						 ref2(68,WHITE,BLACK,
							"Terminar");
						 break;
					case 68: ref1(68,BLACK,WHITE,
							"Terminar");
						 ref2(1,WHITE,BLACK,
							"Archivos de datos");
						 break;
				  }
				  break;
			case 75 : switch (wherex()) {
					case 1:  ref1(1,BLACK,WHITE,
							"Archivos de datos");
						 ref2(68,WHITE,BLACK,
							"Terminar");
						 break;
					case 21: ref1(21,BLACK,WHITE,
							"Actualizacion");
						 ref2(1,WHITE,BLACK,
							"Archivos de datos");
						 break;
					case 36: ref1(36,BLACK,WHITE,
							"Facturacion");
						 ref2(21,WHITE,BLACK,
							"Actualizacion");
						 break;
					case 53: ref1(53,BLACK,WHITE,
							"Listados");
						 ref2(36,WHITE,BLACK,
							"Facturacion");
						 break;
					case 68: ref1(68,BLACK,WHITE,
							"Terminar");
						 ref2(53,WHITE,BLACK,
							"Listados");
						 break;
				  }
		}
		c = getch();
	}
}

void ref1 (int n,int piso,int color,char *s) {
	void piso_color(int,int);
	gotoxy (n,1);
	piso_color (piso,color);
	CPR(s);
}

void ref2 (int n,int piso,int color,char *s) {
	void piso_color(int,int);
	gotoxy (n,1);
	piso_color (piso,color);
	CPR(s);
	gotoxy (n,1);
}


void piso_color (int piso,int color) {
	textbackground (piso);	/* Color del piso */
	textcolor (color);	/* Color de la letra */
}

