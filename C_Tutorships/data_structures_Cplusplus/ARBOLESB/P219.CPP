#include "stdio.h"
#include "alloc.h"
#include "stdlib.h"
#include "conio.h"
#define  nodo_arbol  (struct nodo *)malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *izq;
	struct nodo *der;
	char d;
};

void main()  /* crea un arbol tejido por la derecha  */
{
	struct nodo *raiz,*p,*q;
	int n;
	void inorden (struct nodo *p);
	int lea_entero ();
	void ins_izq (struct nodo *p,int n);
	void ins_der (struct nodo *p,int n);
	printf ("de numero\n");
	n = lea_entero();
	raiz = nodo_arbol;
	raiz->info = n;
	raiz->izq = NULL;
	raiz->der = NULL;
	raiz->d = 'h';
	printf ("de numero\n");
	n = lea_entero();
	while (n != 9999) {
		p = q = raiz;
		while (p->info != n &&  q  != NULL  ) {
			p = q;
			if (n < p->info)
				q = q->izq;
			else if (q->d == 'a')
					q = NULL;
				else	q = q->der;
		}
		if (p->info == n)
			printf ("numero repetido\n");
		  else if (n < p->info)
				ins_izq (p,n);
			else  ins_der (p,n);
		printf ("de numero\n");
		n = lea_entero ();
	}
	inorden (raiz);
}

int lea_entero ()
{
	char linea[10];

	gets (linea);
	return (atoi (linea));
}

void ins_izq (struct nodo *p,int n)
/* inserta un nodo  en un arbol tejido por la derecha */
{
	struct nodo *nuevo;

	nuevo = nodo_arbol;
	nuevo->info = n;
	nuevo->izq = NULL;
	nuevo->der = p;
	nuevo->d = 'a';
	p->izq = nuevo;
}

void ins_der (struct nodo *p,int n)
/* inserta un nodo en un arbol tejido por la derecha */
{
	struct nodo *nuevo;

	nuevo = nodo_arbol;
	nuevo->info = n;
	nuevo->izq = NULL;
	if (p->der)
		nuevo->d = 'a';
	else	nuevo->d = 'h';
	nuevo->der = p->der;
	p->der = nuevo;
	p->d = 'h';

}


void inorden (struct nodo *p)
/* escribe un arbol tejido por la derecha en inorden */
{
	struct nodo *q;

	while (p) {
		q = p;
		p = p->izq;
	}
	while (q) {
		printf ("%d ",q->info);
		if (q->der)
			if (q->d == 'h') {
			  q = q->der;
			  p = q;
			  while (p) {
				q = p;
				p = p->izq;
			  }
			}
			else  q = q->der;
		else  q = NULL;
	}
}
