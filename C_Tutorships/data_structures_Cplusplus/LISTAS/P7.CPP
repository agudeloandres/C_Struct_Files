#include <stdio.h>
#include <alloc.h>
#define  localizar  (struct nodo *) malloc (sizeof (struct nodo))
struct nodo {
	int info;
	struct nodo *sig;
};

void main()  /* crea una lista  */
{
	struct nodo *cab,*q;
   void escribir_lista (struct nodo *q);

	cab = localizar;
	cab->info = 1;
	q = localizar;
	q->info = 2;
	cab->sig = q;
	q->sig = localizar;
	q->sig->info = 3;
	q->sig->sig = NULL;
	escribir_lista (cab);
}

void escribir_lista (struct nodo *q)
{
	while (q != NULL) {
		printf ("%d  ",q->info);
		q = q->sig;
	}
}

