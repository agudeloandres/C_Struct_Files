#include "stdio.h"
#include "stdlib.h"  /* random() */

main() {
	int ant,i,n,*p;
	printf ("Cuantos elementos desea Clasificar?\n");
	n = lea();
	printf ("\nDe el valor de los elementos\n");
	p = (int *) calloc (n,2);
	for (i = 1; i <= n; i++ ) {
		p[i] = random (1000);
		printf ("%d\n",p[i]);
	}
	S_INSERCION (p,n);
	ant = p[1];
	for (i=1; i<=n; i++) {
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


S_INSERCION (int *a, int  n) {
	int i,j,temp;

	a[0] = -32768;
	i = 2;
	while (i <=n) {
		j = i-1;
		temp = a[i];
		while (temp < a[j]) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
		i++;
	}
}

