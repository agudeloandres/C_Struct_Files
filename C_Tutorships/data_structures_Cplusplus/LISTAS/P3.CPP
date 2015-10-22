	#include "stdio.h"
	#include "alloc.h"
	#define L sizeof (struct R)

	struct R {
		int a;
		float b;
		long c;
		char *p;
	};

	void main()
	{
		int i = 10;
		struct R *q;
		void copiar (char *a,char *b);

		q = (struct R *) malloc (L);
		q->a = 8;
		q->b = 10.31;
		q->c = 0x4832aL;
		q->p = (char *)malloc (i);
		copiar (q->p,"TOTALES");
		printf ("%d\n",q->a);
		printf ("%f\n",q->b);
		printf ("%lx\n",q->c);
		printf ("%s\n",q->p);
	}

	void copiar (char *a,char *b)
	{
		while (*a++=*b++);
	}
