#include "stdio.h"
#include "dir.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x)  printf ("%s",x)
#define SALTO  printf ("\n")

void main() {
	char *a,*p,*q;
	int n = 100;

	a = NULL;
	p = getcwd (a, n);
        if (p == NULL) {
           q = _strerror ("Error en getcwd()");
           PRS(q);
           getch(); exit (1);
        }
        PRS("Directorio actual --> ");
        PRS(p);
        SALTO;
        free(p);
        getch();
}


