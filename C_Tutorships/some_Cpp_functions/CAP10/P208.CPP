#include "stdio.h"
#include "fcntl.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

#define PRS(x) printf ("%s\n",x)

void main() {
	FILE *p;
	char a[80],*q;
	int i;

	if ( (p = fopen ("prueba","r+") ) == NULL) {   /* Actualizar */
		PRS ("Error en apertura\n");
		getch(); exit(1);
	}
	q = fgets (a,100,p);
	while (!feof (p) ) {
		i = strlen(a);
		a[i-1] = '\0';
		printf ("%s\n",q);
		q = fgets (a,100,p);
	}
	putchar('\n');
	rewind (p);
	fputc ('c',p);
	rewind(p);   /* No se puede retirar esta instruccion ya que en los
			archivos de texto, una escritura no puede seguir una
			lectura. Debe interponerse una instruccion rewind()
			o una instruccion fseek()  */
	q = fgets (a,100,p);
	while (!feof (p) ) {
		i = strlen(a);
		a[i-1] = '\0';
		printf ("%s\n",q);
		q = fgets (a,100,p);
	}
	getch();
}
