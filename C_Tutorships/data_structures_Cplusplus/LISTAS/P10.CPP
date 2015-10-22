#include "stdio.h"
#include "alloc.h"
#define  localizar  (struct nodo *) malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *sig;
};

void main()   /* crea una lista */
{
	struct nodo *cab,*q;
	int i = 10;
	void escribir_lista (struct nodo *q);

	cab = NULL;
	while (i > 0) {
		q = localizar;
		q->info = i;
		q->sig = cab;
		cab = q;
		i = i - 1;
	}
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