#include <stdio.h>
#include <alloc.h>
#define  nodo_arbol  (struct nodo *)malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *izq;
	struct nodo *der;
};

void main()
{
	struct nodo *raiz,*q;
	void ins_izq (struct nodo *p,int n);
	void ins_der (struct nodo *p,int n);
	void inorden (struct nodo *p);
	raiz = nodo_arbol;
	raiz->info = 10;
	raiz->izq = NULL;
	raiz->der = NULL;
	ins_izq (raiz,5);
	ins_der (raiz,15);
	q = raiz->izq;
	ins_der (q,7);
	q = raiz->der;
	ins_izq (q,12);
	inorden (raiz); /* DESPUES SE EXPLICA ESTA RUTINA */
}

void ins_izq (struct nodo *p,int n)
{
	struct nodo *nuevo;

	nuevo = nodo_arbol;
	nuevo->info = n;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	p->izq = nuevo;
}

void ins_der (struct nodo *p,int n)
{
	struct nodo *nuevo;

	nuevo = nodo_arbol;
	nuevo->info = n;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	p->der = nuevo;
}

#define MAXIMO 20

struct LIFO {
	int t;
	struct nodo *a[MAXIMO];
};

void inorden (struct nodo *p)
{
	struct LIFO pila;
	void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void ins_pila (struct LIFO *p, struct nodo *s);
	void retira_pila (struct LIFO *p,struct nodo **s);
	init_pila (&pila);
	while (p) {
		ins_pila (&pila,p);
		p = p->izq;
	}
	while (!pila_vacia (&pila)) {
		retira_pila (&pila,&p);
		printf ("%d  ",p->info);
		p = p->der;
		while (p) {
			ins_pila (&pila,p);
			p = p->izq;
		}
	}
}

void init_pila (struct LIFO *p)
{
	p->t = 0;
}

int pila_vacia (struct LIFO *p)
{
	return (!p->t);
}

void ins_pila (struct LIFO *p, struct nodo *s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
			p->t++;
			p->a [p->t -1] = s;
	}
}

void retira_pila (struct LIFO *p,struct nodo **s)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = NULL;
	  }
	else  {
			*s = p->a [p->t -1];
			p->t--;
	}
}

