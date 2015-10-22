#include "stdio.h"
#include "alloc.h"
#include "conio.h"
#include "stdlib.h"
#define MAXIMO 20
#define PR(x) printf ("%s",x)
#define SALTO printf ("\n")

#define localizar (nodo *)malloc (sizeof (nodo))

typedef struct nodo nodo;

struct nodo {
	int v;
	nodo *sig;
};

void main() {
	nodo grafo[MAXIMO];
	int nv;
	int lea_grafo (nodo grafo[]);
   void listar_g (nodo g[], int nv);
	nv = lea_grafo (grafo);
	listar_g (grafo,nv);
	getch();
}

int lea_grafo (nodo grafo[])
{
	int v,ad,i,n;
	void ins_lista (nodo g[],int v, int ad);
	int lea();
	PR("De numero de vertices...");
	SALTO;
	n = lea();
	for (i=1; i <= n; i++) {
		grafo[i].v = 0;
		grafo[i].sig = NULL;
	}
	PR ("Lea el primer vertice. 99 para terminar...");
	SALTO;
	v = lea();
	grafo[v].v = v;
	while (v != 99) {
		PR ("Lea el primer adjunto al vertice ");
		printf ("%d ",v);
		PR(". 99 para terminar");
		SALTO;
		ad = lea();
		while (ad != 99) {
			ins_lista (grafo,v,ad);
			PR ("Lea otro adjunto al vertice ");
			printf ("%d ",v);
			PR(". 99 para terminar");
			SALTO;
			ad = lea();
		}
		PR ("Lea otro vertice. 99 para terminar...");
		SALTO;
		v = lea();
		grafo[v].v = v;
	}
	return (n);
}

int lea() {
	char L[10];

	gets (L);
	return (atoi (L));
}

void ins_lista (nodo g[],int v, int ad) {
	nodo *p,*q,*nuevo;

	nuevo = localizar;
	nuevo->v = ad;
	nuevo->sig = NULL;
	q = NULL;
	p = g[v].sig;
	while (p != NULL) {
		q = p;
		p = p->sig;
	}
	if (q == NULL)
		g[v].sig = nuevo;
	else q->sig = nuevo;
}

void listar_g (nodo g[], int nv) {
	int i;
	nodo *p;

	for (i=1; i <= nv; i++) {
		printf ("%d --> ",g[i].v);
		p = g[i].sig;
		while (p != NULL) {
			printf ("%d ",p->v);
			p = p->sig;
		}
		SALTO;
	}
}




