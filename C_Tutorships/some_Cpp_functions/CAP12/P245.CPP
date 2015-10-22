#include "stdio.h"
#include "dos.h"
#include "time.h"
#include "conio.h"

void main()
{
	time_t   t,i;
	char *p;

	i = time (&t);
	p = ctime (&i);  /* igual a: p = ctime (&t); */
	printf ("%s\n",p);
	getch();
}