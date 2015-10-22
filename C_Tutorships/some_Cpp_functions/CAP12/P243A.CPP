#include "stdio.h"
#include "dos.h"
#include "conio.h"
#define PR(x)  cprintf ("%2d :",x)
#define PR1(x)  cprintf ("%2d",x)

typedef struct time HORA;


void main()
{
	HORA p;
	int i;

	clrscr();
	p.ti_min = 0;
	p.ti_hour = 12;
	p.ti_sec = 1;
	p.ti_hund = 10;
	settime (&p);
	getch();
}
