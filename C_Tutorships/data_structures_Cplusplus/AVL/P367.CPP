/* ESTE PROGRAMA INCLUYE LAS RUTINAS QUE MANEJAN UN ARBOL AVL */


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <alloc.h>
#define nodo_arbol (struct nodo *) malloc (sizeof (struct nodo))
struct nodo {
	int info;
	int bal;
	struct nodo *izq;
	struct nodo *der;
};

void main()
{
	int n,lea();
	void inorden (struct nodo *raiz);
	int ins_avl(struct nodo **, int);
   int retirar_avl(struct nodo **, int);
	struct nodo *raiz=NULL;
	printf ("lea n \n"); n = lea();
	while (n != 9999) {
		ins_avl (&raiz,n);
		printf ("lea n \n"); n = lea();
	}
	inorden (raiz); printf ("\n");
	printf ("cual nodo desea retirar? \n");
	n = lea ();
	while (n != 9999) {
		retirar_avl (&raiz,n);
		inorden (raiz); printf ("\n");
		printf ("cual nodo desea retirar?\n");
		n = lea();
	}
	inorden(raiz); printf ("\n");
}
void inorden (struct nodo *raiz)
{
	if (raiz != NULL) {
		inorden (raiz->izq);
		printf ("%d %d   ",raiz->info,raiz->bal);
		inorden (raiz->der);
	}
}

void r_derecha (struct nodo *p,struct nodo *q)
{
	p->bal = 0;
	q->bal = 0;
	p->izq = q->der;
	q->der = p;
}
void r_izquierda (struct nodo *p,struct nodo *q)
{
	p->bal = 0;
	q->bal = 0;
	p->der = q->izq;
	q->izq = p;
}

void dr_derecha (struct nodo *p,struct nodo **q)
{
	struct nodo *r;

	r = (*q)->der;
	(*q)->der = r->izq;
	r->izq = *q;
	p->izq = r->der;
	r->der = p;
	switch (r->bal) {
		case -1 : (*q)->bal = 1;
				p->bal = 0;
				break;
		case  0 : (*q)->bal = p->bal = 0;
				break;
		case  1 : (*q)->bal = 0;
				p->bal = -1;
				break;
	}
	r->bal = 0;
	*q = r;
}
void dr_izquierda (struct nodo *p,struct nodo **q)
{
	struct nodo *r;

	r = (*q)->izq;
	(*q)->izq = r->der;
	r->der = *q;
	p->der = r->izq;
	r->izq = p;
	switch (r->bal) {
		case -1 : (*q)->bal = 0;
				p->bal = 1;
				break;
		case  1 : (*q)->bal = -1;
				p->bal =  0;
				break;
		case  0 : (*q)->bal = p->bal = 0;
				break;

	}
	r->bal = 0;
	*q = r;
}

void bal_der (struct nodo *q,struct nodo **t,int *terminar)
{
	switch (q->bal) {
		case  1 : q->bal = 0;
			  break;
		case -1 : *t = q->der;
			  switch ( (*t)->bal) {
					case 1 : dr_izquierda(q,t);
						 break;
					case -1: r_izquierda (q,*t);
						 break;
					case 0 : q->der = (*t)->izq;
						 (*t)->izq = q;
						 (*t)->bal = 1;
						 *terminar = 1;
						 break;
			  }
			  break;
		case  0 : q->bal = -1;
			  *terminar = 1;
			  break;
	}
}

void bal_izq (struct nodo *q,struct nodo **t,int *terminar)
{
	switch (q->bal) {
		case -1 : q->bal = 0;
			  break;
		case  1 : *t = q->izq;
			  switch ( (*t)->bal) {
			  case  1: r_derecha (q,*t);
				   break;
			  case -1: dr_derecha (q,t);
				   break;
			  case 0 : q->izq = (*t)->der;
				   (*t)->der = q;
				   (*t)->bal = -1;
				   *terminar = 1;
				   break;
			  }
			  break;
		case  0 : q->bal = 1;
			  *terminar = 1;
			  break;
	}
}


struct nodo *crear_nodo (int n)
{
	struct nodo *nuevo;

	nuevo = nodo_arbol;
	nuevo->info = n;
	nuevo->bal = 0;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	return (nuevo);
}

