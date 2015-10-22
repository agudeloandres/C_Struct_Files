#include "stdio.h"
#include "conio.h"
#include "dos.h"

#define CPR(x) cprintf ("%s",x)


char *archivos [] = {
	"Inicializacion Archivos",
	"Ingreso Libreria       ",
	"Retiro Libreria        ",
	"Cambio Datos           ",
	"Estado Cuenta          ",
	"ESC para salir del menu"
};

char *actualiza [] = {
	"Cambio Datos Libreria",
	"Cambio Datos Libros  ",
	"Ingreso Libro Nuevo  ",
	"Retiro Libro         ",
	"ESC para salir       "
};

char *factura [] = {
	"Facturar         ",
	"Abonar           ",
	"Consultar Factura",
	"ESC para salir   "
};


char *listado [] = {
	"Listado Libreria",
	"Listado Libros  ",
	"Listado Facturas",
	"ESC para salir  "
};

char *termina [] = {
	"Termina  ",
	"ESC      "
};


void main ()  {
	int c,d;
	struct text_info p;
	void piso_color(int,int);
	void marco(int,int,int,int);
	void ref1 (int  ,int ,int ,char  *);
	void ref2 (int  ,int ,int ,char  *);
	void escr_menu (int ,char *[],struct text_info *,int *);


	piso_color (BLACK,WHITE);
	clrscr();
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
	marco (2,3,25,8);
	escr_menu (6,archivos,&p,&c);
	d = 0;
	if (c == 75 || c == 77) {
		d = c; c = 0;
	}
	else c = getch();
	while (c == 0) {
		if (d == 0)
			c = getch();
		else {
			c = d; d = 0;
		}
		switch (c) {
			case 77 : switch (p.winleft) {
					case 2:  ref1(1,BLACK,WHITE,
							"Archivos de datos");
						 ref2(21,WHITE,BLACK,
							"Actualizacion");
						 marco (22,3,43,7);
						 escr_menu(5,actualiza,&p,&c);
						 break;
					case 22: ref1(21,BLACK,WHITE,
							"Actualizacion");
						 ref2 (36,WHITE,BLACK,
							"Facturacion");
						 marco (37,3,54,6);
						 escr_menu(4,factura,&p,&c);
						 break;
					case 37: ref1(36,BLACK,WHITE,
							"Facturacion");
						 ref2(53,WHITE,BLACK,
							"Listados");
						 marco (54,3,70,6);
						 escr_menu(4,listado,&p,&c);
						 break;
					case 54: ref1(53,BLACK,WHITE,
							"Listados");
						 ref2(68,WHITE,BLACK,
							"Terminar");
						 marco (69,3,78,4);
						 escr_menu(2,termina,&p,&c);
						 break;
					case 69: ref1(68,BLACK,WHITE,
							"Terminar");
						 ref2(1,WHITE,BLACK,
							"Archivos de datos");
						 marco (2,3,25,8);
						 escr_menu (6,archivos,&p,&c);
						 break;
					default : cprintf ("%c",7);
				  }
				  break;
			case 75 : switch (p.winleft) {
					case 2:  ref1(1,BLACK,WHITE,
							"Archivos de datos");
						 ref2(68,WHITE,BLACK,
							"Terminar");
						 marco (69,3,78,4);
						 escr_menu(2,termina,&p,&c);
						 break;
					case 22: ref1(21,BLACK,WHITE,
							"Actualizacion");
						 ref2(1,WHITE,BLACK,
							"Archivos de datos");
						 marco (2,3,25,8);
						 escr_menu (6,archivos,&p,&c);
						 break;
					case 37: ref1(36,BLACK,WHITE,
							"Facturacion");
						 ref2(21,WHITE,BLACK,
							"Actualizacion");
						 marco (22,3,43,7);
						 escr_menu(5,actualiza,&p,&c);
						 break;
					case 54: ref1(53,BLACK,WHITE,
							"Listados");
						 ref2(36,WHITE,BLACK,
							"Facturacion");
						 marco (37,3,54,6);
						 escr_menu(4,factura,&p,&c);
						 break;
					case 69: ref1(68,BLACK,WHITE,
							"Terminar");
						 ref2(53,WHITE,BLACK,
							"Listados");
						 marco (54,3,70,6);
						 escr_menu(4,listado,&p,&c);
						 break;
					default : cprintf ("%c",7);
				  }
		}
		d = 0;
		if (c == 75 || c == 77) {
			d = c; c = 0;
		}
		else c = getch();
	}
}

