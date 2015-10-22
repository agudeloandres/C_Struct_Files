#include "stdio.h"
#include "dir.h"
#include "dos.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

#define PRS(x)  printf ("%s",x)
#define SALTO  printf ("\n")


/* Se debe recordar que dos backslash dentro de una cadena significa
	un backslash. */

void main() {
	char *q,a[100];
	struct ffblk p;
	int final;

	clrscr();
	if ( (final = findfirst ("c:\\bogota\\*.*",&p,FA_ARCH)) == -1) {
		q = _strerror ("Error en findfirst ()");
		PRS(q);
		getch(); exit (1);
	}
	while ( final == 0) {
		strcpy (a,"c:\\bogota\\");
		strcat (a,p.ff_name);
		unlink (a);
		printf ("Archivo %s  borrado..\n",a);
		final = findnext (&p);
	}
	getch();
}


