/**************************************************/
/* EN ESTE PROGRAMA SE ENCUENTRAN LAS RUTINAS QUE */
/* MANEJAN UNA COLA. SE PUEDE UTILIZAR LA RUTINA  */
/* atender() O atender_1() INDIFERENTEMENTE.      */
/**************************************************/

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
	struct nodo *cab;
	int cliente;
	void iniciar (struct nodo **p);
	void sumar (struct nodo **p,int objeto);
	void atender (struct nodo **p,int *s);
	void atender_1 (struct nodo **p,int *s);
	void listar (struct nodo *p);
	iniciar (&cab);
	sumar (&cab,'A');
	sumar (&cab,'B');
	atender (&cab,&cliente);
	p1 (cliente);
	sumar (&cab,'C');
	sumar (&cab,'D');
	sumar (&cab,'E');
	atender (&cab,&cliente);
	p1 (cliente);
	atender (&cab,&cliente);
	p1 (cliente);
	sumar (&cab,'F');
	atender (&cab,&cliente);
	p1 (cliente);
	atender (&cab,&cliente);
	p1 (cliente);
	listar (cab);
}

void iniciar (struct nodo **p)
{
	*p = localizar;
	(*p)->sig = *p;
}

void sumar (struct nodo **p,int objeto)
{
	struct nodo *nuevo;

	nuevo = localizar;
	nuevo->info = objeto;
	nuevo->sig = (*p)->sig;
	(*p)->sig = nuevo;
	*p = nuevo;
}

void atender (struct nodo **p,int *s)
{
	struct nodo *q,*r;

	if (*p == (*p)->sig) {
		printf ("no existen objetos para atender\n");
		*s = '#';
	}
	else {
		  q = (*p)->sig;
		  r = q->sig;
		  *s = r->info;
		  q->sig = r->sig;
		  if (q == q->sig)
				*p = q;
		  free (r);
	}
}

void atender_1 (struct nodo **p,int *s)
{
	struct nodo *q,*r;
	int vacia (struct nodo **p);
	if (vacia (p)) {
		printf ("no existen objetos para atender\n");
		*s = '#';
	}
	else {
		  q = (*p)->sig;
		  r = q->sig;
		  *s = r->info;
		  q->sig = r->sig;
		  if (q == q->sig)
			  *p = q;
		  free (r);
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