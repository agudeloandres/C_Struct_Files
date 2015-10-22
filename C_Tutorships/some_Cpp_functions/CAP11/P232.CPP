#include "stdio.h"
#include "dir.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x)  printf ("%s",x)
#define SALTO  printf ("\n")

void main() {
	char *a,*p,*q = "XXXXXX";

		  p = mktemp (q);
		  if (p == NULL) {
			  a = _strerror ("Error en mktemp ()");
			  PRS(a);
           getch(); exit (1);
        }
        PRS(p);
        SALTO;
        PRS(q);  /* Debe ser el mismo valor  de p */
        SALTO;   
        getch();
}


