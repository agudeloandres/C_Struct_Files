/* Este menu maneja el programa que ilustra las multilistas en
		disco duro (ver programa l1inver.c) */

#define subir 72
#define bajar 80
#include "stdio.h"
#include "a:l1inver.c"
int ini_archivo(),captura(),consulta();
int uno1();
int *tareas1 [] = {
	(int *) ini_archivo,
	(int *) captura,
	(int *) consulta
};

static char *op1[] = {
	"Inicializar el archivo",
	"Capturar informacion",
	"Consultar datos",
	"Finalizar"
};

int *tareas2 [] = {
	(int *) uno1,
	(int *) uno1,
	(int *) uno1,
	(int *) uno1,
	(int *) uno1,
	(int *) uno1,
	(int *) uno1,
	(int *) uno1,
	(int *) uno1,
	(int *) uno1
};

static char *op2[] = {
	"Consulta por edades",
	"Listado de hombres",
	"Listado de mujeres",
	"Educacion primaria",
        "Educacion secundaria",
	"Educacion universitaria",
	"Listado de solteros",
	"Listado de casados",
	"Listado de divorciados",
	"Listado de viudos",
	"Final"
};

main()
{
	menuprincipal (op1,4,2,50,15,3,6,
		"MENU PRINCIPAL",4,6,3,tareas1);
}

menuprincipal (op,a,c,b,d,k,l,nombre,cuantos,dondex,dondey,tareas)
char *op[];
int a,c,b,d,k,l;
char *nombre;
int cuantos,dondex,dondey;
int *tareas;
{
	int i,j,seguir,guardar,w,v;
	char c1;

	inver1 (0,15);
	window (1,1,80,24);
	clrscr();
	guardar = k;
	do {
		marco (a,c,b,d);
		clrscr();
		inver1 (15,0);
		w = b-a;
		v = w - strlen (nombre);
		v = v / 2;
		for (w = 1; w < v; w++)
			cprintf ("%c",' ');
		cprintf ("%s",nombre);
		for (w = 1; w < v; w++)
			cprintf ("%c",' ');
		inver1 (0,15);
		menu(guardar,op,cuantos,dondex,dondey);
		c1=getch();
		while(c1==0) {
			c1=getch();
			switch (c1) {
			   	case subir :i=wherey();
					    if (wherey() == k)
						gotoxy (dondex,l);
					    else gotoxy (dondex,wherey()-1);
                                            j=wherey();
					    refres(i,j,op,
						cuantos,dondex,dondey);
				    	    break;
				case bajar :i=wherey();
					    if (wherey() == l)
						gotoxy (dondex,k);
					    else gotoxy (dondex,wherey()+1);
					    j=wherey();
					    refres(i,j,op,
						cuantos,dondex,dondey);
					    break;
			}
			c1=getch();
		}
		for (i=0, seguir = 0;i< cuantos - 1 && !seguir;i++) {
			if (wherey() == i + dondey) {
				gotoxy (dondex,i);
				normal();
				guardar = i + dondey;
                                proceso (tareas[i],i);
				seguir = 1;
			 }
		}
        } while (wherey() != dondey + cuantos - 1);

}


menu(j,op,cuantos,dondex,dondey)
int j;
char *op[];
int cuantos;
int dondex,dondey;
{
	int i,seguir;

	gotoxy (dondex,dondey);
	inver1 (0,15);
	for (i=0; i < cuantos ; i++) {
		gotoxy (dondex,dondey+i);
		cprintf ("%s",op[i]);
	}
	for (i=0, seguir = 0; i < cuantos && !seguir; i++) {
		if (j == i + dondey) {
			gotoxy (dondex,i+dondey);
			inver1 (15,0);
			cprintf ("%s",op[i]);
			seguir = 1;
		 }
	}
}

refres (i,j,op,cuantos,dondex,dondey)
int i,j;
char *op[];
int cuantos,dondex,dondey;
{
	int k,seguir;

	for (k=0,seguir = 0; k < cuantos && !seguir; k++)
		if (k == i - dondey) {
			  gotoxy (dondex,k+dondey);
			  textbackground (0);  textcolor(15);
			  cprintf ("%s",op[k]);
			  seguir = 1;
		}
	for (k=0,seguir = 0; k < cuantos && !seguir; k++)
		if (k == j - dondey) {
			  gotoxy (dondex,k + dondey);
			  textbackground (15);  textcolor(0);
			  cprintf ("%s",op[k]);
			  seguir = 1;
		}
}

normal ()
{
	textbackground (0);
	textcolor (15);
	clrscr();
}

#define PV(x) printf ("%c",x)
marco (a,c,b,d)
int a,b,c,d;
{
	int i;

	window (1,1,80,24);
	gotoxy (a,c); PV(201);
	gotoxy (a,d); PV(200);
	for (i=a+1; i<=b-1; i++) {
		gotoxy (i,c); PV(196);
		gotoxy (i,d); PV(196);
	}
	gotoxy (b,c); PV(187);
	gotoxy (b,d); PV(188);
        for (i=c+1; i<=d-1; i++) {
		gotoxy (a,i); PV(179);
		gotoxy (b,i); PV(179);
	}
	window (a+1,c+1,b-1,d-1);
	gotoxy (1,1);
}

inver1 (i,j)
int i,j;
{
	textbackground (i);
	textcolor(j);
}

proceso (f,x)
int (*f)();
int x;
{
	(*f)(x);
}


consulta ()
{
	menuprincipal (op2,29,2,70,22,3,13,
	"MENU CONSULTA",11,3,3,tareas2);
	window (1,1,80,24);
	inver1 (0,15);
	clrscr();
}

uno1(x)
int x;
{
	consult_1 (x);
}