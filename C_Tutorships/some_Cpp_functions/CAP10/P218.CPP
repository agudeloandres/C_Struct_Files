#include "stdio.h"
#include "fcntl.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x) printf ("%s\n",x)

void main() {
	FILE *p,*q;
	long pos;
	int i,j;

	p = fopen ("prueba","rb");
	q = fopen ("PRN","w");  /* Abre la impresora */
	fseek (p,0L,SEEK_END);
	fgetpos(p,&pos);
	i = (int) (pos / sizeof (int) );   /* Numero de registros */
	fseek (p,0L,SEEK_SET);
	while (i > 0) {
		if (    (j = getw (p))  == EOF) {
			PRS("Error en getw()");
			getch(); exit (1);
		}
		fprintf (q,"%d  ",j);   /* Escribe en la impresora */
		i--;
	}
	fprintf (q,"\n");  /* Imprime lo que pueda quedar en el buffer
					de la impresora */
	fclose (p);
	fclose (q);
	getch();
}


