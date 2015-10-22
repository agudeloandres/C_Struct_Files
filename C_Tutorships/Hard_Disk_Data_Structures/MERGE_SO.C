#include "stdio.h"
#include "time.h"
#include "stdlib.h"  /* random() */
typedef struct CURSOR CURSOR;

struct CURSOR {
	int llave;
	int sig;
};

main() {
	int ant,i,n,cab;
	time_t t1,t2;
	double d;
	CURSOR *p;

	printf ("Cuantos elementos desea Clasificar?\n");
	n = lea();
	printf ("\nDe el valor de los elementos\n");
	p = (CURSOR *) calloc (n,sizeof (CURSOR) );
	if (p==NULL) {
		printf ("%s","no hay memoria");
		getch();
		exit(1);
	}
	for (i = 1;  i <= n; i++ ) {
		p[i].llave = lea();
		p[i].sig = 0;
		/*printf ("%d  %d\n",i,p[i].llave); */
	}
	printf ("Ok\n");getch();
	time (&t1);
	MERGE_SORT (p,1,n,&cab);
	time (&t2);
	d = difftime (t2,t1);
	printf ("\nTiempo del sort = %lf",d);
	getch();
	i = cab;
	printf ("\n");
	while (i != 0) {
		printf ("%3d ",p[i].llave);
		i = p[i].sig;
	}
	i = cab;
        printf ("\n");
	while (i != 0) {
		printf ("%3d ",i);
		i = p[i].sig;
	}

	printf ("\n\n");
	for (i = 1;  i <= n; i++ ) {
		printf ("%3d ",p[i].llave);
	}
	printf ("\n");
	for (i = 1;  i <= n; i++ ) {
		printf ("%3d ",p[i].sig);
	}
	free(p);
	getch();
}

lea() {
	char a[10];

	a[0]=5;
	cgets (a);
	printf ("\n");
	return (atoi (a+2) );
}

mezclar (CURSOR *a, int p,int q,int *r) {
	int aux;

	if (a[p].llave <= a[q].llave) {
		*r = p;
		p = a[p].sig;
	}
	else {
		*r = q;
		q = a[q].sig;
	}
	aux = *r;
	while (p > 0 && q > 0) {
		if (a[p].llave <= a[q].llave) {
			a[aux].sig = p;
			aux = p;
			p = a[p].sig;
		}
		else {
			a[aux].sig = q;
			aux = q;
			q = a[q].sig;
		}
	}
	if (p > 0)
		a[aux].sig = p;
	if (q > 0)
		a[aux].sig = q;
}

MERGE_SORT (CURSOR *a, int izq, int der,int *cab) {
	int max,min,cabizq,cabder;

	min = (izq + der) / 2;
	max = min + 1;
	if (der - izq < 2)
		cabizq = izq;
	else MERGE_SORT (a,izq,min,&cabizq);
	if (der - izq < 3)
		cabder = der;
	else MERGE_SORT (a,max,der,&cabder);
	if (der - izq < 1)
		*cab = min;
	else mezclar(a,cabizq,cabder,cab);
}
