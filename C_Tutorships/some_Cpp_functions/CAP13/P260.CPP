#include "stdio.h"
#include "alloc.h"
#include "stdlib.h"
#include "conio.h"

#include "math.h"

#define PR(x)  printf ("%s\n",x)
#define LocFar (struct Y far *) farcalloc (tamano, sizeof (struct Y))

struct Y {
	float angulo;
	float coseno;
};

void main(int argc,char *argv[]) {  /* Se debe correr  en model = large */
	float angulo;
	struct Y far *p;
	int i;
	unsigned long tamano;
	void ordenar (struct Y far *a,int l,int r);

	clrscr();
	if (argc != 2) {
		PR("Error en la linea de comandos");
		getch();
		exit (1);
	}
	tamano = (unsigned long) atoi (argv [1]);
	p = LocFar;
	randomize();
	for (i = 0; i < (int) tamano; i++) {
		(p+i)->angulo = (float) (random (1001) / 1000.0);
		(p+i)->coseno = cos((p+i)->angulo);
	}
	ordenar(p,0,(int) tamano-1);
	for (i = 0; i < (int) tamano; i++)
		printf ("%f %f\n",(p+i)->angulo,(p+i)->coseno);

	getch();
}

void ordenar (struct Y far *a,int l,int r) {
	int i,j;
	struct Y x,w;

	i = l;
	j = r;
	x = a[ (l+r) / 2];
	do {
		while (a[i].coseno < x.coseno) i++;
		while (x.coseno < a[j].coseno) j--;
		if (i <= j) {
			w = a[i];
			a[i++] = a[j];
			a[j--] = w;
		}
	} while (i <= j);
	if (l < j) ordenar (a,l,j);
	if (i < r) ordenar (a,i,r);
}




