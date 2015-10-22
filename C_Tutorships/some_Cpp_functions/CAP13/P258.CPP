#include "stdio.h"
#include "alloc.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"

#define PR(x)  printf ("%s\n",x)

void main() {
	char far *p,*q;

	p = (char far*)farmalloc (20);  /* Devuelve una direccion a un void */
	strcpy (p,"MEMORIA");
	q = strcat (p," DINAMICA");
	PR(q);
	getch();
}
