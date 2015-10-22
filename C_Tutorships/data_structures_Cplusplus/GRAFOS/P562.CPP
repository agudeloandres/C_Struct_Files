#include "stdio.h"
#include "alloc.h"
#include "conio.h"
#include "stdlib.h"
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
	int menor;
	nodo *cab;
};


void main() {
	int V_corte (GRAFO g[], int v, int padre, int *seq,int raiz,int *s);
	GRAFO grafo[MAXIMO];
	int nv,seq=1,s=0;
	int lea_grafo (GRAFO grafo[]);
	void listar_g (GRAFO g[], int nv);
	nv = lea_grafo (grafo);
	listar_g (grafo,nv);
	SALTO;
	V_corte (grafo,2,0,&seq,2,&s);
	listar_g (grafo,nv);
	SALTO;
	getch();
}

int lea_grafo (GRAFO grafo[])
{
	int v,ad,i,n;
	void ins_lista (GRAFO g[],int v, int ad);
	int lea();
	PR("De numero de vertices...");
	SALTO;
	n = lea();
	for (i=1; i <= n; i++) {
		grafo[i].v = grafo[i].padre = grafo[i].seq = 0;
		grafo[i].menor = 0;
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
		printf ("%2d %2d %2d %2d --> ",g[i].v,g[i].padre,g[i].seq,
					g[i].menor);
		p = g[i].cab;
		while (p != NULL) {
			printf ("%d ",p->v);
			p = p->sig;
		}
		SALTO;
	}
}

int  V_corte (GRAFO g[], int v, int padre, int *seq,int raiz,int *s)
{
	nodo *p;
	int aux,devuelto;

	g[v].padre = padre;
	g[v].seq = *seq;
	g[v].menor = (*seq)++;
	if (padre == raiz)
		if (*s == 0)
			*s = 1;
		else printf ("vertice de corte %d\n",raiz);
	p = g[v].cab;
	while (p != NULL) {
		aux = p->v;
		if (g[aux].seq == 0) {
			devuelto = V_corte (g,aux,v,seq,raiz,s);
			if (devuelto < g[v].menor)
				g[v].menor = devuelto;
			if (devuelto >= g[v].seq && v != raiz)
				printf ("vertice de corte %d\n",v);
		}
		else if (aux != padre)
			if (g[aux].seq < g[v].menor)
				g[v].menor = g[aux].seq;
		p = p->sig;
	}
	return (g[v].menor);
}

