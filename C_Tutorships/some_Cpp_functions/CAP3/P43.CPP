#include "stdio.h"
#include "string.h"
#include "math.h"
#include "errno.h"
#include "dos.h"
#include "conio.h"
#define PR(x) printf ("%s",x)
#define PRC(x) printf ("%3d  ",x)

void main()  {
	double x = 0.0,y;
	char *p;

	y = log10(x);
	p = strerror (errno);
	PRC(errno);
	PR(p);
   printf ("%lf\n",y);
	getch();
}
