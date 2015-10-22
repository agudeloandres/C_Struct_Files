#include "stdio.h"
#include "stdlib.h"

int a[] ={ 23,5,3,46,8,545,3,12,45,9,8,67,45,34,2,45 };
void main() {
	int Comparacion (const void *p, const void *q);
	unsigned char i;
	qsort ( 	(void *)a, 				// Direccion del primer elemento
				sizeof(a) / sizeof (int); 	// Numero de entradas
				sizeof (int),			// Longitud de cada entrada
				Comparacion          // Funcion de comparacion
	);
	for (i=0; i < 16; i++)
		printf ("%d ",a[i]);
	printf ("\n");
}

int Comparacion(const void *p,const void *q) {
	if ( *(int*)p  ==  *(int*)q)
		return 0;
	else if (*(int*)p > *(int*)q)
		return 1;
	else return -1;
}

