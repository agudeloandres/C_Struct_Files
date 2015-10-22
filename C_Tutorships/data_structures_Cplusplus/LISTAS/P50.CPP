#include <stdio.h>
#include <alloc.h>
#define  localizar  (struct nodo *) malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *ant;
	struct nodo *sig;
};

void main()
{
	struct nodo *cab,*q;

	cab = localizar;
	cab->info = 1;
	cab->ant = NULL;
	q = localizar;
	q->info =2;
	q->ant = cab;
	cab->sig = q;
	q = localizar;
	q->info = 3;
	cab->sig->sig = q;
	q->ant = cab->sig;
	q->sig =NULL;
	while (q != NULL) {
		printf ("%d ",q->info);
		q = q->ant;
	}
	q = cab;
	while (q != NULL) {
		printf ("%d ",q->info);
		q = q->sig;
	}

}
