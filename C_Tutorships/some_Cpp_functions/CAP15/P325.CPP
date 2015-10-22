#include "dos.h"
#include "bios.h"
#include "time.h"    /* CLK_TCK  */
#include "conio.h"
#include "stdio.h"

void main() {
	long i;

	i = biostime (0,(long)0);
	printf ("%ld Pulsaciones =  %lf Segundos\n",i, i / CLK_TCK);
	getch();
}