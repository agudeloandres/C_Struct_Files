#include "stdio.h"
#include "fcntl.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x) printf ("%s\n",x)


void main() {
	FILE *p;
	long pos,i,j;

	p = fopen ("prueba","rb");
	fseek (p,0L,SEEK_END);
	fgetpos(p,&pos);
	i = (int) (pos / sizeof (int) );   /* Numero de registros */
	fseek (p,0L,SEEK_SET);
	while (i > 0) {
		if (    (j = getw (p))  == EOF) {
			PRS("Error en getw()");
			getch(); exit (1);
		}
		printf ("%d\n",j);
		i--;
	}
        getch();
}

