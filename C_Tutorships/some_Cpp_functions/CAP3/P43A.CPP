#include "stdio.h"
#include "string.h"
#define PR(x) printf ("%s\n",x)
#include "conio.h"
void main()  {
	char *p;
	int n;

	n = 5;
	p = strerror (n);
	PR(p);
	getch();
}
