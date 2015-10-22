/*********************************************************************/
/* EN ESTE PROGRAMA SE ENCUENTRAN LAS RUTINAS QUE MANEJAN UNA BICOLA */
/*********************************************************************/

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
	void deque_iniciar (struct nodo **p);
	void deque_insertar (struct nodo **p,int s,int lugar);
	void deque_retirar (struct nodo **p,int *s,int lugar);
   void listar (struct nodo *p);
	int objeto;

	deque_iniciar (&cab);
	deque_insertar (&cab,'A','d');
	deque_insertar (&cab,'B','d');
	deque_insertar (&cab,'S','i');
	deque_retirar (&cab,&objeto,'d');
	p1 (objeto);
	deque_insertar (&cab,'U','i');
	deque_retirar (&cab,&objeto,'d');
	p1 (objeto);
	deque_insertar (&cab,'C','i');
	deque_retirar (&cab,&objeto,'i');
	p1 (objeto);
	listar (cab);
}

void deque_iniciar (struct nodo **p)
{
	*p = localizar;
	(*p)->sig = *p;
}

void deque_insertar (struct nodo **p,int s,int lugar)
{
	struct nodo *nuevo,*q;

	nuevo = localizar;
	nuevo->info = s;
	if (lugar == 'd')  {
		 nuevo->sig = (*p)->sig;
			(*p)->sig = nuevo;
			*p = nuevo;
	}
	else {
			q = (*p)->sig;
			nuevo->sig = q->sig;
			q->sig = nuevo;
			if (*p == q )
						*p = nuevo;
		}
}

void deque_retirar (struct nodo **p,int *s,int lugar)
{
	struct nodo *q,*r;

	if (*p == (*p)->sig) {
		printf ("no existen objetos para retirar\n");
		*s = '#';
	}
	else {
			if (lugar == 'd')  {
				q = *p;
				do {
					q = q->sig;
				} while (q->sig != *p);
				*s = (*p)->info;
				q->sig = (*p)->sig;
				free (*p);
				*p = q;
			}
			else {
					q = (*p)->sig;
								 r = q->sig;
								 *s = r->info;
					q->sig = r->sig;
					if (*p == r )
					*p = q;
					free (r);
			}
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

