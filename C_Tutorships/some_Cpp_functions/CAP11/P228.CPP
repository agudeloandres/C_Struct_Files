#include "stdio.h"
#include "dir.h"
#include "dos.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

#define PRS(x)  printf ("%s",x)
#define SALTO  printf ("\n")

void main() {
	char *q,a[100];
	struct ffblk p;
	int final;

	clrscr();
	final = findfirst ("c:\\pm\\*.*",&p,FA_ARCH);
	while ( final == 0) {
		strcpy (a,"c:\\pm\\");
		strcat (a,p.ff_name);
		unlink (a);
		final = findnext (&p);
	}
	if (rmdir ("c:\\pm") == -1) {
		q = _strerror ("Error en rmdir()");
		PRS(q);
		getch();
		exit(1);
	}
	PRS("Directorio c:\\pm borrado del disco");
	SALTO;
	getch();
}


