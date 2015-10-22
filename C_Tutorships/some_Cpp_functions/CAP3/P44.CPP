#include "stdio.h"
#include "string.h"
#include "math.h"
#include "errno.h"
#include "dos.h"
#include "conio.h"
#define PR(x) fprintf (imp,"%s",x)
#define PRC(x) fprintf (imp,"%3d  ",x)

void main()  {
	char *p;
	FILE *imp = fopen ("PRN","w");

	for (errno=0; errno <= 35; errno++) {
		PRC(errno);
		p = strerror (errno);
		PR(p);
	}
	getch();
}
