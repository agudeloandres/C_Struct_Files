#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "conio.h"
void main() {
	double x = 45.8231;
	int n,signo,d;
	char *p;

	d = 6;
	p = ecvt (x,d,&n,&signo);
	printf ("%s %d %d\n",p,n,signo);
	getch();
}
