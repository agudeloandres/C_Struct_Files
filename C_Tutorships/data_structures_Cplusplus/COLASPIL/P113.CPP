/* RUTINAS QUE MANEJAN UNA PILA UTILIZANDO MEMORIA DINAMICA */

#include <stdio.h>
#include <alloc.h>
#define localizar  (struct LIFO *)  malloc (sizeof (struct LIFO) )
#define p1(x)  printf ("%c\n",x)
#define MAXIMO 10

struct LIFO {
	int info;
	struct LIFO *sig;
};

 
void main()
{
	struct LIFO *pila;
	void init_pm (struct LIFO **p);
	int vacia_pm (struct LIFO **p);
	void retirar_pm (struct LIFO **p,int *s);
   void ins_pm (struct LIFO **p,int s);
	int s;
	init_pm (&pila);
	ins_pm (&pila,'A');
	ins_pm (&pila,'B');
	retirar_pm (&pila,&s);
	p1 (s);
	retirar_pm (&pila,&s);
	p1 (s);
	ins_pm (&pila,'C');
	retirar_pm (&pila,&s);
	p1 (s);
	retirar_pm (&pila,&s);
	p1 (s);
}

void init_pm (struct LIFO **p)
{
	*p = NULL;
}

int vacia_pm (struct LIFO **p)
{
	return (*p == NULL);
}

void ins_pm (struct LIFO **p,int s)
{
	struct LIFO *nuevo;

	nuevo = localizar;
	nuevo->info = s;
	nuevo->sig = *p;
	*p = nuevo;
}

void retirar_pm (struct LIFO **p,int *s)
{
	struct LIFO *q;

	if (vacia_pm (p)  ) {
		 printf ("la pila esta vacia\n");
		 *s = '#';
	}
	else {
		 q = (*p)->sig;
		 *s = (*p)->info;
		 free (*p);
		 *p = q;
	}
}
