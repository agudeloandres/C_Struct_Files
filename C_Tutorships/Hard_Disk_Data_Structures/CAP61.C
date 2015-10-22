/* Maneja un cursor arbol binario en memoria. Este programa se ejecuta
	desde el programa mcurarbo.c */

#include "stdio.h"
#define MAXIMO 40
#define P(x) printf ("%s\n",x)
typedef struct CURSOR CURSOR;
struct CURSOR {
	int info;
	int izq;
	int der;
};

CURSOR a[MAXIMO];

captu ()
{
	capturar (a);
}

consul ()
{
	consul1 (a);
}

retirar ()
{
	retirar1 (a);
}

listar ()
{
	inorden (a);
}

inicializar ()
{
	init_cursor (a);
}

capturar (CURSOR a[])
{
	int n;

	P("De numero");
	n = lea_entero();
	while (n != 9999) {
		if (insertar (a, n) == -1)
			P("Repetido...");
		else P("Insertado...");
		P("De numero");
		n = lea_entero();
	}
}

consul1 (CURSOR a[])
{
	int n;

	P("De numero");
	n = lea_entero();
	while (n != 9999) {
		if (consultar (a, n) == -1)
			P("No existe. Trate otra vez...");
		else P("Si existe...");
		P("De numero");
		n = lea_entero();
	}
}

retirar1 (CURSOR a[])
{
	int n;

	P("De numero a retirar...");
	n = lea_entero();
	while (n != 9999) {
		if (borrar (a, n) == -1)
			P("No existe. Trate otra vez...");
		else P("retirado... ");
		P("De numero");
		n = lea_entero();
	}
}


lea_entero()
{
	char a[10];

	gets (a);
	return (atoi (a));
}

init_cursor (CURSOR a[])
{
	int i;

	a[0].izq = 0;
	for (i=0; i < MAXIMO; i++)
		a[i].der = i + 1;
	a[i-1].der = 0;
}

insertar (CURSOR a[], int n)
{
	int p, q, enc = 0, prox;

	if (a[0].izq == 0) {          /* Para controlar cursor vacio */
		prox = disp (a);
		a[prox].info = n;
		a[prox].izq = a[prox].der = 0;
		a[0].izq = prox;
		return (0);
	}
	p = q = a[0].izq;
	while ( p != 0 && !enc) {
		q = p;
		if (n < a[p].info)
			p = a[p].izq;
		else if (n > a[p].info)
			p = a[p].der;
		else enc = 1;
	}
	if (enc == 1)
		return (-1);
	prox = disp (a);
	if (prox != -1) {
		a[prox].info = n;
		a[prox].izq = a[prox].der = 0;
		if (n < a[q].info)
			a[q].izq = prox;
		else a[q].der = prox;
	}
	else {
		P("Cursor lleno...");
		getch();
		exit ();
	}
	return (0);
}

consultar (CURSOR a[], int n)
{
	int p,enc = 0;

	p = a[0].izq;
	while ( p != 0 && !enc) {
		if (n < a[p].info)
			p = a[p].izq;
		else if (n > a[p].info)
			p = a[p].der;
		else enc = 1;
	}
	if (enc != 1)
		return (-1);
	else return (p);
}

borrar (CURSOR a[], int n)
{
	int p, q, enc = 0, prox;

	q = 0;
	p = a[0].izq;
	while ( p != 0 && !enc) {
		if (n < a[p].info) {
			q = p;
			p = a[p].izq;
		}
		else if (n > a[p].info) {
			q = p;
			p = a[p].der;
		}
		else enc = 1;
	}
	if (enc == 1) {
		borrar_elemento (a,q,p);
		return (0);
	}
	else return (-1);
}


disp (CURSOR a[])
{
	int i = a[0].der;

	if (i == 0)
		return (-1);
	else {
		a[0].der = a[i].der;
		return (i);
	}
}


borrar_elemento (CURSOR a[],int q,int p)
{
	int r,t,s;

	if (a[p].izq == 0)
		r = a[p].der;
	else if (a[p].der == 0)
		r = a[p].izq;
	else {
		s = p;
		r = a[p].der;
		t = a[r].izq;
		while (t != 0) {
			s = r;
			r = t;
			t = a[t].izq;
		}
		if (p != s) {
			a[s].izq = a[r].der;
			a[r].der = a[p].der;
		}
		a[r].izq = a[p].izq;
	}
	if (q == 0)
		a[0].izq = r;
	else if (p == a[q].izq)
		a[q].izq = r;
	else a[q].der = r;
	liberar (a,p);
}

liberar (CURSOR a[],int p)
{
	a[p].der = a[0].der;
	a[0].der = p;
}

typedef struct LIFO LIFO;
struct LIFO {
	int t;
	int a[MAXIMO];
};

inorden (CURSOR a[])
{
	LIFO pila;
	int p = a[0].izq;

	init_pila (&pila);
	while (p != 0) {
		ins_pila (&pila,p);
		p = a[p].izq;
	}
	while (!pila_vacia (&pila) ) {
		retira_pila(&pila,&p);
		printf ("%d ",a[p].info);
		p = a[p].der;
                while (p != 0) {
			ins_pila (&pila,p);
			p = a[p].izq;
		}
	}
}

init_pila (LIFO *p)
{
	p->t = 0;
}

pila_vacia (LIFO *p)
{
	return (p->t == 0);
}

ins_pila (LIFO *p,int s)
{
	if (p->t == MAXIMO) {
		printf ("pila llena...");
		getch();
		exit (1);
	}
	else {
		p->a [p->t] = s;
		p->t++;
	}
}

retira_pila (LIFO *p, int *s)
{
	if (pila_vacia (p) ) {
		printf ("pila vacia...");
		getch();
		exit (1);
	}
	else {
		p->t--;
		*s = p->a [p->t];
	}
}




