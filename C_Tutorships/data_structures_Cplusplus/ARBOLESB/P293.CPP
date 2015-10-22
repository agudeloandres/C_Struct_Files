/* EN ESTE PROGRAMA SE MUESTRAN LAS RUTINAS QUE RETIRAN UNO O
   MAS NODOS DE UN ARBOL BINARIO */

#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define  nodo_arbol  (struct nodo *)malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *izq;
	struct nodo *der;
};

void main()
{
	void borrar_nodo (struct nodo **raiz,struct nodo *q,
				struct nodo *p);

	struct nodo *raiz,*p,*q;
	int n,si,encontro;
	void inorden (struct nodo *);
	void ins_der (struct nodo *p,int n);
	void ins_izq (struct nodo *p,int n);
	int lea_entero ();
	printf ("de numero\n");
	n = lea_entero();
	raiz = nodo_arbol;
	raiz->info = n;
	raiz->izq = NULL;
	raiz->der = NULL;
	printf ("de numero\n");
	n = lea_entero();
	while (n != 9999) {
		p = q = raiz;
		while (p->info != n &&  q  != NULL ) {
			p = q;
			if (n < p->info)
				q = q->izq;
			else q = q->der;
		}
		if (p->info == n)
		   printf ("numero repetido\n");
	     else if (n < p->info)
				ins_izq (p,n);
			else  ins_der (p,n);
		printf ("de numero\n");
		n = lea_entero ();
	}
	printf ("Desea retirar un nodo ? (s/n) \n");
	si = getch();
	while (si == 's') {
		printf ("\nDe nodo a retirar \n");
		n=lea_entero();
		p=raiz;
		q=NULL;
		encontro = 0;
		while (p && !encontro)
			if (p->info == n)
				encontro = 1;
			else {
					q = p;
					if (n < p->info)
						p = 	p->izq;
					else p = p->der;
				}
		if (!encontro)
			printf ("No existe\n");
		else borrar_nodo (&raiz,q,p);
		printf ("Desea retirar mas nodos? (s/n) \n");
		si = getch();
	}
	printf ("\n");
	inorden (raiz);
	printf ("\n");
}

int lea_entero ()
{
	char linea[10];

	gets(linea);
	return (atoi(linea));
}

void ins_izq (struct nodo *p,int n)
{
	struct nodo *nuevo;

	nuevo = nodo_arbol;
	nuevo->info = n;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	p->izq = nuevo;
}


void ins_der (struct nodo *p,int n)
{
	struct nodo *nuevo;

	nuevo = nodo_arbol;
	nuevo->info = n;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	p->der = nuevo;
}

void inorden (struct nodo *p) {
	if (p!= NULL) {
		inorden (p->izq);
		printf ("%d ",p->info);
		inorden (p->der);
	}
}


void borrar_nodo (struct nodo **raiz,struct nodo *q,
				struct nodo *p)
{
	struct nodo *r,*t,*s;

	if (p->izq == NULL)
		r = p->der;
	else if (p->der == NULL)
		   r = p->izq;
	else  {
			s = p;
			r = p->der;
			t = r->izq;
			while (t) {
				s = r;
				r = t;
				t = t->izq;
			}
			if (p != s) {
				s->izq = r->der;
				r->der = p->der;
			}
			r->izq = p->izq;
		}
	if (q == NULL)
		*raiz = r;
	else if (p == q->izq)
			q->izq = r;
		else q->der = r;
	free (p);
}
