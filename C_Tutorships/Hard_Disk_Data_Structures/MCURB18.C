
/* Este menu maneja el programa cap18.c */

#include  "stdio.h"
#include "a:cap18.c"

#define subir 72
#define bajar 80
#define WTODO window (1,1,80,25)


int uno(), dos(), tres();
int uno1(),dos1(),tres1();
int cuatro (),cinco();
int *tareas1 [] = {
	(int *) uno,
	(int *) dos,
	(int *) tres,
	(int *) cuatro,
	(int *) cinco
};

static char *op1[] = {
	"INICIALIZAR CURSOR ARBOL B+",
	"CAPTURAR",
	"CONSULTAR",
	"BORRAR",
	"LISTAR",
	"FINALIZAR"
};


main()
{
	/* LAS PRIMERAS CUATRO, LA VENTANA*/
	/* LAS SIGUIENTES DOS, DONDE COMIENZA Y DONDE TERMINA */
	/* CUANTAS OPCIONES (SIN CONTAR FINALIZACION */
	/* DONDE ESTA UBICADO EL MENU, DENTRO DE LA VENTANA */
	menuprincipal (op1,10,10,70,20,3,8,
		"MENU PRINCIPAL ARBOLES B+",6,15,3,tareas1);
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

#define P1(x) printf ("%c",x)
marco (a,c,b,d)
int a,b,c,d;
{
	int i;

	window (1,1,80,24);
	gotoxy (a,c); P1(201);
	gotoxy (a,d); P1(200);
	for (i=a+1; i<=b-1; i++) {
		gotoxy (i,c); P1(196);
		gotoxy (i,d); P1(196);
	}
	gotoxy (b,c); P1(187);
	gotoxy (b,d); P1(188);
        for (i=c+1; i<=d-1; i++) {
		gotoxy (a,i); P1(179);
		gotoxy (b,i); P1(179);
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


uno ()
{
	WTODO;
	clrscr();
	cprintf ("Inicializando...");
	inicia ();
	cprintf ("Oprima una tecla...");
	getch();
	clrscr();
}

dos ()
{
	WTODO;
	clrscr();
	captu();
	clrscr();
}

tres()
{
	WTODO;
	clrscr();
	consul();
	clrscr();
}

cuatro ()
{
	WTODO;
	clrscr();
	retira();
	clrscr();
}

cinco ()
{
	WTODO;
	clrscr();
	listar();
	clrscr();
}


