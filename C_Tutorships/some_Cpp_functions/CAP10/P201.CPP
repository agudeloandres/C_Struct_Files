#include "stdio.h"
#include "fcntl.h"
#define PRS(x) printf ("%s\n",x)
#include "conio.h"
#include "stdlib.h"

char a[] = "ESCRITORIO";
char b[] = "MESA";

void main() {
	FILE *p;
	int c;

	if ( (p = fopen ("prueba","w") ) == NULL) {
		PRS ("Error en apertura\n");
		getch(); exit(1);
	}
	if (fputs (a,p) == EOF) {
		PRS ("Error en fputs()");
		getch(); exit (1);
	}
	fputc ('\n',p);
	if (fputs (b,p) == EOF) {
		PRS ("Error en fputs()");
		getch(); exit (1);
	}
	fclose (p);
}
