#include "stdio.h"
#include "fcntl.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x) printf ("%s\n",x)


void main() {
	FILE *p;
	int c,j,i;
	long pos;
	int lea_entero();

	p = fopen ("prueba","wb");
	c = 0;
	while (c != 27) {
		PRS ("Lea un entero..");
		j = lea_entero();
		if (putw (j, p) == EOF) {
			PRS("Error en putw()");
			getch(); exit (1);
		}
		PRS ("Oprima una tecla. ESC para terminar.");
		c = getch();
		if (c == 0) c = getch();
	}
	fclose (p);
}

int lea_entero() {
	char a[10];
	gets(a);
	return atoi(a);
}