#include "stdio.h"
#include "stdlib.h"
#include "iostream.h"


// El arreglo debe estar clasificado

int a[16] ={ -4,2,4,6,7,10,30,31,56,67,80,81,100,123,456,2345 };
int *q = a;
void main() {
	int Comparacion (const void *p, const void *q);
	char aux[10];
	int n,*p;
	cout << "De numero a buscar" << endl;
	gets (aux);
	n = atoi (aux);
	while ( n != 9999) {
		p =  (int *) bsearch (	(void *) &n, // Direccion de la llave
										(void *)a,  // Arreglo
										16,		  // Numero de elementos
										sizeof (int), 	// Longitud de cada
															// elemento
										Comparacion
							);
		if (p != NULL) {
			cout << "Si existe, ";
			printf ("en la posicion = %d\n",p-q);
		}
		else cout << "No existe " << endl;
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


