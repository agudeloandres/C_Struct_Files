#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "alloc.h"
#define MAXIMO 20
#define PR(x) printf ("%s",x)
#define SALTO printf ("\n")


void main() {
	int M[MAXIMO][MAXIMO],T[MAXIMO][MAXIMO];
	int nv,i;
	void listar_g (int g[][MAXIMO], int nv);
	int lea_grafo (int grafo[][MAXIMO]);
	void WARSHALL (int M[][MAXIMO], int T[][MAXIMO], int nv);
	nv = lea_grafo (M);
	listar_g (M ,nv);
	SALTO;
	getch();
	WARSHALL (M,T,nv);
	listar_g (T,nv);
	SALTO;
	getch();
}

void WARSHALL (int M[][MAXIMO], int T[][MAXIMO], int nv)
{
	int i,j,k;
	void listar_g (int g[][MAXIMO], int nv);
	void copiar (int a[][MAXIMO], int b[][MAXIMO],int nv);
	copiar (T, M, nv);
	for (k=1; k<=nv; k++) {
		for (i=1; i<=nv; i++) {
			if (i!=k) {
				if (T[i][k] == 1) {
					for (j=1; j<=nv; j++) {
						if (T[i][j] == 0)
							T[i][j] = T[k][j];
					}
				}
			}
		}
		SALTO;
		listar_g (T,nv);getch();
		SALTO;
	}
}




int lea_grafo (int grafo[][MAXIMO])
{
	int v,ad,i,j,n;
	int lea();
	PR("De numero de vertices...");
	SALTO;
	n = lea();
	for (i=1; i <= n; i++)
		for (j=1; j <=n; j++)
			grafo[i][j] = 0;
	PR ("Lea el primer vertice. 99 para terminar...");
	SALTO;
	v = lea();
	while (v != 99) {
		PR ("Lea el primer adjunto al vertice ");
		printf ("%d ",v);
		PR(". 99 para terminar");
		SALTO;
		ad = lea();
		while (ad != 99) {
			grafo [v][ad] = 1;
			PR ("Lea otro adjunto al vertice ");
			printf ("%d ",v);
			PR(". 99 para terminar");
			SALTO;
			ad = lea();
		}
		PR ("Lea otro vertice. 99 para terminar...");
		SALTO;
		v = lea();
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
			printf ("%d ",g[i][j]);
		SALTO;
	}
}


void copiar (int a[][MAXIMO], int b[][MAXIMO],int nv) {
	int i,j;

	for (i=1; i<=nv; i++)
		for (j=1; j <= nv; j++)
			a[i][j] = b[i][j];
}


