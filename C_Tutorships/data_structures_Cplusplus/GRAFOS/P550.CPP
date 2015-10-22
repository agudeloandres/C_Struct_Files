#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "alloc.h"
#define MAXIMO 20
#define PR(x) printf ("%s",x)
#define SALTO printf ("\n")

#define localizar (nodo *)malloc (sizeof (nodo))
#define asigne_cola (FIFO *)malloc (sizeof (FIFO))

typedef struct nodo nodo;
typedef struct GRAFO GRAFO;
typedef struct nodo_cola FIFO;

struct nodo_cola {
	int info;
	FIFO *sig;
};

struct nodo {
	int v;
	int LR;
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
	void R_ancho (GRAFO g[], int v);
	void listar_g (GRAFO g[], int nv);
	GRAFO grafo[MAXIMO];
	int nv;
	nv = lea_grafo (grafo);
	listar_g (grafo,nv);
	SALTO;
	R_ancho (grafo, 3);
	listar_g (grafo,nv);
	SALTO;
	getch();
}

int lea_grafo (GRAFO grafo[])
{
	int v,ad,i,n,lea();
	void ins_lista (GRAFO g[],int v, int ad);
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
	nuevo->LR = ' ';
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
			printf ("%d%c ",p->v,p->LR);
			p = p->sig;
		}
		SALTO;
	}
}

void R_ancho (GRAFO g[], int v)
{
	void init_cola (FIFO **p);
	void ins_cola (FIFO **p,int objeto);
	void retira_cola (FIFO **p,int *s);
	int cola_vacia (FIFO **p);
	int seq = 1,aux;
	nodo *p;
	FIFO *cola;

	init_cola (&cola);
	g[v].padre = 0;
	g[v].seq = seq++;
	ins_cola (&cola,v);
	do {
		retira_cola (&cola,&v);
		p = g[v].cab;
		while (p != NULL) {
			aux = p->v;
			if (g[aux].seq == 0) {
				g[aux].padre = v;
				g[aux].seq = seq++;
				ins_cola (&cola,aux);
			}
			else if (g[v].padre != aux)
				p->LR = '*';
			p = p->sig;
		}
	} while (!cola_vacia (&cola));
}



void init_cola (FIFO **p)
{
	*p = asigne_cola;
	(*p)->sig = *p;
}

void ins_cola (FIFO **p,int objeto)
{
	FIFO *nuevo;

	nuevo = asigne_cola;
	nuevo->info = objeto;
	nuevo->sig = (*p)->sig;
	(*p)->sig = nuevo;
	*p = nuevo;
}

void retira_cola (FIFO **p,int *s)
{
	FIFO *q,*r;

	if (*p == (*p)->sig) {
		printf ("no existen objetos para atender\n");
		*s = '#';
	}
	else {
		  q = (*p)->sig;
		  r = q->sig;
		  *s = r->info;
		  q->sig = r->sig;
		  if (q == q->sig)
				*p = q;
		  free (r);
	}
}

int cola_vacia (FIFO **p)
{
	return (*p == (*p)->sig);
}


