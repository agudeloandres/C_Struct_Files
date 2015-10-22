#include "dos.h"
#include "conio.h"
#include "stdio.h"

#define p 0 				/* Puerto serial */
#undef import

void main() {
	unsigned int c;		/* 16 bits */

	c = inport (p);
	printf ("Palabra leida = %x\n",c);
	getch();
}


