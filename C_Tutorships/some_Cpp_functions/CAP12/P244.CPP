#include "stdio.h"
#include "dos.h"
#include "conio.h"
#include "time.h"

void main()
{
	time_t   t,i;

	i = time (&t);
	printf ("Desde las 0 horas del primero de enero ");
	printf ("de 1970, han pasado %ld segundos\n",i);
				/* en i y en t, existe el mismo dato */
	getch();
}