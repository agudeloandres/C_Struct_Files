/*********************************************/
/* EN ESTE PROGAMA SE ENCUENTRAN LAS RUTINAS */
/* QUE MANEJAN UNA ESTRUCTURA COMPUESTA POR  */
/* DOS COLAS                                 */
/*********************************************/

#include <stdio.h>
#include <alloc.h>
#define p1(x) printf ("cliente atendido... %c\n",x)
#define localizar  (struct nodo *) malloc (sizeof (struct nodo))
struct nodo {
	int info;
	struct nodo *sig;
};

void main()
{
	struct nodo *cab,*cab1;
	void iniciar_id (struct nodo **p,struct nodo **q);
	void sumar_id (struct nodo **p,int n);
	void atender_id (struct nodo **p,
					struct nodo *q,int *);
	void listar (struct nodo *p);
	int objeto;
	iniciar_id (&cab,&cab1);
	sumar_id (&cab,'A');
	sumar_id (&cab,'B');
	sumar_id (&cab1,'S');
	atender_id (&cab,cab1,&objeto);
	p1 (objeto);
	sumar_id (&cab1,'T');
	atender_id (&cab,cab1,&objeto);
	p1 (objeto);
	sumar_id (&cab1,'U');
	atender_id (&cab1,cab,&objeto);
	p1 (objeto);
	sumar_id (&cab,'C');
	listar (cab);
}

void iniciar_id (struct nodo **p,struct nodo **q)
{
	*p = localizar;
	*q = localizar;
	(*p)->info = '#';
	(*q)->info = '#';
	(*p)->sig = *q;
	(*q)->sig = *p;
}

void sumar_id (struct nodo **p,int n)
{
	struct nodo *nuevo;

	nuevo = localizar;
	nuevo->info = n;
	nuevo->sig = (*p)->sig;
	(*p)->sig = nuevo;
	*p = nuevo;
}

void atender_id (struct nodo **p,struct nodo *q,int *n)
{
	struct nodo *s,*v;

	if ((*p)->info  ==  '#') {
		printf ("no existen objetos para atender\n");
		*n = '#';
	}
	else {
		  s = q->sig;
		  v = s->sig;
		  *n = v->info;
		  s->sig = v->sig;
		  if (*p == v )
			  *p = s;
		  free (v);
	}
}


void listar (struct nodo *p)
{
	struct nodo *q;

	q = p;
	do  {
		q = q->sig;
		printf ("%c  ",q->info);
	}  while (q != p);
}

int vacia (struct nodo **p)
{
	return (*p == (*p)->sig);
}
