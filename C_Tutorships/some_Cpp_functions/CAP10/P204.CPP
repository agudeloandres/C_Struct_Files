#include "stdio.h"
#include "fcntl.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x) printf ("%s\n",x)

void main() {
	FILE *p;
	char a[80],*q;
	int i;


	if ( (p = fopen ("prueba","r") ) == NULL) {
		PRS ("Error en apertura\n");
		getch(); exit(1);
	}
	q = fgets (a,5,p);
	while (!feof (p) ) {
		printf ("%s\n",q);
		q = fgets (a,5,p);
	}
	getch();
}

