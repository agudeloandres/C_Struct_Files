#include "dos.h"
#include "stdio.h"

// ****************************************************
// Este programa se debe ejecutar desde el ambiente DOS
// ****************************************************

void interrupt (*f)(...);  // Para C++. Ver programa p347

void main() {
	int i = 0;
	f = getvect (0x1b);
	for (; i <= 1000; i++) {
		if (i == 123)
			f();
		printf ("Cuando i = 123, se cancela el programa: %3d\n",i);
	}
}
