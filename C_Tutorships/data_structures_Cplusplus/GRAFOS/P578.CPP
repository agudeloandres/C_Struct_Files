#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "alloc.h"
#define MAXIMO 20
#define PR(x) printf ("%s",x)
#define SALTO printf ("\n")


void main() {
	int M[MAXIMO][MAXIMO],T[MAXIMO][MAXIMO];
	int suma, marcas[MAXIMO],padres[MAXIMO],minimo [MAXIMO];
	int nv,i;
	int PRIM (int M[][MAXIMO],
				int N,int minimo[],int padres[],int marcas[]);
	int lea_grafo (int grafo[][MAXIMO]);
	void listar_g (int g[][MAXIMO], int nv);
	void listar_r (int a[],int nv);
	nv = lea_grafo (M);
	listar_g (M ,nv);
	SALTO;
	getch();
	suma = PRIM (M,nv,minimo,padres,marcas);
	printf ("\n suma=%d\n",suma);
	SALTO;
	listar_r (minimo,nv);
	SALTO;
	SALTO;
	listar_r (padres,nv);
	SALTO;
	listar_r (marcas,nv);
	SALTO;
	getch();
}

int PRIM (int M[][MAXIMO],int N,int minimo[],int padres[],int marcas[])
{
	int min;
	int j,k,escogido,suma;

	for (j=1; j<=N; j++ ) {
		minimo[j] = M[1][j];
		marcas [j] = 0;
		padres [j] = 1;
	}
	minimo [1] = 0;
	padres [1]= 0;
	marcas [1] = 1;
	suma = 0;
	for (k = 2; k <= N; k++) {
		min = 32767;
		for (j=1; j <= N; j++)
			if (marcas [j] == 0 && minimo [j] < min) {
				min = minimo [j];
				escogido = j;
			}
		marcas [escogido] = 1;
		suma = suma + min;
		for (j=1; j <= N; j++)
			if (marcas [j] == 0 &&
				M[escogido][j] < minimo[j] ) {
				minimo [j] = M[escogido][j];
				padres [j] = escogido;
			}
	}
	return (suma);
}


int lea_grafo (int grafo[][MAXIMO])
{
	int v,ad,i,j,n,costo,lea();

	PR("De numero de vertices...");
	SALTO;
	n = lea();
	for (i=1; i <= n; i++)
		for (j=1; j <=n; j++)
			grafo[i][j] = 32767;
	PR ("Vertice  ... ");
	v = 1;
	printf ("%d",v);
	SALTO;
	while (v <= n) {
		PR ("Lea el primer adjunto al vertice ");
		printf ("%d ",v);
		PR(". 99 para terminar");
		SALTO;
		ad = lea();
		while (ad != 99) {
			PR("Lea costo del arco");SALTO;
			costo = lea();
			grafo [v][ad] = costo;
			PR ("Lea otro adjunto al vertice ");
			printf ("%d ",v);
			PR(". 99 para terminar");
			SALTO;
			ad = lea();
		}
		PR ("Vertice ...");
		v++;
		printf ("%d ",v);
		SALTO;
	}
	return (n);
}

int lea() {
	char L[10];

	gets (L);
	return (atoi (L));
}


void listar_g (int g[][MAXIMO], int nv) {
	int i,j;

	for (i=1; i <= nv; i++) {
		for (j = 1; j <= nv; j++)
			if (g[i][j] == 32767)
				printf ("%s"," * ");
			else printf ("%2d ",g[i][j]);
		SALTO;
	}
}

void listar_r (int a[],int nv) {
	int k;

	for (k=1; k<=nv; k++)
		printf ("%d ",a[k]);
}


