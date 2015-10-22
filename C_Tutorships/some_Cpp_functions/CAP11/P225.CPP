#include "stdio.h"
#include "dir.h"
#include "dos.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x)  printf ("%s",x)
#define SALTO  printf ("\n")

struct t1 {
	unsigned segundos : 5;
	unsigned minutos : 6;
	unsigned horas : 5;
};

union TIEMPO {
	unsigned tiempo;
	struct t1 t1;
};

struct f1 {
	unsigned dia : 5;
	unsigned mes : 4;
	unsigned ano :7;
};

union FECHA {
	unsigned fecha;
	struct f1 f1;
};

/* Se debe recordar que dos backslash dentro de una cadena significa
	un backslash. */

void main() {
	char *q;
	struct ffblk p;
	union TIEMPO tiempo;
	union FECHA fecha;
	int final;

	clrscr();
	if ( (final = findfirst ("c:\\bogota\\*.*",&p,FA_ARCH)) == -1) {
		q = _strerror ("Error en findfirst ()");
		PRS(q);
		getch(); exit (1);
	}
	printf ("Dir = c:\\bogota\*.*\n\n");
	while ( final == 0) {
		tiempo.tiempo = p.ff_ftime;
		fecha.fecha = p.ff_fdate;
			printf ("%-20s ",p.ff_name);
		printf ("%d  ",p.ff_attrib);
		printf ("%2u %2u %2u  ",tiempo.t1.horas,
			tiempo.t1.minutos,tiempo.t1.segundos / 2);
		printf ("%5u %2u %2u  ",fecha.f1.ano + 1980,
			fecha.f1.mes,fecha.f1.dia);
		printf ("%5ld\n",p.ff_fsize);
		final = findnext (&p);
	}
	getch();
}


