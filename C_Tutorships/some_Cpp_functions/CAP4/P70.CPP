#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	char a[] = "FTUVR",*p;
	int base = 32;
	long x;

	x = strtol (a,&p,base);
	printf ("%ld\n",x);
	getch();
}



