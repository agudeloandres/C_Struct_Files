#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "alloc.h"


#define localizar  (nodo *) malloc (sizeof (nodo))
#define nodo_cola (cola  *) malloc (sizeof (cola))
#define MAXIMOV 20 /* Numero de vertices */
#define MAXIMOA 30 /* Numero de actividades */
#define PR(x) printf ("%s",x)
#define SALTO printf ("\n")

typedef struct nodo nodo;
typedef struct V V;
typedef struct cola cola;

struct nodo {
	int ad;
	int act;
	int tiempo;
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
	int temp [MAXIMOV],tarde [MAXIMOV], acttemp [MAXIMOA];
	int acttarde [MAXIMOA],nv,nact,v,valor, actividad,aux;
	struct V grafo[MAXIMOV], g_invertido[MAXIMOV];
	cola *cola;
	struct nodo *p;
	int topo [MAXIMOV],i,suma,mayor;
	int lea_grafo (V grafo[],V g_invertido[],
			int *nv, int *nact );
	void ins_lista (V g[],int v,
			int ad, int act, int tiempo);
	void escriba_g (V g[],int nv);
	lea_grafo (grafo,g_invertido,&nv,&nact);
	escriba_g (grafo,nv);
	SALTO;
	getch();
	escriba_g (g_invertido,nv);
	SALTO;
	getch();
	for (i=1; i<=nv; i++) {
		topo [i] = 0;
		temp[i] = 0;
	}
	for (i=1; i <= nact; i++) {
		acttemp [i] = acttarde [i] = 0;
	}
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
		p = grafo[v].cab;
		while (p != NULL) {
			aux = p->ad;
			valor = p->tiempo;
			actividad = p->act;
			topo [aux]--;
			if (topo[aux] == 0)
				ins_cola (&cola,aux);
			suma = temp[v] + valor;
			if (suma > temp [aux] )
				temp [aux] = suma;
			acttemp [actividad] = temp [v];
			p = p->sig;
		}
	}
	mayor = temp [1];
	for (i=2; i <=nv; i++ )
		if (mayor < temp [i])
			mayor = temp[i];
	for (i=1; i<=nv; i++) {
		topo [i] = 0;
		tarde [i] = mayor;
	}
	for (i=1; i <= nv; i++ ) {
		p = grafo [i].cab;
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
		p = g_invertido [v].cab;
		while (p != NULL) {
			aux = p->ad;
			valor = p->tiempo;
			actividad = p->act;
			topo [aux]--;
			if (topo[aux] == 0)
				ins_cola (&cola,aux);
			suma = tarde [v] - valor;
			if (suma < tarde [aux] )
				tarde [aux] = suma;
			acttarde [actividad] = suma;
			p = p->sig;
		}
	}


	PR("Lo mas temprano de los eventos..");
	for (i=1; i<=nv; i++) {
		printf ("%2d ",temp [i]);
	}
	SALTO;
	PR("Lo mas tarde de los eventos.....");
	for (i=1; i<=nv; i++) {
		printf ("%2d ",tarde [i]);
	}
	SALTO;
	PR("Lo mas temprano las actividades..");
	for (i=1; i<=nact; i++) {
		printf ("%2d ",acttemp [i]);
	}
	SALTO;
	PR("Lo mas tarde de las actividades..");
	for (i=1; i<=nact ; i++) {
		printf ("%2d ",acttarde [i]);
	}
	PR("\nRUTA CRITICA.....\n");
	PR("EVENTOS..");
	SALTO;
	for (i=1; i <= nv; i++)
		if (temp [i] == tarde [i])
			printf ("%2d ",i);
	PR("\nACTIVIDADES ");
	SALTO;
	for (i=1; i <= nact; i++)
		if (acttemp[i] == acttarde [i])
			printf ("%2d ",i);
	getch();
}

int lea_grafo (V grafo[],V g_invertido[],
			int *nv, int *nact )
{
	void ins_lista (V g[],int v, int ad,
			int act, int tiempo);
	int v,ad,i,n,act,tiempo;
	int lea();
	PR("De numero de vertices...");
	SALTO;
	*nv = n = lea();
	PR("De numero de actividades...");
	SALTO;
	*nact = lea();
	for (i=1; i <= n; i++) {
		grafo[i].v = g_invertido [i].v = 0;
		grafo[i].cab = g_invertido [i].cab = NULL;
	}
	PR ("Lea el primer vertice. 99 para terminar...");
	SALTO;
	v = lea();
	grafo[v].v = v;
	while (v != 99) {
		PR ("Lea adjunto, actividad, tiempo al vertice");
		printf ("%d ",v);
		PR(". 99 para terminar");
		SALTO;
		ad = lea(); act = lea(); tiempo = lea();
		while (ad != 99) {
			ins_lista (grafo,v,ad,act,tiempo);
			ins_lista (g_invertido,ad,v,act,tiempo);
			PR ("Lea adjunto, actividad, tiempo al vertice ");
			printf ("%d ",v);
			PR(". 99 para terminar");
			SALTO;
			ad = lea(); act = lea(); tiempo = lea();
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

void ins_lista (V g[],int v, int ad, int act, int tiempo) {
	nodo *p,*q,*nuevo;

	nuevo = localizar;
	nuevo->ad = ad;
	nuevo->act = act;
	nuevo->tiempo = tiempo;
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
			printf ("%d:%d:%d  ",p->ad,p->act,p->tiempo);
			p = p->sig;
		}
		SALTO;
	}
}

