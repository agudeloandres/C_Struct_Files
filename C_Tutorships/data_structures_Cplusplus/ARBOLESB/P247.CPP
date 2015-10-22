/* EN ESTE PROGRAMA SE INCLUYEN LAS RUTINAS QUE MANEJAN UNA
	COLA DE PRIORIDAD */

#include "stdio.h"
#define MAXIMO 100

struct arbol {
	int cont;
	int a[MAXIMO];
};

void main()
{
	void retirar_p (struct arbol *m,int *elemento);
	void crea_p (struct arbol *m,int dato);
	int lea_entero ();
	void inicia_p (struct arbol *m);
	struct arbol cola_p;
	int n;

	inicia_p (&cola_p);
	printf ("de prioridad\n");
	n = lea_entero();
	while (n != 9999) {
		crea_p (&cola_p,n);
		printf ("de prioridad\n");
		n = lea_entero();
	}
	printf ("Retiro de elementos de la estructura\n");
	while (cola_p.cont != 0) {
		retirar_p (&cola_p,&n);
		printf ("%d ",n);
	}
	printf ("\n");
}

int lea_entero ()
{
	int i;
	scanf ("%d",&i);
	return (i);
}

void inicia_p (struct arbol *m)
{
	m->cont = 0;
	m->a[0] = 32767;
}

void crea_p (struct arbol *m,int dato)
{
	int i,j;

	m->cont++;
	i = m->cont;
	j = i / 2;
	while (m->a[j] < dato ) {
		m->a[i] = m->a[j];
		i = j;
		j = i / 2;
	}
	m->a[i] = dato;
}

void retirar_p (struct arbol *m,int *elemento)
{
	int i,j,temp;

	*elemento = m->a[1];
	temp = m->a[m->cont];
	m->cont--;
	i = 1;
	j = 2;
	while (j <= m->cont) {
		if (j < m->cont)
			if (m->a[j] < m->a[j+1])
				j++;
		if (temp >= m->a[j])
			break;
		m->a[i] = m->a[j];
		i = j;
		j = 2 * i;
	}
	m->a[i] = temp;
}


	
