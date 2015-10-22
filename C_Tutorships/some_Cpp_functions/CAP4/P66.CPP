#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double x = 0.0045321789;
	int d = 7;
	char a[15],*p;

	p = gcvt (x,d,a);
	printf ("%s %s\n",p,a);
	getch();
}
