#include "stdio.h"
#include "alloc.h"
#include "stdlib.h"
#define  nodo_arbol  (struct nodo *)malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *izq;
	char i;
	struct nodo *der;
	char d;
};

void main()
/* crea un arbol tejido completo */
{
	struct nodo *raiz,*p,*q;
	void ins_izq (struct nodo *p,int n);
	void ins_der (struct nodo *p,int n);
	void inorden  (struct nodo *q);
	void inorden1  (struct nodo *q);
	int n;
	int lea_entero ();
	printf ("de numero\n");
	n = lea_entero();
	raiz = nodo_arbol;
	raiz->info = n;
	raiz->izq = NULL;
	raiz->der = NULL;
	raiz->d = 'h';
	raiz->i = 'h';
	printf ("de numero\n");
	n = lea_entero();
	while (n != 9999) {
		p = q = raiz;
		while (p->info != n &&  q  != NULL  ) {
			p = q;
			if (n < p->info)
			   if (q->i == 'a')
				q = NULL;
			   else q = q->izq;
			else if (q->d == 'a')
					q = NULL;
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
	inorden (raiz);
	printf ("\n");
	inorden1 (raiz);
	printf ("\n");
}

int lea_entero ()
{
	char linea[10];

	gets(linea);
	return (atoi (linea));
}

void ins_izq (struct nodo *p,int n)
/* inserta un nodo  en un arbol tejido completo */
{
	struct nodo *nuevo;

	nuevo = nodo_arbol;
	nuevo->info = n;
	nuevo->der = p;
	nuevo->d = 'a';
        if (p->izq)
		nuevo->i = 'a';
	else nuevo->i = 'h';
	nuevo->izq = p->izq;
	p->izq = nuevo;
	p->i = 'h';
}

void ins_der (struct nodo *p,int n)
/* inserta un nodo  en un arbol tejido completo */
{
	struct nodo *nuevo;

	nuevo = nodo_arbol;
	nuevo->info = n;
	nuevo->izq = p;
	nuevo->i = 'a';
		  if (p->der)
		nuevo->d = 'a';
	else nuevo->d = 'h';
	nuevo->der = p->der;
	p->der = nuevo;
	p->d = 'h';
}


void inorden  (struct nodo *q)
/* escribe un arbol tejido completo en inorden */
{

	while (q->izq)
		q = q->izq;
	while (q) {
		printf ("%d ",q->info);
		if (q->der)
		   if (q->d == 'h') {
			  q = q->der;
			  while (q->i == 'h')
				q = q->izq;
		   }
		   else q = q->der;
		 else q = NULL;
	}
}

void inorden1  (struct nodo *q)
/* escribe un arbol tejido completo en inorden invertido */
{

	while (q->der)
		q = q->der;
	while (q) {
		printf ("%d ",q->info);
		if (q->izq)
			if (q->i == 'h') {
			  q = q->izq;
			  while (q->d == 'h')
				q = q->der;
		   }
		   else q = q->izq;
		 else q = NULL;
	}
}
