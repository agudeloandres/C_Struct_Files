#include "stdio.h"
#include "alloc.h"
void main()
{
	char *p;
	int n=10;
	void copiar (char *a,char *b);

	p = (char *)malloc (n);
	copiar (p,"sencillo");
	printf ("%s",p);
}

void copiar (char *a,char *b)
{
	while (*a++ = *b++)
		;
}
