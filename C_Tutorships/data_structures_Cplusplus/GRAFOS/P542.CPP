#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "alloc.h"
#define MAXIMO 20
#define PR(x) printf ("%s",x)
#define SALTO printf ("\n")

#define localizar (nodo *)malloc (sizeof (nodo))

typedef struct nodo nodo;
typedef struct GRAFO GRAFO;

struct nodo {
	int v;
	nodo *sig;
};

struct GRAFO {
	int v;
	int padre;
	int seq;
	nodo *cab;
};


void main() {
	int lea_grafo (GRAFO grafo[]);
	void listar_g (GRAFO g[], int nv);
	void R_profundo (GRAFO g[], int v, int padre, int *seq);
	GRAFO grafo[MAXIMO];
	int nv,seq=1;
	nv = lea_grafo (grafo);
	listar_g (grafo,nv);
	SALTO;
	R_profundo (grafo,2,0,&seq);
	listar_g (grafo,nv);
	SALTO;
	getch();
}

int lea_grafo (GRAFO grafo[])
{
	void ins_lista (GRAFO g[],int v, int ad);
	int v,ad,i,n;
	int lea();
	PR("De numero de vertices...");
	SALTO;
	n = lea();
	for (i=1; i <= n; i++) {
		grafo[i].v = grafo[i].padre = grafo[i].seq = 0;
		grafo[i].cab = NULL;
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

void ins_lista (GRAFO g[],int v, int ad) {
	nodo *p,*q,*nuevo;

	nuevo = localizar;
	nuevo->v = ad;
	nuevo->sig = NULL;
	q = NULL;
	p = g[v].cab;
	while (p != NULL) {
		q = p;
		p = p->sig;
	}
	if (q == NULL)
		g[v].cab = nuevo;
	else q->sig = nuevo;
}

void listar_g (GRAFO g[], int nv) {
	int i;
	nodo *p;

	for (i=1; i <= nv; i++) {
		printf ("%d %d %d --> ",g[i].v,g[i].padre,g[i].seq);
		p = g[i].cab;
		while (p != NULL) {
			printf ("%d ",p->v);
			p = p->sig;
		}
		SALTO;
	}
}

void R_profundo (GRAFO g[], int v, int padre, int *seq)
{
	nodo *p;
	int aux;

	g[v].padre = padre;
	g[v].seq = (*seq)++;
	p = g[v].cab;
	while (p != NULL) {
		aux = p->v;
		if (g[aux].seq == 0)
			R_profundo (g,aux,v,seq);
		p = p->sig;
	}
}

