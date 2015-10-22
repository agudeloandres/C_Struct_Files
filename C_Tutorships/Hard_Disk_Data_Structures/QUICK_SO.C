#include "stdio.h"
#include "stdlib.h"  /* random() */

main() {
	int ant,i,n,*p;
	printf ("Cuantos elementos desea Clasificar?\n");
	n = lea();
	printf ("\nDe el valor de los elementos\n");
	p = (int *) calloc (n,2);
	for (i = 0; i < n; i++ ) {
		p[i] = random (1000);
		printf ("%d\n",p[i]);
	}
	QUICK_SORT (p,0,n-1);
	ant = p[0];
	for (i=0; i<n; i++) {
		if (ant > p[i]) {
			printf ("error");getch();
			exit(1);
		}
		else ant = p[i];
		printf ("%d ",p[i]);
	}
	getch();
}

lea() {
	char a[10];

	a[0]=5;
	cgets (a);
	printf ("\n");
	return (atoi (a+2) );
}

cambio (int *a,int i,int j) {
	int temp;

	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

QUICK_SORT (int *a,int i, int j) {
	int x,tempi, tempj,temp;

	tempi = i;
	tempj = j;
	x = a[ (i+j) / 2 ];
	do {
		while (x > a[i]) i++;
		while (x < a[j]) j--;
		if (i < j) {
			cambio (a,i,j);
			i++;
			j--;
		}
	} while ( i < j);
	if (i == j)
		if (x < a[i])
			j--;
		 else i++;
	if (j-1 == tempi) {
		if (a [tempi] > a[j])
			cambio (a, tempi,j);
	}
	else if (j > tempi) QUICK_SORT (a,tempi,j);
	if (i+1 == tempj) {
		if (a[i] > a[tempj])
			cambio (a,i,tempj);
	}
	else if (i < tempj) QUICK_SORT (a,i,tempj);

}