#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "alloc.h"

#define P(x) printf ("%s",x)
#define salto printf ("\n")
#define nuevo_grafo (struct nodo *) malloc (sizeof (struct nodo))
#define nodo_doble (struct CAMINO *) malloc (sizeof (struct CAMINO))
#define MAXIMO	 20

struct LIFO {
	int t;
	struct nodo *a[20];
};

struct nodo {
	int v;
	struct nodo *sig;
};

struct CAMINO {
	struct CAMINO *ant;
	int dato;
	struct CAMINO *sig;
};

struct GR {
	int vertice;
	int siono;
	struct nodo *cab;
};
void main()
{
	struct GR GRAFO[30];
	int nu_v,arcos,comienzo;
	struct CAMINO *Euler,*q;
	void listar_Euler (struct CAMINO *p);
	void EULER (struct GR g[], int v,
			struct CAMINO *Euler,int *arcos);
	void listar (struct GR g[],int i);
	int lea();
	int cargar (struct GR g[],int *arcos);

	P("Carga grafo...");salto;
	nu_v = cargar (GRAFO,&arcos);
	listar (GRAFO,nu_v);
	Euler = nodo_doble;
	Euler->dato = -1;
	q = nodo_doble;
	P("Por donde quiere comenzar? ");comienzo = lea();
	salto;
	q->dato = comienzo;
	Euler->sig = q;
	q->ant = Euler;
	Euler->ant = q;
	q->sig = Euler;
	EULER (GRAFO,comienzo,Euler,&arcos);
	listar_Euler (Euler);
	getch ();
}

void listar_Euler (struct CAMINO *p)
{
	printf ("\n");
	p = p->sig;
	while (p->dato != -1) {
		printf ("%d ",p->dato);
		p = p->sig;
	}
}

void EULER (struct GR g[], int v,
			struct CAMINO *Euler,int *arcos)
{
	struct nodo *p,*q;
	int senal,aux;
	void devolver_arco (struct CAMINO *Euler);
	void borrar_arco (struct GR g[], int v, int aux, struct nodo **q);
	int invest_camino (struct CAMINO *cab, int aux);

	p = g[v].cab;
	while (p != NULL) {
		aux = p->v;
		if (aux != 9999) {
			senal = invest_camino (Euler, aux);
			if (senal == 0) {
				borrar_arco (g, v, aux, &q);
				(*arcos)--;
				EULER (g, aux, Euler, arcos);
				if (*arcos != 0) {
					p->v = aux;
					q->v = v;
					devolver_arco (Euler);
					(*arcos)++;
				}
			}
		}
		p = p->sig;
	}
}

void devolver_arco (struct CAMINO *Euler)
{
	struct CAMINO *p,*s;

	p = Euler->ant;
	s = p->ant;
	s->sig = p->sig;
	Euler->ant = s;
	free (p);
}



void borrar_arco (struct GR g[], int v, int aux, struct nodo **q)
{
	struct nodo *p;

	p = g[v].cab;
	while (p->v != aux)
		p = p->sig;
	p->v = 9999;
	*q = g[aux].cab;
	while ((*q)->v != v)
		(*q) = (*q)->sig;
	(*q)->v = 9999;
}

int invest_camino (struct CAMINO *cab, int aux)
{
	struct CAMINO *L,*nuevo;

	L = cab->ant;
	nuevo = nodo_doble;
	nuevo->dato= aux;
	nuevo->ant = L;
	nuevo->sig = cab;
	L->sig = nuevo;
	cab->ant = nuevo;
	return (0);
}



void listar (struct GR g[],int i)
{
	struct nodo *p;
		  int j=1;

	while (j <= i) {
		printf ("%d --> ",g [j].vertice);
		p = g[j].cab;
		while (p) {
			printf ("%d  ",p->v);
			p = p->sig;
		}
		P("\n");
		j++;
	}
}


int lea()
{
	char L[10];

	gets (L);
	return (atoi (L));
}

int cargar (struct GR g[],int *arcos)
{
	int i,j,v,ad,k=1;
	struct nodo *p,*q,*r;

	P("Cuantos vertices? ");
	i = lea();
	P("Cuantos arcos? ");
	*arcos = lea();
	for (j=1; j<=i; j++) {
		g[j].vertice = j;
		g[j].siono = 0;
		g[j].cab = NULL;
	}
	P("Informe vertice. 9999 para finalizar\n");
	printf ("%d\n",k);
	v = k;
	while (v <= i) {
		P("Informe adjunto a ese vertice. 99 si no existen mas..\n");
                ad = lea();
		while ( ad != 99) {
			q = nuevo_grafo;
			q->v = ad;
			q->sig = NULL;
			p = r = g [v].cab;
			while (p) {
				r = p;
				p = p->sig;
			}
			if (r)
				r->sig = q;
			else g [v].cab = q;
			P("Informe adjunto a ese vertice. 99 si no existen mas..\n");
                	ad = lea();
		}
		P("Informe vertice. 9999 para finalizar\n");
		v = ++k;
		printf ("%d\n",k);
		  }
	return (i);
}

/*void borrar_arco (struct GR g[], int v, int v1)
{
	struct nodo *p,*q;

	q = NULL;
	p = g[v].cab;
	while (p->v != v1) {
		q = p;
		p = p->sig;
	}
	if (q != NULL)
		q->sig = p->sig;
	else g[v].cab = p->sig;
	free (p);

	q = NULL;
	p = g[v1].cab;
	while (p->v != v) {
		q = p;
		p = p->sig;
	}
	if (q != NULL)
		q->sig = p->sig;
	else g[v1].cab = p->sig;
	free (p);

}
*/

