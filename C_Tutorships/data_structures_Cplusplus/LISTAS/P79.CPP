#include <stdio.h>
#include <alloc.h>
#define  localizar  (struct nodo *) malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *sig;
};

void main()   /* crea una lista */
{
	struct nodo *cab,*q;
	void l_recursiva (struct nodo *p);
   void l1_recursiva (struct nodo *p);
	int i = 10;

	cab = NULL;
	while (i > 0) {
		q = localizar;
		q->info = i;
		q->sig = cab;
		cab = q;
		i = i - 1;
	}
	l_recursiva (cab);
	printf ("\n");
	l1_recursiva (cab);
}

void l_recursiva (struct nodo *p)
{
	if (p != NULL) {
		printf ("%d\n",p->info);
		l_recursiva (p->sig);
	}
}

void l1_recursiva (struct nodo *p)
{
	if (p != NULL) {
		l1_recursiva (p->sig);
		printf ("%d\n",p->info);
	}
}
