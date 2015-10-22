#include <stdio.h>
#include <alloc.h>
#define  localizar  (struct nodo *) malloc (sizeof (struct nodo))

struct nodo {
	int info;
	struct nodo *sig;
};

void main()
{
	struct nodo  *cabeza;
	void retirar1 (struct nodo **cab, struct nodo *p, int *dato);
	void escribir_lista (struct nodo *p);
	struct nodo *insertar1 (struct nodo *p,int n);
	void insertar2 (struct nodo **p, int n);
	int numero;

	printf ("utilizando la funcion insertar2 ()\n");
	cabeza = NULL;
	printf ("de numero a insertar en la lista\n");
	scanf ("%d",&numero);
	while (numero != 9999) {
		insertar2 (&cabeza,numero);
		printf ("de numero a insertar en la lista\n");
		scanf ("%d",&numero);
	}
	numero = -1;
	retirar1 (&cabeza,cabeza->sig->sig,&numero);
	printf ("retirado...%d\n",numero);
	escribir_lista (cabeza);
}

struct nodo *insertar1 (struct nodo *p,int n)
{
	struct nodo *nuevo;

	nuevo = localizar;
	nuevo->info = n;
	if (p == NULL)
		nuevo->sig = nuevo;
	else {
			nuevo->sig = p->sig;
			p->sig = nuevo;
		}
	p = nuevo;
	return (p);
}
void insertar2 (struct nodo **p, int n)
{
	struct nodo *nuevo;

	nuevo = localizar;
	nuevo->info = n;
	if (*p == NULL)
		nuevo->sig = nuevo;
	else {
			nuevo->sig =(*p)->sig;
			(*p)->sig = nuevo;
		}
	*p = nuevo;
}

void escribir_lista (struct nodo *p)
{
	struct nodo *q;

	if (p==NULL)
		printf ("vacia\n");
	else {
			q = p;
			do {
				q=q->sig;
				printf ("%d ",q->info);
			} while (p != q);
			}
}

void retirar1 (struct nodo **cab, struct nodo *p, int *dato)
  /* retira el nodo despues de p */
{
	struct nodo *q;

	if (*cab ==NULL)
		printf ("no se pueden retirar nodos\n");
	else if (p == NULL)
		printf ("no se pueden retirar nodos\n");
		  else  if (*cab == (*cab)->sig)
				printf ("solamente un nodo... no se retiro\n");
			else {
				 q = p->sig;
				 *dato = q->info;
				 p->sig = q->sig;
				 if (q == *cab)
					 *cab = p;
				 free (q);
			 }
}
