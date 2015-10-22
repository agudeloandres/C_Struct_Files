#include <stdio.h>
#include <alloc.h>
#include <string.h>

#define  localizar  (struct nodo *) malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *ant;
	struct nodo *sig;
};
	struct nodo *cab,*p,*q,*r;
	int n;


void main()
{
	struct nodo *p,*q,*r;
	int n;
	void sumar_listas (struct nodo *p,struct nodo *q,struct nodo *r);
	void listar_doble (struct nodo *q);
	void insertar_final (struct nodo *p,int n);
	p=localizar;
	p->info =-1;
	p->ant =p;
	p->sig = p;
	printf("Conforme grupos de numeros de 4 digitos\n");
	printf("desde el ultimo digito hacia el primero\n");
	printf("y luego cada vez que el programa le pida\n");
	printf("un numero, de cada grupo desde el primero\n");
	printf("(mas hacia la izquierda) hasta el	final\n");
	printf ("de el primer numero\n");
	scanf ("%d",&n);
	while (n != 9999) {
		insertar_final (p,n);
		printf ("de siguiente numero. 9999 para terminar\n");
		scanf ("%d",&n);
	}

	listar_doble (p);
	q=localizar;
	q->info =-1;
	q->ant =q;
	q->sig = q;
	printf("Conforme grupos de numeros de 4 digitos\n");
	printf("desde el ultimo digito hacia el primero\n");
	printf("y luego cada vez que el programa le pida\n");
	printf("un numero, de cada grupo desde el primero\n");
	printf("(mas hacia la izquierda) hasta el	final\n");
	printf ("de el primer numero. 9999 para terminar\n");
	printf ("Segundo numero\n");
	scanf ("%d",&n);
	while (n != 9999) {
		insertar_final (q,n);
		printf ("de siguiente numero\n");
		scanf ("%d",&n);
	}
	listar_doble (q);
	r=localizar;
	r->info =-1;
	r->ant =r;
	r->sig = r;
	sumar_listas (p,q,r);
	printf ("Resultado\n");
	listar_doble (r);

	}

#define divisor 10000
void sumar_listas (struct nodo *p,struct nodo *q,struct nodo *r)
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
		printf ("%d",q->info);
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

