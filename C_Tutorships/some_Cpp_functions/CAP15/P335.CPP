#include "dos.h"
#include "conio.h"
#include "stdio.h"
#include "stdlib.h"

void main() {
	long A,B,C,D;
	union REGS r;

	r.h.ah = 0x36;
	r.h.dl = 2;	/* Unidad B:  */
	if (intdos (&r, &r) == -1) {
		printf ("Unidad mal especificada\n");
		getch();
		exit(1);
	}

	if (r.x.cflag != 0)  {		/* Ocurrio un error */
		printf ("%s\n",strerror (_doserrno));
		getch();
		exit (1);
	}
	C = r.x.cx;
	A = r.x.ax;
	B = r.x.bx;
	D = r.x.dx;
	printf ("%-30s %ld\n","Bytes por Cluster",C * A);
	printf ("%-30s %ld\n","Numero total de bytes libres",C * A *B);
	printf ("%-30s %ld\n","Espacio total de almacenamiento",C * A * D);
	printf ("%-30s %lf\n","Porcentaje de espacio libre",B*100/(double)D);
	getch();
}





