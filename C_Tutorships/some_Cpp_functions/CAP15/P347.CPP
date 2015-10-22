#include "dos.h"
#include "conio.h"
#include "stdio.h"

#ifdef __cplusplus
  #define TRESPUNTOS ...
#else
  #define TRESPUNTOS
#endif

// *******************************************
// Este programa se debe ejecutar desde el DOS
// *******************************************

void interrupt (*f)(TRESPUNTOS);

void main() {
	f = getvect (0x5);
	f();
	getch();
}