void ref1 (int n,int piso,int color,char *s) {
	void piso_color(int,int);
	window (1,1,80,25);
	gotoxy (n,1);
	piso_color (piso,color);
	CPR(s);
}

void ref2 (int n,int piso,int color,char *s) {
	void piso_color(int,int);
	window (1,1,80,25);
	gotoxy (n,1);
	piso_color (piso,color);
	CPR(s);
	piso_color (BLACK,WHITE);
}


void piso_color (int piso,int color) {
	textbackground (piso);	/* Color del piso */
	textcolor (color);	/* Color de la letra */
}

void escr_menu (int n,char *a[],struct text_info *p,int *c)  {
	int i,j,d;

	piso_color (BLACK,WHITE);
	for (i=1; i < n; i++) {
		gotoxy (1,i+1);
		CPR(a[i]);
	}
	piso_color (WHITE,BLACK);
	gotoxy (1,1);
	CPR (a [0]);
	gotoxy (1,1);
	*c = getch();
	while (*c == 0) {
		*c = getch();
		switch (*c) {
			case 80: piso_color (BLACK,WHITE);
				 CPR (a [wherey() - 1]);
				 piso_color (WHITE,BLACK);
				 if (wherey() == n-1)
					gotoxy (1,1);
				 else gotoxy (1,wherey() + 1);
				 CPR (a [wherey() - 1]);
				 gotoxy (1,wherey());
				 break;
			case 72: piso_color (BLACK,WHITE);
				 CPR (a [wherey() - 1]);
				 piso_color (WHITE,BLACK);
				 if (wherey() == 1)
					gotoxy (1,n-1);
				 else gotoxy (1,wherey() - 1);
				 CPR (a [wherey() - 1]);
				 gotoxy (1,wherey());
				 break;
			case 77: break;
			case 75: break;
		}
		if (*c == 77 || *c == 75) {
			break;
		}
		else *c = getch();
	}
	piso_color (BLACK,WHITE);
	gettextinfo(p);
	window ((*p).winleft-1, (*p).wintop-1, (*p).winright+1,
		(*p).winbottom+1);
	clrscr();
}

#define si 201
#define sd 187
#define ii 200
#define id 188
#define lv 186
#define lh 205


void marco (int a,int b,int c, int d) {
	int i,j;
	void vaya(int,int);
	void escriba_c (char ,int );
	window (1,1,80,25);
	vaya (a-1,b-1);
	escriba_c (si,1);
	vaya(a,b-1);
	escriba_c(lh,c-a+1);
	vaya (c+1,b-1);
	escriba_c (sd,1);
	for (i=b; i <= d; i++ ) {
		vaya (c+1,i);
		escriba_c (lv,1);
	}
	vaya (c+1,d+1);
	escriba_c(id,1);
	vaya (a-1,d+1);
	escriba_c (ii,1);
	vaya (a,d+1);
	escriba_c(lh,c-a+1);
	for (i=b; i <= d; i++ ) {
		vaya (a-1,i);
		escriba_c (lv,1);
	}
	window (a,b,c,d);
	gotoxy (1,1);

}

void vaya(int i,int j) {
	union REGS r;

	r.h.ah = 2;
	r.h.dh = j-1;
	r.h.dl = i-1;
	r.h.bh = 0;
	int86 (0x10,&r,&r);
}


void escriba_c (char c,int veces) {
	union REGS r;

	r.h.ah = 0xa;
	r.h.al = c;
	r.h.bh = 0;
	r.x.cx = veces;
	int86 (0x10,&r,&r);
}

