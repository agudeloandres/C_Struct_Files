#include "dos.h"
#include "conio.h"
#include "stdio.h"
#define p 0 				/* Puerto serial */
#undef importb

void main() {
	unsigned char c;		/* 8 bits */

	c = inportb (p);
	printf ("Byte leido = %c\n",c);
	getch();
}


