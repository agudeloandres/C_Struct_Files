#include <stdio.h>
#include "alloc.h"
#define  localizar  (struct nodo *) malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *sig;
};

void main()
{
	struct nodo *crear_lista(), *cab;
	void escribir_lista (struct nodo *q);
   struct nodo *crear_lista (int i);

	cab = crear_lista (10);
	escribir_lista (cab);

}

void escribir_lista (struct nodo *q)
{
	while (q != NULL) {
		printf ("%d  ",q->info);
		q = q->sig;
	}
}

struct nodo *crear_lista (int i)
{
	struct nodo *p,*q;

	p = NULL;
	while (i > 0) {
		q = localizar;
		q->info = i;
		q->sig = p;
		p = q;
		i = i - 1;
	}
	return (p);
}


