#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char a[6][7] = {
	"uno   ",
	"dos   ",
	"tres  ",
	"cuatro",
	"cinco ",
	"seis  "
};
void main() {
	printf ("%d\n",sizeof(a[0]));
	int Comparacion (const void *p, const void *q);
	unsigned char i;
	qsort ( 	(void *)a, 				// Direccion del primer elemento
				6,							// Numero de entradas
				7,							// Longitud de cada entrada
				Comparacion          // Funcion de comparacion
	);
	for (i=0; i < 6; i++)
		printf ("%s ",a[i]);
	printf ("\n");
}

int Comparacion(const void *p,const void *q) {
	int i;
	i = strcmp (  (char *)p, (char *)q );
	return i;
}

