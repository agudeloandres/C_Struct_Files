#include "dos.h"
#include "conio.h"
#include "stdio.h"

#define p 0 				/* Puerto serial */
#undef outportb

void main() {
	unsigned char c = 'a';

	outportb (p, c);
	getch();
}


