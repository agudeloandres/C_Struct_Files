

/* INSERTA DATOS EN UN CURSOR LISTA DOBLEMENTE ENCADENADO EN MEMORIA */

#include "stdio.h"
#include "stdlib.h"
#define MAXIMO 20
#define P(x)  printf ("%s\n",x)
typedef struct CURSOR CURSOR;

struct CURSOR {
	int ant;
	int info;
	int sig;
};

main()
{
	CURSOR a[MAXIMO];
	int n;

	init_cursor (a);
	P("De numero");
	n = lea_entero();
	while (n != 9999) {
		if (insertar (a, n) == -1)
			P("Repetido");
		else P("Insertado");
		P("De numero");
		n = lea_entero();
	}
	escribir (a);
	getch();
}

init_cursor (CURSOR a[])
{
	int i;

	a[0].ant = a[0].info = 0;
	for (i=0; i < MAXIMO; i++)
		a[i].sig = i + 1;
	a[i - 1].sig = 0;
}

lea_entero()
{
	char a[10];

	gets (a);
	return (atoi (a));
}


escribir (CURSOR a[])
{
	int i= a[0].ant;

	while (i != 0) {
		printf ("%d ",a[i].info);
		i = a[i].sig;
	}
	P("\n");
	i = a[0].info;
	while (i != 0) {
		printf ("%d ",a[i].info);
		i = a[i].ant;
	}
}

mantener1 (CURSOR a[],int n)
{
	int p,q,enc,prox;

	p = a[0].ant;
	enc = q = 0;
	while (p != 0 && !enc) {
		if (n > a[p].info) {
			q = p;
			p = a [p].sig;
		}
		else enc = 1;
	}
	if (enc == 1)
		if (a[p].info == n)
			return (-1);
	prox = disp (a);
	if (prox != -1) {
		a [prox].info = n;
		a [prox].sig = p;
		a [prox].ant = q;
		if (p == 0)
			a [0].info = prox;
		else a [p].ant = prox;
		if (q == 0) {
			a [0].ant = prox;
			a [p].ant = prox;
		}
		else a[q].sig = prox;
	}
	else {
		P("Lista llena...");
		getch();
		exit (1);
	}
}

disp1 (CURSOR a[])
{
	int i = a[0].sig;

	if (i==0)
		return (-1);
	else {
		a[0].sig = a[i].sig;
		return (i);
	}
}


liberar1 (CURSOR a[],int p)
{
	a[p].sig = a[0].sig;
	a[0].sig = p;
}
