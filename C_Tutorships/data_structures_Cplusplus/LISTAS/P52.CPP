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
	struct nodo *cab,*p;
	void listar_doble (struct nodo *q);
	void insertar_despues_p (struct nodo *p,int n);
	int n;

	p=localizar;
	p->info =-1;
	p->ant =NULL;
	p->sig = NULL;
	printf ("de numero\n");
	scanf ("%d",&n);
	while (n != 9999) {
		insertar_despues_p (p,n);
		printf ("de numero\n");
		scanf ("%d",&n);
	}
	insertar_despues_p (p->sig->sig,3333);
	listar_doble (p);
}


void listar_doble (struct nodo *q)
{
	while (q != NULL) {
		printf ("%d ",q->info);
		q = q->sig;
	}

}

void insertar_despues_p (struct nodo *p,int n)
{
	struct nodo *nuevo,*q;

	if (p == NULL)
		printf ("no se puede insertar\n");
	else {
		 nuevo = localizar;
		 q = p->sig;
		 nuevo->info = n;
		 nuevo->ant = p;
		 nuevo->sig = q;
		 p->sig = nuevo;
		 if (q != NULL)
			q->ant = nuevo;
	}
}