int ins_avl (struct nodo **raiz,int n)
{
	struct nodo *nuevo,*p,*q,*s,*pivote,*pp;
	int llave,altura;

	nuevo = crear_nodo(n);
	if (*raiz == NULL) {
		*raiz = nuevo;
		return (1);  /* el arbol tiene un solo nodo */
	}
	pp = q = NULL;
	pivote = p = *raiz;
	llave = nuevo->info;
	while (p != NULL) {
		if (p->bal) {
			pp = q;
			pivote = p;
		}
		if (llave == p->info) {
			free (nuevo);
			return (2); /* ya existe */
		}
		else {
				q = p;
				if (llave < p->info)
					p = p->izq;
				else p = p->der;
			}
	}
	if (llave < q->info)
		q->izq = nuevo;
	else q->der = nuevo;
	if (llave < pivote->info) {
		s = pivote->izq;
		altura  = 1;
	}
	else {
			s = pivote->der;
			altura = -1;
		}
	p = s;
	while (p != nuevo) 
		if (llave < p->info) {
			p->bal = 1;
			p = p->izq;
		}
		else {
				p->bal = -1;
				p = p->der;
			}
	if (pivote->bal == 0)
		pivote->bal = altura;
	else if (pivote->bal + altura == 0)
			pivote->bal = 0;
		else {
				if (altura == 1)
					if (s->bal == 1)
						r_derecha (pivote,s);
					else dr_derecha (pivote,&s);
				else if (s->bal == -1)
						r_izquierda (pivote,s);
					else dr_izquierda (pivote,&s);
				if (pp == NULL)
					*raiz = s;
				else if (pp->izq == pivote)
						pp->izq = s;
					else pp->der = s;
		}
		return 0;
}
int lea()
{
	char l[10];

	gets(l);
	return (atoi(l));
}

#define MAXIMO 20
struct LIFO {
	int t;
	struct nodo *a [MAXIMO];
};

int retirar_avl (struct nodo **raiz,int n)
 /* retira un nodo de un arbol avl  */
/* manteniendo esta propiedad */
{
	struct LIFO pila;
	void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void ins_pila (struct LIFO *p, struct nodo *s);
	void retira_pila (struct LIFO *p,struct nodo **s);
	struct nodo *p,*q,*t,*r;
	int encontro,llave,terminar,accion;

	if (*raiz == NULL) {
		printf ("arbol vacio\n");
		return (1);
	}
	init_pila (&pila);
	encontro = terminar = 0;
	p = *raiz;
	while (!encontro && p != NULL) {
		ins_pila (&pila,p);
		if (n < p->info)
			p = p->izq;
		else if (n > p->info)
			p = p->der;
		else encontro = 1;
	}
	if (!encontro) {
		printf ("no existe en el arbol\n");
		return (2);
	}
	t = NULL;
	retira_pila (&pila,&p);
	llave = p->info;
	if (p->izq == NULL && p->der == NULL)
		accion = 0;
	else if (p->der == NULL)
		accion = 1;
	else if (p->izq == NULL)
		accion = 2;
	else accion = 3;
	if (accion == 0 || accion == 1 || accion == 2) {
		if (!pila_vacia (&pila) ) {
			retira_pila (&pila,&q);
			if (llave < q->info) {
				switch (accion) {
				   case 0:
				   case 1: q->izq = p->izq;
					   bal_der (q,&t,&terminar);
						break;
					case 2: q->izq = p->der;
						bal_der (q,&t,&terminar);
					   break;
				}
			}
			else {
				switch (accion) {
				   case 0:
				   case 2: q->der = p->der;
					   bal_izq (q,&t,&terminar);
					   break;
				   case 1: q->der = p->izq;
					   bal_izq (q,&t,&terminar);
					   break;
				}
			}
		}
		else switch (accion) {
			case 0 : *raiz = NULL;
				 terminar = 1;
				 break;
			case 1 : *raiz = p->izq;
				 break;
			case 2 : *raiz = p->der;
				 break;
		     }
	}
	else {
			ins_pila (&pila,p);
			r = p; p = r->der;
			q = NULL;
			while (p->izq != NULL)  {
				ins_pila (&pila,p);
				q = p;
				p = p->izq;
			}
			llave = r->info = p->info;
			if (q != NULL) {
				q->izq =p ->der;
				bal_der (q,&t,&terminar);
			}
			else {
				r->der = p->der;
				bal_izq (r,&t,&terminar);
			}
			retira_pila (&pila,&q);
	}
	free (p);
	while (!pila_vacia (&pila)  && !terminar) {
		retira_pila (&pila,&q);
		if (llave < q->info) {
			if (t != NULL)  {
				q->izq = t;
				t = NULL;
			}
			bal_der (q,&t,&terminar);
		}
		else {
				if (t != NULL)  {
					q->der = t;
					t = NULL;
				}
				bal_izq (q,&t,&terminar);
			}
	}
	if (t != NULL)
		if (pila_vacia (&pila) )
			*raiz = t;
		else {
			retira_pila (&pila,&q);
			if (llave < q->info)
			     q->izq = t;
			else q->der = t;
		}
      return 0;
}

void init_pila (struct LIFO *p)
{
	p->t = 0;
}

int pila_vacia (struct LIFO *p)
{
	return (!p->t);
}

void ins_pila (struct LIFO *p, struct nodo *s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
			p->t++;
			p->a [p->t -1] = s;
	}
}

void retira_pila (struct LIFO *p,struct nodo **s)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = NULL;
	  }
	else  {
			*s = p->a [p->t -1];
			p->t--;
	}
}



