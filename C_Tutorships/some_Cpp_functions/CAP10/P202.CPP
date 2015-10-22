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

	if ( (p = fopen ("prueba","w") ) == NULL) {
		PRS ("Error en apertura\n");
		getch(); exit(1);
	}
	PRS ("De cadena");
	gets (a);
	while (strcmp(a,"final") != 0) {
		i = strlen (a);
		a[i] = '\n';
		a[++i] = '\0';
		fputs (a,p);
		PRS ("De cadena");
		gets(a);
	}
	fclose (p);
}
