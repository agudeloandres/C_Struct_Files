#include "iostream.h"
#include "stdio.h"
#include "stdarg.h"

void Constantes (char *msg, ...) {
	va_list p;            	// Define el indicador de argumentos
	va_start (p,msg);			// p indica el primer argumento variable
									// msg indica el nombre del ultimo argumento
									// fijo
	cout <<  msg << endl;
	int i = va_arg (p,int); // Avanza p en 2 bytes y deja el
									// en i
	while (i != 0) {
		cout << i << endl;
		i = va_arg (p,int);
	}
	va_end (p);             // Termina el proceso. Esta instruccion
									// es obligatoria
}

void main() {
  Constantes ("a",1,2,3,4,6,0);
}









