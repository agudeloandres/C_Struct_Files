/*******************************************************************/
/* EN ESTE PROGRAMA SE ENCUENTRAN LAS RUTINAS QUE MANEJAN UNA PILA */
/*******************************************************************/

#include <stdio.h>
#include <alloc.h>
#define p1(x)  printf ("%c  ",x)
#define MAXIMO 10

struct LIFO {
	int t;
	int a [MAXIMO];
};


void main()
{
	struct LIFO pila;
	void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void ins_pila (struct LIFO *p,int s);
	void retira_pila (struct LIFO *p,int *s);
	int s;
	init_pila (&pila);
	ins_pila (&pila,'A');
	retira_pila (&pila,&s);
	p1(s);
	ins_pila (&pila,'B');
	retira_pila (&pila,&s);
	p1 (s);
	ins_pila (&pila,'C');
	retira_pila (&pila,&s);
	p1 (s);
}


void init_pila (struct LIFO *p)
{
	p->t = 0;
}

int pila_vacia (struct LIFO *p)
{
	return (!p->t);
}

void ins_pila (struct LIFO *p,int s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
		  p->t++;
		  p->a [p->t - 1] = s;
	}
}

void retira_pila (struct LIFO *p,int *s)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = '#';
	}
	else  {
		  *s = p->a [p->t - 1];
		  p->t--;
	}
}



