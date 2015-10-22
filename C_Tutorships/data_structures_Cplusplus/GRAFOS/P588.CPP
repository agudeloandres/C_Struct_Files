#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "alloc.h"
#define MAXIMO 20
#define PR(x) printf ("%s",x)
#define SALTO printf ("\n")


void main() {
	int M[MAXIMO][MAXIMO];
	int nv;
	int lea_grafo (int grafo[][MAXIMO]);
	void listar_g (int g[][MAXIMO], int nv);
	void FLOYD (int M[][MAXIMO],int N);
	nv = lea_grafo (M);
	listar_g (M ,nv);
	SALTO;
	getch();
	FLOYD (M,nv);
	SALTO;
	listar_g (M,nv);
	getch();
}

void FLOYD (int M[][MAXIMO],int N)
{
	int i,j,k;
	void listar_g (int g[][MAXIMO], int nv);
	for (k=1; k <= N; k++)
		M [k][k] = 0;
	for (k=1; k <= N; k++) {
		for (i=1; i <= N; i++) {
			if (i != k) {
				if (M [i][k] != 32000) {
					for (j=1; j <= N; j++) {
						if (M[i][k] + M[k][j]
							< M[i][j] )
							M[i][j] =
							M[i][k]+ M[k][j];
					}
				}
			}
		}
		SALTO;
		listar_g (M,N);
		getch();
	}
}




int lea_grafo (int grafo[][MAXIMO])
{
	int lea(),v,ad,i,j,n,costo;

	PR("De numero de vertices...");
	SALTO;
	n = lea();
	for (i=1; i <= n; i++)
		for (j=1; j <=n; j++)
			grafo[i][j] = 32000;
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
			if (g[i][j] == 32000)
				printf ("%s"," * ");
			else printf ("%2d ",g[i][j]);
		SALTO;
	}
}


