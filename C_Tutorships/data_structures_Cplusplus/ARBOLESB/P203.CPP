#include "stdio.h"
#include "alloc.h"
#include "stdlib.h"
#define  nodo_arbol  (struct nodo *)malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *izq;
	struct nodo *der;
};

void main()
{
	struct nodo *raiz,*p,*q;
	int n;
	void ins_izq (struct nodo *p,int n);
	void ins_der (struct nodo *p,int n);
	int altura (struct nodo *p);
	int lea_entero();
	printf ("de numero\n");
	n = lea_entero();
	raiz = nodo_arbol;
	raiz->info = n;
	raiz->izq = NULL;
	raiz->der = NULL;
	printf ("de numero\n");
	n = lea_entero();
	while (n != 9999) {
		p = q = raiz;
		while (p->info != n &&  q  != NULL ) {
			p = q;
			if (n < p->info)
				q = q->izq;
			else q = q->der;
		}
		if (p->info == n)
			printf ("numero repetido\n");
		  else if (n < p->info)
				ins_izq (p,n);
			else  ins_der (p,n);
		printf ("de numero\n");
		n = lea_entero ();
	}
	printf ("Altura = %d \n",altura (raiz));
}

int lea_entero() {
	char aux[20];
	gets (aux);
	return atoi(aux);
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

struct elemento {
	struct nodo *apunt;
	int h;
};

struct LIFO {
	int t;
	struct elemento a[MAXIMO];
};

int altura (struct nodo *p)
{
	int i,max;
	struct LIFO pila;
	void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void ins_pila (struct LIFO *p,struct nodo *s,int i);
	void retira_pila (struct LIFO *p,struct nodo **s,int *i);
	i = 0;
	init_pila (&pila);
	while (p) {
		ins_pila (&pila,p,i++);
		p = p->izq;
	}
	max = i - 1;
	while (!pila_vacia (&pila)) {
		retira_pila (&pila,&p,&i);
		if (i > max)
			max = i;
		i++;
		p = p->der;
		while (p) {
			ins_pila (&pila,p,i++);
			p = p->izq;
		}
	}
	return (max);
}


void init_pila (struct LIFO *p)
{
	p->t = 0;
}

int pila_vacia (struct LIFO *p)
{
	return (!p->t);
}

void ins_pila (struct LIFO *p,struct nodo *s,int i)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
			p->t++;
			p->a[p->t - 1].apunt = s;
			p->a[p->t - 1].h = i;
	}
}

void retira_pila (struct LIFO *p,struct nodo **s,int *i)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = NULL;
	  }
	else  {
			*s = p->a [p->t -1].apunt;
			*i = p->a [p->t - 1].h;
			p->t--;
	}
}

