#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "alloc.h"
#define localizar  (nodo *) malloc (sizeof (nodo))
#define nodo_cola (cola  *) malloc (sizeof (cola))
#define MAXIMOV 20 /* Numero de vertices */
#define PR(x) printf ("%s",x)
#define SALTO printf ("\n")

typedef struct nodo nodo;
typedef struct V V;
typedef struct cola cola;

struct nodo {
	int ad;
	nodo *sig;
};

struct V {
	int v;
	nodo  *cab;
};

struct cola {
	int v;
	cola *cab;
};

void main()
{
	void init_cola (cola **p);
	void ins_cola (cola **p,int objeto);
	void retira_cola (cola **p,int *s);
	int cola_vacia (cola **p);
	void escriba_g (V g[],int nv);
	int lea_grafo (V grafo[],V g_invertido[], int *nv);
	int nv,v,aux;
	struct V grafo[MAXIMOV], g_invertido[MAXIMOV];
	cola *cola;
	struct nodo *p;
	int topo [MAXIMOV],i;

	lea_grafo (grafo,g_invertido,&nv);
	escriba_g (grafo,nv);
	SALTO;
	getch();
	escriba_g (g_invertido,nv);
	SALTO;
	getch();
	for (i=1; i<=nv; i++)
		topo [i] = 0;
	for (i=1; i <= nv; i++ ) {
		p = g_invertido [i].cab;
		while (p != NULL) {
			topo [i]++;
			p = p->sig;
		}
	}
	init_cola (&cola);
	for (i=1;i<=nv;i++)
		if (topo [i] == 0 )
			ins_cola (&cola,i);
	while (!cola_vacia(&cola)) {
		retira_cola (&cola ,&v);
		printf ("%d ",v);
		p = grafo[v].cab;
		while (p != NULL) {
			aux = p->ad;
			topo [aux]--;
			if (topo[aux] == 0)
				ins_cola (&cola,aux);
			p = p->sig;
		}
	}

	getch();
}

int lea_grafo (V grafo[],V g_invertido[], int *nv)
{
	int v,ad,i,n,lea();
	void ins_lista (V g[],int v, int ad);
	PR("De numero de vertices...");
	SALTO;
	*nv = n = lea();
	PR("De numero de actividades...");
	SALTO;
	for (i=1; i <= n; i++) {
		grafo[i].v = g_invertido [i].v = 0;
		grafo[i].cab = g_invertido [i].cab = NULL;
	}
	PR ("Lea el primer vertice. 99 para terminar...");
	SALTO;
	v = lea();
	grafo[v].v = v;
	while (v != 99) {
		PR ("Lea adjunto ");
		printf ("%d ",v);
		PR(". 99 para terminar");
		SALTO;
		ad = lea();
		while (ad != 99) {
			ins_lista (grafo,v,ad);
			ins_lista (g_invertido,ad,v);
			PR ("Lea adjunto ");
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

void ins_lista (V g[],int v, int ad) {
	nodo *p,*q,*nuevo;

	nuevo = localizar;
	nuevo->ad = ad;
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



void init_cola (cola **p)
{
	*p = nodo_cola;
	(*p)->cab = *p;
}

void ins_cola (cola **p,int objeto)
{
	cola *nuevo;

	nuevo = nodo_cola;
	nuevo->v = objeto;
	nuevo->cab = (*p)->cab;
	(*p)->cab = nuevo;
	*p = nuevo;
}

void retira_cola (cola **p,int *s)
{
	cola *q,*r;

	if (*p == (*p)->cab) {
		printf ("no existen objetos para atender\n");
		*s = '#';
	}
	else {
		  q = (*p)->cab;
		  r = q->cab;
		  *s = r->v;
		  q->cab = r->cab;
		  if (q == q->cab)
				*p = q;
		  free (r);
		  }
}


int cola_vacia (cola **p)
{
	return (*p == (*p)->cab);
}

void escriba_g (V g[],int nv) {
	nodo *p;
	int i;

	for (i=1; i<=nv;i++) {
		p = g[i].cab;
		printf ("%d--> ",i);
		while (p != NULL) {
			printf ("%d  ",p->ad);
			p = p->sig;
		}
		SALTO;
	}
}



