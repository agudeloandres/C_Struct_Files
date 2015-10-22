/* INSERTA DATOS EN UN CUROSR LISTA EN MEMORIA */

#include "stdio.h"
#include "stdlib.h"
#define MAXIMO 10
typedef struct CURSOR CURSOR;
struct CURSOR {
	int info,sig;
};

init_cursor (CURSOR a[])
{
	int i;
	a[0].info = 0;
	for (i=0; i < MAXIMO ; i++)
		a[i].sig = i+1;
	a[i-1].sig = 0;
}


insertar (CURSOR a[],int n)
{
	int p,q,enc,prox;

	p = a[0].info;
	q = enc = 0;
	while (p != 0 && !enc) {
		if (n > a[p].info) {
			q = p; p = a[p].sig;
		}
		else enc = 1;
	}
	if (enc == 1)
		if (a[p].info == n)
			return (-1);
	prox = disp(a);
	if (prox != -1) {
		a[prox].info = n;
		a[prox].sig = p;
		if (q == 0)
			a[0].info = prox;
		else a[q].sig = prox;
	}
	else {
		printf ("lista llena...\n");
		getch();
		exit (1);
	}
}

disp (CURSOR a[])
{
	int i;

	i = a[0].sig;
	if (i==0)
		return (-1);
	else  {
			a[0].sig = a[i].sig;
			return (i);
	}
}


main ()
{
	int n;
	CURSOR a[MAXIMO];

	init_cursor (a);
	printf ("de numero\n");
	n = lea();
	while (n != 9999) {
		if (insertar (a,n) == -1)
			printf ("repetido\n");
		else printf ("insertado....\n");
		printf ("de numero\n");
		n = lea();
	}
	escribir (a);
	getch();
}

lea ()
{
	char a[10];

	gets (a);
	return (atoi (a));
}

escribir (CURSOR a[])
{
	int i;

	i = a[0].info;
	while (i!= 0) {
		printf ("%d\n",a[i].info);
		i = a[i].sig;
	}
}


liberar (CURSOR a[],int p)
{
	a[p].sig = a[0].sig;
	a[0].sig = p;
}


