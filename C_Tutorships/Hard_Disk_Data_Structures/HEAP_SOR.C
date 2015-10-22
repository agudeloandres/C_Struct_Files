#include "stdio.h"
#include "stdlib.h"  /* random() */

main() {
	int ant,i,n,*p;

	clrscr();
	printf ("Cuantos elementos desea Clasificar?\n");
	n = lea();
	printf ("\nDe el valor de los elementos\n");
	p = (int *) calloc (n+1,2);
	for (i = 1;  i<=n; i++ ) {
		p[i] = lea();
		printf ("%d\n",p[i]);
	}
	HEAP_SORT (p,n);
	ant = p[1] ;
	printf ("\n");
	for (i=1; i<=n; i++) {
		if (ant > p[i]) {
			printf ("error");getch();
			exit(1);
		}
		else ant = p[i];
		printf ("%d ",p[i]);
	}
	free (p);
	getch();
}

lea() {
	char a[10];

	a[0]=5;
	cgets (a);
	printf ("\n");
	return (atoi (a+2) );
}

HEAP_SORT (int *a, int n) {
	int j,jj,temp;

	for (j = n / 2; j > 0; j--)
		prioridad (a,j,n);
	for (j = n-1; j > 0; j--) {
		temp = a[j+1];
		a[j+1] = a[1];
		a[1] = temp;
		prioridad (a,1,j);
	}
}

prioridad (int *a, int i, int n) {
	int temp,k;

	temp = a[i];
	k = i * 2;
	while (k <= n) {
		if (k < n)
			if (a[k] < a[k+1])
				k++;
		if (temp < a[k]) {
			a[i] = a[k];
			i = k;
			k = i * 2;
		}
		else break;
	}
	a[i] = temp;
}


