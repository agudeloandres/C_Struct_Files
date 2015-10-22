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
   void insertar (struct nodo **cab, struct nodo *p,
							struct nodo *q, int n);


	crear_lista1 (&cab,10);
	p = cab;
	while (p->sig != NULL )
		p = p->sig;
	insertar (&cab,(struct nodo *)NULL,cab,9999);
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

void insertar (struct nodo **cab, struct nodo *p,
							struct nodo *q, int n)
{
	struct nodo *nuevo;

	nuevo = localizar;
	nuevo->info = n;
	nuevo->sig = q;
	if (p != NULL)
		p->sig = nuevo;
	else *cab = nuevo;
}

