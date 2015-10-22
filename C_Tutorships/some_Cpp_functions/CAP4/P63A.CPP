#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	char a[40],*p;
	unsigned long i;
	int base;

	i = 0xab24b5af;		/* Un dato de tipo unsigned long */
	base = 2;  		/* La base debe estar entre 2-36 */
	p = ultoa (i,a,base);
	printf ("%s %s\n",a,p);
	getch();
}


