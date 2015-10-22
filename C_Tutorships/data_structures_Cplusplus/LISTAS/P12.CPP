#include <stdio.h>
#include <alloc.h>
#define  localizar  (struct nodo *) malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *sig;
};

void main()
{
	struct nodo  *cab;
	void escribir_lista (struct nodo *q);
	void crear_lista1 (struct  nodo **p, int i);

	crear_lista1 (&cab,10);
	escribir_lista (cab);

}

void escribir_lista (struct nodo *q)
{
	while (q != NULL) {
		printf ("%d  ",q->info);
		q = q->sig;
	}
}

void crear_lista1 (struct  nodo **p, int i)
{
	struct nodo *q;

	*p = NULL;
	while (i > 0) {
		q = localizar;
		q->info = i;
		q->sig = *p;
		*p = q;
		i = i - 1;
	}
}


