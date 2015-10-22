#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "alloc.h"
#define MAXIMO 20
#define PR(x) printf ("%s",x)
#define SALTO printf ("\n")

#define localizar (nodo *)malloc (sizeof (nodo))

typedef struct nodo nodo;
typedef struct GRAFO GRAFO;

struct nodo {
	int v;
	int L; /* c si es linea de cruce. * si es linea de regreso */
	nodo *sig;
};

struct GRAFO {
	int v;
	int padre;
	int seq;
	int menor;
	int t;
	nodo *cab;
};


void main() {
	GRAFO grafo[MAXIMO];
	int nv,seq=1;
	int lea_grafo (GRAFO grafo[]);
	void listar_g (GRAFO g[], int nv);
	int Lineas_c (GRAFO g[], int v, int padre, int *seq);
	nv = lea_grafo (grafo);
	listar_g (grafo,nv);
	SALTO;
	Lineas_c (grafo,4,0,&seq);
	listar_g (grafo,nv);
	SALTO;
	getch();
}

int lea_grafo (GRAFO grafo[])
{
	int v,ad,i,n;
	int lea();
	void ins_lista (GRAFO g[],int v, int ad);
	PR("De numero de vertices...");
	SALTO;
	n = lea();
	for (i=1; i <= n; i++) {
		grafo[i].v = grafo[i].padre = grafo[i].seq = 0;
		grafo[i].menor = 0;
		grafo[i].t = 0;
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
	nuevo->L = ' ';
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
		printf ("%d %d %d %d %d --> ",g[i].v,g[i].padre,g[i].seq,
						g[i].menor,g[i].t);
		p = g[i].cab;
		while (p != NULL) {
			printf ("%d%c ",p->v,p->L);
			p = p->sig;
		}
		SALTO;
	}
}

int Lineas_c (GRAFO g[], int v, int padre, int *seq)
{
	nodo *p;
	int aux,devuelto;

	g[v].padre = padre;
	g[v].menor = *seq;
	g[v].seq = (*seq)++;
	p = g[v].cab;
	while (p != NULL) {
		aux = p->v;
		if (g[aux].seq == 0) {
			devuelto = Lineas_c (g,aux,v,seq);
			if (devuelto < g[v].menor)
				g[v].menor = devuelto;
		}
		else if (aux == padre)
			;  /* No existe ningun tipo de linea */
		else if (g[aux].seq < g[v].menor  && g[aux].t == 0) {
			g[v].menor = g[aux].seq;
			p->L = '*';
		}
		else p->L = 'c';
		p = p->sig;
	}
	g[v].t = 1;
	return (g[v].menor);
}

