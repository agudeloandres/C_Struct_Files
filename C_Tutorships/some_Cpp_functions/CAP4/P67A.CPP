#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double x;
	char a[15] = "-48.35231",*p;

	x = strtod (a, &p);
	printf ("%lf\n",x);
	getch();
}



