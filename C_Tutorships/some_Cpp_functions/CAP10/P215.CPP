#include "stdio.h"
#include "fcntl.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x) printf ("%s\n",x)

struct DATOS {
	int i;
	char b[5];
	float y;
};


void main() {
	FILE *p;
	int i;
	struct DATOS dato;
	long pos;

	if (   (p = fopen ("prueba","rb")) == NULL) {
		PRS("error en fopen()");
		getch();
		exit(1);
	}

	fseek (p,(long)0,SEEK_END);
	fgetpos (p,&pos);
	i = (int) (pos / sizeof (struct DATOS));  /* Numero de registros */
	fseek (p,(long)0,SEEK_SET);
	while (i > 0) {
		if (fread (&dato, sizeof (struct DATOS), 1, p) != 1) {
			PRS ("Error en fread ()");
			printf ("%d\n",i);
			getch();
			exit (1);
		}
		printf ("%d %s %7.2f\n",dato.i,dato.b,dato.y);
		i--;
	}
        fclose (p);
        getch();
}
