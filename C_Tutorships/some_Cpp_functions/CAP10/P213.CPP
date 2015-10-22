#include "stdio.h"
#include "fcntl.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

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

	dato.i = 2345;
	strcpy (dato.b,"HORA");
	dato.y = 0.00345e+3;
	if (   (p = fopen ("prueba","wb")) == NULL) {
		PRS("error en fopen()");
		getch();
		exit(1);
	}
	i = 0;
	while  (i < 10) {
		if (fwrite ( &dato, sizeof (struct DATOS), 1, p) != 1) {
			PRS ("Error en fwrite()");
			getch();
			exit (1);
		}
		i++;
	}
	if (fclose(p) != 0) {
			PRS("error en fopen()");
		getch();
		exit(1);
	}
}
