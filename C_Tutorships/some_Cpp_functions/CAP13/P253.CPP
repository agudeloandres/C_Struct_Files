#include "stdio.h"
#include "alloc.h"
#include "stdlib.h"
#include "conio.h"
#define PR(x)  printf ("%s\n",x)

// La cantidad de numeros, se informa en la linea de comandos

void main(int argc,char *argv[]) {
	int *p;
	int tamano,i;
	void ordenar (int *a,int l,int r);

	clrscr();
	if (argc != 2) {
		PR("Error en la linea de comandos");
		getch();
		exit (1);
	}
	tamano = atoi (argv [1]);
	p = (int *) calloc (tamano, sizeof (int));
	randomize();
	for (i = 0; i < tamano; i++)
		*(p+i) = rand();
	ordenar(p,0,tamano-1);
	for (i = 0; i < tamano; i++)
		printf ("%d\n",*(p+i) );

	getch();
}

void ordenar (int *a,int l,int r) {
	int i,j,x,w;

	i = l;
	j = r;
	x = a[ (l+r) / 2];
	do {
		while (a[i] < x) i++;
		while (x < a[j]) j--;
		if (i <= j) {
			w = a[i];
			a[i++] = a[j];
			a[j--] = w;
		}
	} while (i <= j);
	if (l < j) ordenar (a,l,j);
	if (i < r) ordenar (a,i,r);
}




