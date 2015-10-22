#include "stdio.h"
#include "dos.h"
#include "conio.h"
#define PR(x)  cprintf ("%2d :",x)
#define PR1(x)  cprintf ("%2d",x)

typedef struct time HORA;

/* Escribe la hora durante 20 veces con intervalos de 1 segundo */

void main()
{
	HORA p;
	int i;

	clrscr();
	gettime (&p);
	for (i = 1; i <= 20; i++) {
		gotoxy(10,10);
		PR(p.ti_hour);
		PR(p.ti_min);
		PR(p.ti_sec);
		PR1(p.ti_hund);
		delay (1000); /* Para un segundo la ejecucion  */
		gettime (&p);
	}
	getch();
}