#include "stdio.h"
#include "fcntl.h"
#include "conio.h"
#include "stdlib.h"
#include "time.h"
#define PRS(x) printf ("%s\n",x)

void main() {
	FILE *p;
	int i,num;
	long pos;

	randomize();
	if ( (p = fopen ("prueba","r") ) == NULL) {
		PRS ("Error en apertura\n");
		getch(); exit(1);
	}
	num = random (50);
	printf ("Numero aleatorio generado = %d\n",num);
	fseek (p,(long)num,SEEK_SET);
	if ( (pos = ftell (p) ) == -1) {
		PRS("Error funcion fgetpos()");
		getch(); exit (1);
	}
	printf ("Posicion del apuntador del archivo = %ld\n",pos);
	fclose (p);
	getch();
}
