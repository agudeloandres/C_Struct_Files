	#include "stdio.h"
	#include "alloc.h"
	void main ()
	{
		char	*p,*q;
		int n=50;
		void copiar (char *a,char *b);

/*1*/		p = (char *)malloc (n);
/*2*/		copiar (p,"pascal");
/*3*/		q = (char *)malloc (n);
/*4*/		copiar (q,"lenguaje C");

		/* otras instrucciones */

/*30*/		q = p;
	}

void copiar (char *a,char *b)
{
	while (*a++=*b++);
}
