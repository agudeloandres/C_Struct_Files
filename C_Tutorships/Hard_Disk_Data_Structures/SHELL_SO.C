#include "stdio.h"
#include "stdlib.h"  /* random() */

main() {
	int ant,i,n,*p;
	printf ("Cuantos elementos desea Clasificar?\n");
	n = lea();
	printf ("\nDe el valor de los elementos\n");
	p = (int *) calloc (n,2);
	for (i = 0;  i< n; i++ ) {
		p[i] = random (1000);
		printf ("%d\n",p[i]);
	}
	SHELL_SORT (p,n);
	ant = p[0] ;
	printf ("\n");
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

SHELL_SORT (int *a, int  n) {
	int variacion [3] = {5,3,1};
	int i,j;

	for (i=0; i < 3; i++)
		ordenar (a,variacion[i],n);
}

ordenar (int *a, int salto,int n) {
	int i,j,temp;

	j = salto;
	while (j < n) {
		i = j - salto;
		temp = a[j];
		while (i >= 0) {
			if (temp >= a[i])
				break;
			else {
				a[i + salto] = a[i];
				i = i - salto;
			}
		}
		a[i + salto] = temp;
		j++;
	}

}

