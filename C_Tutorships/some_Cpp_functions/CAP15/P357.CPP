#include "dos.h"
#include "conio.h"
#include "stdio.h"

#define p 0 				/* Puerto serial */
#undef outport

void main() {
	unsigned int i = 0xffff;

	outport (p, i);
	getch();
}


