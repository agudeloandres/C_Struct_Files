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
	struct nodo *p,*q;
	void listar_doble (struct nodo *q);
	void insertar_final (struct nodo *p,int n);
	void copiar_listas (struct nodo *p,struct nodo *q);
	int n;

	p=localizar;
	p->info =-1;
	p->ant =p;
	p->sig = p;
	printf ("de numero a insertar\n");
	scanf ("%d",&n);
	while (n != 9999) {
		insertar_final (p,n);
		printf ("de siguiente numero\n");
		scanf ("%d",&n);
	}
	listar_doble (p);
	q=localizar;
	q->info =-1;
	q->ant =q;
	q->sig = q;
	printf ("\nde numero a insertar\n");
	scanf ("%d",&n);
	while (n != 9999) {
		insertar_final (q,n);
		printf ("de siguiente numero\n");
		scanf ("%d",&n);
	}
	listar_doble (q);
	copiar_listas (p,q);
	listar_doble (q);
}


void listar_doble (struct nodo *q)
{
	q = q->sig;
	while (q->info !=-1) {
		printf ("%d ",q->info);
		q = q->sig;
	}
	printf ("\n");
}

void insertar_final (struct nodo *p,int n)
{
	  struct nodo *q,*nuevo;

	  nuevo = localizar;
	  q = p->ant;
	  nuevo->info = n;
	  nuevo->ant = q;
	  nuevo->sig = p;
	  q->sig = p->ant = nuevo;
}

void copiar_listas (struct nodo *p,struct nodo *q)
{
	struct nodo *r;
	void liberarnodo (struct nodo *q);
	void crear_lista_vacia (struct nodo *p);
	r = q;
	q =q->sig;
	p = p->sig;
	if (p->info != -1) {
		while (  (r !=q) && (p->info != -1)  ) {
			q->info = p->info;
			q = q->sig;
			p = p->sig;
		}
		if (r == q)
			while (p->info != -1) {
				insertar_final (q,p->info);
				p = p->sig;
			}
		else {
			  p = q->ant;
			  while (q != r) {
				  liberarnodo (q);
				  q = p->sig;
			  }
		}
	}
	else crear_lista_vacia (r);
}

void liberarnodo (struct nodo *q)
{
	struct nodo *r,*s;

	r = q->ant;
	s = q->sig;
	r->sig = s;
	s->ant = r;
	free (q);
}

void crear_lista_vacia (struct nodo *p)
{
	struct nodo *q;

	q =p->sig;
	while (p != q) {
		liberarnodo (q);
		q = q->sig;
	}
}
