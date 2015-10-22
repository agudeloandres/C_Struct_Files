#include "stdio.h"
#include "dos.h"
#include "conio.h"

typedef struct date DATE;
char *mes[] = { "zzz","ene","feb","mar","arb","may","jun",
		"jul","ago","sep","oct","nom","dic"
};

void main()
{
	DATE p;

	getdate (&p);
	printf ("a¤o = %d\nmes = %s\ndia = %d\n",p.da_year,mes [p.da_mon],
						 p.da_day);
	getch();
}