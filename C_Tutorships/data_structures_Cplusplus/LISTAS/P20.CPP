#include <stdio.h>
#include <alloc.h>
#define  localizar  (struct nodo *) malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *sig;
};

void main()
{
	struct nodo  *p,*cab;
	void escribir_lista (struct nodo *q);
	void crear_lista1 (struct  nodo **p, int i);
	void insertar_antes (struct nodo *p, int n);

	crear_lista1 (&cab,10);
	p = cab;
	while (p->sig != NULL )
		p = p->sig;
	insertar_antes (cab->sig,8888);
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

void insertar_antes (struct nodo *p, int n)
{
	struct nodo *nuevo;

	if (p == NULL)
		printf ("no se puede insertar");
	else  {
		  nuevo = localizar;
		  nuevo->info = p->info;
		  nuevo->sig = p->sig;
		  p->info = n;
		  p->sig = nuevo;
	}
}
