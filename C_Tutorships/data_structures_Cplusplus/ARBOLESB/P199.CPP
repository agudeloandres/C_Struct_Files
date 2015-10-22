#include "stdio.h"
#include "alloc.h"
#include "stdlib.h"
#define  nodo_arbol  (struct nodo *)malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *izq;
	struct nodo *der;
};

void main()
{
	struct nodo *raiz,*p,*q;
	int n;
	void ins_izq (struct nodo *p,int n);
	void ins_der (struct nodo *p,int n);
	void niveles (struct nodo *p);
	int lea_entero();
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
	niveles (raiz);
}

int lea_entero() {
	char aux[20];
	gets (aux);
	return atoi(aux);
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



#define localizar  (struct nodo_cola *)malloc (sizeof (struct nodo_cola))

struct nodo_cola {
	struct nodo *info;
	struct nodo_cola *sig;
};

void niveles (struct nodo *p)
{
	struct nodo_cola *cab;
	void iniciar (struct nodo_cola **p);
	void sumar (struct nodo_cola **p,struct nodo *objeto);
	void atender (struct nodo_cola **p, struct nodo **s);
	int vacia (struct nodo_cola *p);
	if (p) {
		iniciar (&cab);
	sumar (&cab,p);
	}
	while (!vacia (cab) )  {
		atender (&cab,&p);
		printf ("%d ",p->info);
		if (p->izq)
			sumar (&cab,p->izq);
		if (p->der)
			sumar (&cab,p->der);
	}
}

void iniciar (struct nodo_cola **p)
{
	*p = localizar;
	(*p)->sig = *p;
}

void sumar (struct nodo_cola **p,struct nodo *objeto)
{
	struct nodo_cola *nuevo;

	nuevo = localizar;
	nuevo->info = objeto;
	nuevo->sig = (*p)->sig;
	(*p)->sig = nuevo;
	*p = nuevo;
}

void atender (struct nodo_cola **p, struct nodo **s)
{
	struct nodo_cola *q,*r;

	if (*p == (*p)->sig) {
		printf ("no existen objetos para atender\n");
		*s = NULL;
	}
	else {
			q = (*p)->sig;
			r = q->sig;
			*s = r->info;
			q->sig = r->sig;
			if (q == q->sig)
				*p = q;
			free (r);
	}
}

int vacia (struct nodo_cola *p)
{
	return (p == p->sig);
}
