#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "conio.h"
#include "process.h"
#define CPR(x) cprintf ("%s",x)

// Para ejecutar se deben compilar los programas a ser llamados.

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
void piso_color(int a,int b) {
	textbackground (a);
	textcolor (b);
}

char *op[] = {
	"Ingreso Libreria ",
	"Retiro Libreria  ",
	"Cambio de Datos  ",
	"Estado de cuenta ",
	"Consulta Libreria"
};

void main ()  {
	int i,j,c;
	void piso_color (int,int );
	piso_color (BLACK,WHITE);
	void marco(int,int,int,int);
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
	if (c == 27) {
		clrscr();
		exit(1);
	}

	/* execl(), solamente busca en el directorio actual */
	int E;
	switch (wherey() ) {
		case 1 : E=execl ("c:\\bc\\work1\\ingreso.exe",
							"c:\\bc\\work1\\ingreso.exe","key1",NULL);
					if (E==-1) {
						printf ("error1\n");
						getch();
						exit (1);
					}
					break;
		case 2 : E=execl ("c:\\bc\\work1\\retiro.exe",
							"c:\\bc\\work1\\retiro.exe","key2",NULL);
					if (E==-1) {
						printf ("error2\n");
						getch();
						exit (1);
					}
					break;
		case 3 : E=execl ("c:\\bc\\work1\\cambio.exe",
							"c:\\bc\\work1\\cambio.exe","key3",NULL);
					if (E==-1) {
						printf ("error3\n");
						getch();
						exit (1);
					}
					break;
		case 4 : E=execl ("c:\\bc\\work1\\estado.exe",
							"c:\\bc\\work1\\estado.exe","key4",NULL);
					if (E==-1) {
						printf ("error4\n");
						getch();
						exit (1);
					}
					break;
		case 5 : E=execl ("c:\\bc\\work1\\consulta.exe",
						"c:\\bc\\work1\\consulta.exe","key5",NULL);
					if (E==-1) {
						printf ("error5\n");
						getch();
						exit (1);
					}
					break;
		default : printf ("error en el manejo del menu\n");
				getch();
				exit (1);
	}
}


