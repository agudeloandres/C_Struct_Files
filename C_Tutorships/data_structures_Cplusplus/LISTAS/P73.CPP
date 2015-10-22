#include <stdio.h>
#include <alloc.h>
#define  localizar  (struct nodo *) malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *ant;
	struct nodo *sig;
};

void main()  /* genera el termino n de la secuencia de Fibonacci */
{
	struct nodo *penultimo,*ultimo,*proximo,*auxiliar;
	void sumar_listas (struct nodo *p,
				struct nodo *q,struct nodo *r);
	void listar_doble (struct nodo *q);
	void copiar_listas (struct nodo *p,struct nodo *q);
	void insertar_final (struct nodo *p,int n);
	void crear_lista_vacia (struct nodo *p);
	int n,i;

	printf ("De termino deseado.... ");
	scanf ("%d",&n);
	penultimo=localizar;
	penultimo->info =-1;
	penultimo->ant =penultimo;
	penultimo->sig = penultimo;
	ultimo=localizar;
	ultimo->info =-1;
	ultimo->ant =ultimo;
	ultimo->sig = ultimo;
	insertar_final (ultimo,1);
	proximo=localizar;
	proximo->info =-1;
	proximo->ant =proximo;
	proximo->sig = proximo;
	i = 1;
	while (i <= n) {
		copiar_listas (ultimo,penultimo);
		crear_lista_vacia (ultimo);
		auxiliar = ultimo;
		ultimo = proximo;
		proximo = auxiliar;
		sumar_listas (penultimo,ultimo,proximo);
		i++;
	}
	listar_doble (proximo);
}

#define divisor 10000

void sumar_listas (struct nodo *p,
				struct nodo *q,struct nodo *r)
{
	int v,tot,residuo;
	void adicione_r (struct nodo *p,int n);

	p = p->ant;
	q = q->ant;
	v = 0;
	while ( p->info != -1  &&  q->info != -1 ) {
		tot = p->info + q->info + v;
		residuo = tot % divisor;
		v = tot / divisor;
		adicione_r (r, residuo);
		p = p->ant;
		q = q->ant;
	}
	if (p->info == -1)
		p = q;
	while (p->info != -1) {
		tot = p->info + v;
		residuo = tot % 10000;
		v = tot / 10000;
		adicione_r (r,residuo);
		p = p->ant;
	}
	if (v != 0)
		adicione_r (r,v);
}

void adicione_r (struct nodo *p,int n)
{
	struct nodo *nuevo;

	nuevo = localizar;
	nuevo->info = n;
	nuevo->ant = p;
	nuevo->sig = p->sig;
	p->sig = nuevo;
	nuevo->sig->ant = nuevo;
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

void copiar_listas (struct nodo *p,struct nodo *q)
{
	struct nodo *r;
	void liberarnodo (struct nodo *q);
	void crear_lista_vacia (struct nodo *p);
	void insertar_final (struct nodo *p,int n);
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

