#include "stdio.h"
#include "fcntl.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

#define PRS(x) printf ("%s\n",x)

void main() {
	FILE *p;
	char a[80],*q;
	int i;


	if ( (p = fopen ("prueba","r") ) == NULL) {
		PRS ("Error en apertura\n");
		getch(); exit(1);
	}
	q = fgets (a,100,p);
	while (!feof (p) ) {
		i = strlen(a);
		a[i-1] = '\0';
		printf ("%s\n",q);
		q = fgets (a,100,p);
	}
	getch();
}
