#include "stdio.h"
#include "stdlib.h"
#include "iostream.h"


// El arreglo NO debe estar clasificado
// Si el numero no existe, NO se agrega a la tabla

int a[16] = { -4,2,4,6,56,7,4,-1,34,56,32,4,32,12,2132,-1};

int *q = a;

void main() {
	int Comparacion (const void *p, const void *q);
	char aux[10];
	int n,*p;
	unsigned int Num = sizeof (a) / sizeof (int);
	cout << "De numero a buscar" << endl;
	gets (aux);
	n = atoi (aux);
	while ( n != 9999 ) {
		p =  (int *) lfind (	(void *) &n, // Direccion de la llave
										(void *)a,  // Arreglo
										&Num,		  // Numero de elementos
										sizeof (int), 	// Longitud de cada
															// elemento
										Comparacion
							);
		if (p != NULL) {
				cout << "Si existe, ";
				printf ("en la posicion = %d\n",p-q);
		}
		else {
						cout << "No existe. " << endl;

		}
		cout << "De numero a buscar. 9999 para terminar " << endl;
		gets (aux);
		n = atoi (aux);
	}
}

int Comparacion(const void *p,const void *q) {
	if ( *(int*)p  ==  *(int*)q)
		return 0;
	else if (*(int*)p > *(int*)q)
		return 1;
	else return -1;
}


