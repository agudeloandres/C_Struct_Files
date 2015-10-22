#include "stdio.h"
#include "dos.h"
#include "conio.h"

typedef struct date DATE;

void main()
{
	DATE p;

	p.da_year = 1991;
	p.da_mon = 8;
	p.da_day = 7;
	setdate (&p);
	printf ("Oprima una tecla...\n");
	getch();
}