#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "alloc.h"
#define MAXIMO 20
#define PR(x) printf ("%s",x)
#define SALTO printf ("\n")


void main() {
	int M[MAXIMO][MAXIMO],a[MAXIMO][MAXIMO],R[MAXIMO][MAXIMO];
	int S[MAXIMO][MAXIMO];
	int nv,i;
	void producto (int a[][MAXIMO],int b[][MAXIMO],int c[][MAXIMO],int m);
	void listar_g (int g[][MAXIMO], int nv);
	void sumar (int S[][MAXIMO],int R[][MAXIMO],int nv);
	int lea_grafo (int grafo[][MAXIMO]);
   void copiar (int a[][MAXIMO], int b[][MAXIMO],int nv);
	nv = lea_grafo (M);
	listar_g (M ,nv);
	getch();
	copiar (a,M,nv);
	copiar (S,M,nv);
	for (i=1; i<nv; i++) {
		producto (a,M,R,nv);
		sumar (S,R,nv);
		listar_g (R,nv);
		SALTO;getch();
		copiar (a,R,nv);
	}
	listar_g (R,nv);
	SALTO;
	listar_g (S,nv);
	getch();
}

void sumar (int S[][MAXIMO],int R[][MAXIMO],int nv) {
	int i,j;

	for (i=1;i<=nv;i++)
		for (j=1; j<=nv;j++)
			S[i][j] += R[i][j];
}

int  lea_grafo (int grafo[][MAXIMO])
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

void producto (int a[][MAXIMO],int b[][MAXIMO],int c[][MAXIMO],int m) {
	register i,j,k;

	for (i=1; i<=m; i++)
		for (k=1; k<=m; k++) {
			c[i][k] = 0;
			for (j=1; j<=m; j++)
				c[i][k] += a[i][j] * b[j][k];
		}
}

void copiar (int a[][MAXIMO], int b[][MAXIMO],int nv) {
	int i,j;

	for (i=1; i<=nv; i++)
		for (j=1; j <= nv; j++)
			a[i][j] = b[i][j];
}


