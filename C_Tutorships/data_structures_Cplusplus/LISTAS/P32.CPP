#include <stdio.h>
#include <alloc.h>
#define  localizar  (struct nodo *) malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *sig;
};

void main()
{
	struct nodo  *cabeza,*p;
	void retirar_p (struct nodo **cab,struct nodo *p,int *dato);
	void escribir_lista (struct nodo *q);
	void insertar (struct nodo **cab,struct nodo *p,
				struct nodo *q,int n);
	void mantener (struct nodo **cab, int n);

	int numero;

	cabeza = NULL;
	printf ("de numero a insertar en la lista\n");
	scanf ("%d",&numero);
	while (numero != 9999) {
		mantener (&cabeza,numero);
		printf ("de numero a insertar en la lista\n");
		scanf ("%d",&numero);
	}
	p = cabeza;
	numero = -1;
	retirar_p (&cabeza,p,&numero);
	printf ("retirado....%d\n",numero);
	escribir_lista (cabeza);

}

void retirar_p (struct nodo **cab,struct nodo *p,int *dato)
  /* retira el nodo  p */
{
	struct nodo *aux;

	if (p == NULL)
		printf ("no se puede retirar\n");
	else {
		*dato = p->info;
		if (p == *cab)
			*cab = p->sig;
		else {
			  aux = *cab;
			  while (aux->sig != p)
				  aux = aux->sig;
			  aux->sig = p->sig;
				}
				free (p);
			}
}
void escribir_lista (struct nodo *q)
{
	while (q != NULL) {
		printf ("%d  ",q->info);
		q = q->sig;
	}
}
void insertar (struct nodo **cab,struct nodo *p,
				struct nodo *q,int n)
{
	struct nodo *nuevo;

	nuevo = localizar;
	nuevo->info = n;
	nuevo->sig = q;
	if (p != NULL)
		p->sig = nuevo;
	else *cab = nuevo;
}

void mantener (struct nodo **cab, int n)
{
	struct nodo *p,*q;
	int encontro ;

	p = NULL;
	q = *cab;
	encontro = 0;
	while ((q != NULL) && (!encontro))
		if (n > q->info) {
			p = q;
			q = q->sig;
		}
		else  encontro = 1;
	if (encontro)
		if (n == q->info)
		  printf ("repetido\n");
		else insertar (cab,p,q,n);
	else insertar (cab,p,q,n);
}


