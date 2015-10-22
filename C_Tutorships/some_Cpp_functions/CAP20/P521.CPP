#include "stdio.h"
#include "stdlib.h"
#include "iostream.h"


// El arreglo debe No estar clasificado
// Si el numero no existe, se agrega a la tabla

int a[16] = { -4,2,4,6};  // Espacio para agregar llaves = 12

int *q = a;

void main() {
	int Comparacion (const void *p, const void *q);
	char aux[10];
	int n,*p;
	unsigned int NEntradas=4,NEAnterior;
	cout << "De numero a buscar" << endl;
	gets (aux);
	n = atoi (aux);
	while ( n != 9999 && NEntradas < 16) {
		NEAnterior = NEntradas;
		p =  (int *) lsearch (	(void *) &n, // Direccion de la llave
										(void *)a,  // Arreglo
										&NEntradas,		  // Numero de elementos
										sizeof (int), 	// Longitud de cada
															// elemento
										Comparacion
							);
		if (NEntradas == NEAnterior) {
				cout << "Ya existe, ";
				printf ("en la posicion = %d\n",p-q);
		}
		else {
						cout << "No existia. " << endl;
						cout << "Se agrego a la tabla\n";

						//  NEntradas++; lsearch hace esta operacion!!

		}
		cout << "De numero a buscar. 9999 para terminar " << endl;
		gets (aux);
		n = atoi (aux);
	}
	for (int i=0; i < NEntradas; i++)
		printf ("%d\n",  a[i]);
}

int Comparacion(const void *p,const void *q) {
	if ( *(int*)p  ==  *(int*)q)
		return 0;
	else if (*(int*)p > *(int*)q)
		return 1;
	else return -1;
}


