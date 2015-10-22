#include "alloc.h"
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define MAXIMO 50
#define P(x) printf ("%s\n",x)

typedef struct ELEMENTO ELEMENTO;
typedef struct arbol arbol;
typedef struct nodo_grafo nodo_grafo;
typedef struct vertices vertices;

struct ELEMENTO {
	int costo;
	int v1,v2;
};

struct arbol {
	int cont;
	ELEMENTO a[MAXIMO];
};

struct nodo_grafo {
	int vertice;
	int datos;
	nodo_grafo *sig;
};

struct vertices {
	int vertice;
	int padre;
	int datos;
	nodo_grafo *cab;
};

void main()
{
	int a[MAXIMO],contar=0,i,j,n,v1,v2,costo,suma=0;
	arbol prioridad;
	vertices T [MAXIMO];
	ELEMENTO dato;
	void inicia_p(arbol *m);
	void crea_p (arbol *m,ELEMENTO dato);
	void copiar (ELEMENTO *a,ELEMENTO *b);
	void retirar_p (arbol *m,ELEMENTO *elemento);
	void UNIR (int *a,int i,int j);
	int BUSCAR (int *a,int i);
	void INSERTAR (vertices *T,ELEMENTO elemento);
	void listar (vertices *T);
	for (i=1; i<MAXIMO; i++)
		a[i] = -1;
	n = 0;
	inicia_p (&prioridad);
	P("De vertices y costo del arco..(v1 v2 costo)");
	scanf ("%d %d %d",&v1,&v2,&costo);
	while (  v1 != 9999) {
		dato.costo = costo;
		dato.v1 = v1;
		dato.v2 = v2;
		crea_p (&prioridad, dato);
		n++;
		P("De vertices y costo del arco..(v1 v2 costo)");
		scanf ("%d %d %d",&v1,&v2,&costo);
	}
/*	for (i=0; i <= prioridad.cont ; i++)
		printf ("%d %d %d\n",prioridad.a[i].costo,
			prioridad.a[i].v1, prioridad.a[i].v2);
	getch();
	exit (1); */
	for (i=0; i < MAXIMO; i++)  {
		T[i].vertice = i;
		T[i].padre = 0;
		T [i].datos = 0;
		T [i].cab = NULL;
	}
	while  ( (contar < n-1) && (prioridad.cont) ) {
                retirar_p (&prioridad,&dato);
		P("ARCO A PROCESAR....");
		printf ("    %d %d %d\n",dato.v1,dato.v2,dato.costo);
		i = BUSCAR (a, dato.v1);
		j = BUSCAR (a, dato.v2);
		if (i == j)
			P("ARCO RECHAZADO....");
		else {
			suma = suma + dato.costo;
			UNIR (a,i,j);
			INSERTAR (T,dato);
			contar++;
		}
		getch();
	}
	listar (T);
	printf ("%d\n",suma);
	getch();
}




void inicia_p(arbol *m)
{
	m->cont = 0;
	m->a[0].costo = -32767;
}

void crea_p (arbol *m,ELEMENTO dato)
{
	int i,j;
	void copiar (ELEMENTO *a,ELEMENTO *b);
	m->cont++;
	i= m->cont;
	j = i/2;
	while (m->a[j].costo > dato.costo) {
		copiar (m->a+i,m->a+j);
		i = j;
		j = i / 2;
	}
	copiar (m->a+i,&dato);
}

void copiar (ELEMENTO *a,ELEMENTO *b)
{
	a->costo = b->costo;
	a->v1 = b->v1;
	a->v2 = b->v2;
}


void retirar_p (arbol *m,ELEMENTO *elemento)
{
	int i,j;
	ELEMENTO temp;

	copiar (elemento,m->a+1);
	copiar (&temp, m->a + m->cont);
	m->cont--;
	i = 1;
	j = 2;
	while (j <= m->cont) {
		if (j <m->cont)
			if (m->a[j].costo > m->a[j+1].costo)
				j++;
		if (temp.costo <= m->a[j].costo)
			break;
		copiar (m->a+i,m->a+j);
		i = j;
		j = 2 * i;
	}
	copiar (m->a+i,&temp);
}

void UNIR (int *a,int i,int j)
{
	int k;

	k = a [i] + a[j];
	if (a[i] < a[j]) {
		a[j] = i;
		a[i] = k;
	}
	else {
		a[i] = j;
		a[j] = k;
	}
}

int BUSCAR (int *a,int i)
{
	int j,k,t;

	j = i;
	while (a[j] > 0)
		j = a[j];
	k = i;
	while (j != k) {
		t = a[k];
		a[k] = j;
		k = t;
	}
	return (j);
}

void listar (vertices *T)
{
	int i=1;
	nodo_grafo *p;

	while (i < 15) {
		printf ("%s %d  ","VERTICE",T[i].vertice);
		p = T[i].cab;
		while (p) {
			printf ("%d %d      ",p->vertice,p->datos);
			p = p->sig;
		}
		P(" ");
		i++;
	}
}

void INSERTAR (vertices *T,ELEMENTO elemento)
{
	int i = 1;
	nodo_grafo *p,*nuevo;

	while (T[i].vertice != elemento.v1)
		i++;
	T[i].datos = 1;
	nuevo = (nodo_grafo *) malloc (sizeof (nodo_grafo));
	nuevo->vertice = elemento.v2;
	nuevo->datos = elemento.costo;
	nuevo->sig = NULL;
	if (T[i].cab != NULL) {
		p = T[i].cab;
		while (p->sig !=NULL)
			p = p->sig;
		p->sig = nuevo;
	}
	else T[i].cab = nuevo;

	while (T[i].vertice != elemento.v2)
		i++;
	T[i].datos = 1;
	nuevo = (nodo_grafo *) malloc (sizeof (nodo_grafo));
	nuevo->vertice = elemento.v1;
	nuevo->datos = elemento.costo;
	nuevo->sig = NULL;
	if (T[i].cab != NULL) {
		p = T[i].cab;
		while (p->sig !=NULL)
			p = p->sig;
		p->sig = nuevo;
	}
	else T[i].cab = nuevo;
}



