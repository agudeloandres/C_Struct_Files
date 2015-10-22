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
	struct nodo *p;
	void retirar_nodo (struct nodo **cab,
			struct nodo *p,int *dato);
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
	retirar_nodo (&p,p->sig->sig,&n);
	printf ("retirado...%d\n",n);
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

void retirar_nodo (struct nodo **cab,struct nodo *p,int *dato)
{
	struct nodo *r,*q;

	if (p == NULL)
		printf ("no se puede retirar un nodo");
	else {
			*dato = p->info;
			r = p->ant;
			q = p->sig;
			if (r == NULL)
				if (q == NULL) {
						*cab = NULL;
						printf ("la lista quedo vacia\n");
				}
				else  {
				  *cab = p->sig;
				  q->ant = NULL;
				}
			else  if (q == NULL)
				  r->sig = NULL;
			else  {
					 r->sig = q;
					 q->ant = r;
			}
			free (p);
	}
}
