#include "iostream.h"
#include "stdio.h"
#include "stdarg.h"

void Constantes (char *msg1,char *msg2,char *msg3, ...) {
	va_list p;            	// Define el indicador de argumentos
	va_start (p,msg3);		// p indica el primer argumento variable
									// msg3 indica el nombre del ultimo argumento
									// fijo
	cout <<  msg1 << endl;
	cout <<  msg2 << endl;
	cout <<  msg3 << endl;
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
  Constantes ("alfa","beta","gamma",1,2,3,4,6,0);
}









