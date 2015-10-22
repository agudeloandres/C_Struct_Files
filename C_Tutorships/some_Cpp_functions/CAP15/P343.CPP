#include "dos.h"
#include "conio.h"
#include "stdio.h"
void main() {
	char far *p;

	p = getdta ();
	printf ("DTA = %Fp\n",p);
	getch();
}



