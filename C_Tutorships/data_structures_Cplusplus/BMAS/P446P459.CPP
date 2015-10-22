/* En este programa se encuentran las rutinas que insertan y */
/* retiran llaves de un arbol b+ de cualquier orden. */

#include "stdio.h"
#include "alloc.h"
#include "stdlib.h"
#include "conio.h"
#define N 2
#define M 4
#define M1 5
#define MAXIMO 10
#define localizar (pagina *) malloc (sizeof (pagina))

typedef struct z pagina;
typedef struct LIFO LIFO;
typedef struct componente componente;
typedef struct LIFO1 LIFO1;
struct z {
	int cont;
	int info [M];
	pagina *apunt [M1];
};
struct LIFO {
	int t;
	pagina *a [MAXIMO];
};
struct componente  {
	pagina  *s;
	int v;
};

struct LIFO1 {
	int t;
	componente a [MAXIMO];
};



void main()
{
	pagina *raiz,*VSAM;
	int x,min,s;
	void ins_b (pagina **raiz,pagina **VSAM,int x,int *s);
	void listar_VSAM (pagina *VSAM);
	int retira_b (pagina **raiz,
				pagina **VSAM, int x, int *s);
	void listar_b (pagina *p);
	int lea();
	raiz = VSAM = NULL;
	printf ("Comienzo..\n");
	printf ("De llave\n");
	min = lea();
	while (min != 9999) {
		ins_b (&raiz, &VSAM, min, &s);
		if (s == 1)
			printf ("La llave ya existe en el arbol B+\n");
		/*printf ("\n");
		listar_b (raiz,0);
		printf ("\n");
		listar_VSAM (VSAM);*/
		printf ("De llave\n");
		min = lea();
	}
	listar_VSAM (VSAM);
	getch();

	printf ("\nRetiros\n");
	printf ("De llave a retirar\n");
	x = lea();
	while (x != 9999) {
		retira_b (&raiz, &VSAM, x, &s);
		if (s == 0)
			printf ("La llave no existe en el arbol B+\n");
		listar_b (raiz);
		printf ("\n");
		listar_VSAM (VSAM);
		printf ("De llave a retirar\n");
		x = lea();
	}
	printf ("\n");
	listar_b (raiz);
	getch();

}

void init_pila (struct LIFO *p)
{
	p->t = 0;
}

int pila_vacia (struct LIFO *p)
{
	return (!p->t);
}



void ins_pila (struct LIFO *p,pagina *s)
{
	if (p->t == MAXIMO) {
		printf ("la pila no soporta mas elementos\n");
		exit (1);
	}
	else  {
		  p->t++;
		  p->a [p->t - 1] = s;
	}
}

void retira_pila (struct LIFO *p,pagina **s)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		exit (1);
	}
	else  {
		  *s = p->a [p->t - 1];
		  p->t--;
	}
}


void init1_pila (struct LIFO1 *p)
{
	p->t = 0;
}

int pila1_vacia (struct LIFO1 *p)
{
	return (!p->t);
}

void ins1_pila (struct LIFO1 *p,pagina *s,int i)
{
	if (p->t == MAXIMO) {
		printf ("la pila no soporta mas elementos\n");
		exit (1);
	}
	else  {
			p->t++;
			p->a[p->t - 1].s = s;
			p->a[p->t - 1].v = i;
	}
}

void retira1_pila (struct LIFO1 *p,pagina **s,int *i)
{
	if (pila1_vacia (p) )  {
		printf ("la pila esta vacia\n");
		exit (1);
	}
	else  {
			*s = p->a [p->t -1].s;
			*i = p->a [p->t - 1].v;
			p->t--;
	}
}



void inicializar (pagina *p)
{
	int i;

	i=0;
	p->cont = 0;
	while (i < M1)
		p->apunt [i++] = NULL;
}

void crear_pagina (pagina **p,int x)
{
	*p = localizar;
	inicializar (*p);
	(*p)->cont = 1;
	(*p)->info [0] = x;
}

void buscar (pagina *p,int x,int *posicion,LIFO *pila)
{
	int i,encontro = 0;

	*posicion = -1;
	while (p && !encontro) {
		ins_pila (pila, p);
		i = 0;
		while (x > p->info [i] && i < p->cont - 1)
			i++;
		if (x < p->info [i])
			p = p->apunt [i];
		else if (x > p->info [i])
			if (p->apunt [0] != NULL)
				p = p->apunt [i+1];
			else p = NULL;
		else if (p->apunt [0] != NULL)
			p = p->apunt [i+1];
		else encontro = 1;
	}
	if (!encontro)
		*posicion = i;
}

void insertar (pagina *p,int x,int *i)
{
	int j;

	if (p->cont)
		if (x > p->info [*i])
			(*i)++;
		else {
			j = p->cont - 1;
			while (j >= *i) {
				p->info [j+1] = p->info [j];
				j--;
			}
		}
	p->cont++;
	p->info [*i] = x;
}

int donde (pagina *p, int x)
{
	int i;

	i= 0;
	while (x > p->info [i] && i < p->cont - 1)
		i++;
	return (i);
}

void romper (pagina *p,pagina *t,pagina **q,
		int x,int *subir,int separar)
{
	int a [M1], i=0 ,s = 0;
	pagina *b[M1+1], *temp;

	if (separar == 0) {
		temp = p->apunt [M];
		p->apunt[M] = NULL;
	}
	while (i < M && !s)
		if (p->info[i] < x) {
			a[i] =p->info [i];
			b[i] = p->apunt [i];
			p->apunt [i++] = NULL;
		}
		else s = 1;
	a[i] = x;
	b[i] = p->apunt [i];
	p->apunt [i] = NULL;
	b[++i] = t;
	while (i <= M) {
		a[i] =p->info [i-1];
		b[i+1] = p->apunt [i];
		p->apunt [i++] = NULL;
	}
	*q = localizar;
	inicializar (*q);
	i = 0;
	if (separar == 0) {
		p->cont = N;
		(*q)->cont = N + 1;
		(*q)->info [0] = a[N];
		while (i < N) {
			p->info [i] = a[i];
			p->apunt [i] = b [i];
			(*q)->info [i+1] = a[i+N+1];
			(*q)->apunt [i] = b[i+N+1];
			i++;
		}
		(*q)->apunt [M] = temp;
		p->apunt [M] = *q;
	}
	else {
		p->cont = (*q)->cont = N;
		while (i < N) {
			p->info [i] = a[i];
			p->apunt [i] = b [i];
			(*q)->info [i] = a[i+N+1];
			(*q)->apunt [i] = b[i+N+1];
			i++;
		}
	}
	p->apunt [N] = b [N];
	(*q)->apunt [N] = b [M1];
	*subir = a [N];
}

void cderecha_apunt (pagina *p,int i)
{
	int j;

	j = p->cont;
	while (j > i) {
		p->apunt [j] = p->apunt [j - 1];
		j--;
	}
}

void listar_b (pagina *p)
{
	int i;
	LIFO1 pila;

	init1_pila (&pila);
	while (p) {
		ins1_pila (&pila,p,0);
		p = p->apunt [0];
	}
	while (!pila1_vacia (&pila) ) {
		retira1_pila (&pila,&p,&i);
		if (i < p->cont) {
			printf ("%d ",p->info [i]);
			ins1_pila (&pila,p,i+1);
			if (p->apunt [0] != NULL)
				p = p->apunt [i+1];
			else p = NULL;
						while (p) {
				ins1_pila (&pila,p,0);
				p = p->apunt [0];
			}
		}
	}
}

void listar1_b (pagina *p,int l)
{
	int i;

	if (p) {
		for (i = 0; i < l; i++)
			printf ("  ");
		for (i = 0; i < p->cont; i++)
			printf ("%4d",p->info [i]);
		printf ("\n");
		listar1_b (p->apunt [0],l+1);
		for (i=1; i <= p->cont; i++)
			listar1_b (p->apunt [i], l+1);
	}
}

void listar_VSAM (pagina *VSAM)
{
	int i;

	while (VSAM != NULL ) {
		i = 0;
		while (i < VSAM->cont)
			printf ("%d ",VSAM->info[i++]);
		printf ("/");
		VSAM = VSAM->apunt[M];
	}
	printf ("\n");
}

void ins_b (pagina **raiz,pagina **VSAM,int x,int *s)
{
	int posicion,i,subir,subir1,terminar,separar;
	pagina *p,*nuevo,*nuevo1;
	LIFO pila;

	init_pila (&pila);
	*s = 0;
	if (*raiz == NULL) {
	   crear_pagina (raiz, x);
		*VSAM = *raiz;
	}
	else {
		buscar (*raiz, x, &posicion, &pila);
		if (posicion == -1)
		   *s = 1; /* La llave esta en el arbol */
		else {
			terminar = separar = 0;
			while (!pila_vacia (&pila) && terminar == 0) {
			  retira_pila (&pila, &p);
			  if (p->cont == M) {
			     if (separar == 0) {
				romper (p, NULL, &nuevo, x, &subir,separar);
				separar = 1;
				  }
			     else {
				     romper (p,nuevo,&nuevo1,subir,
						&subir1,separar);
				     subir = subir1;
				     nuevo = nuevo1;
			     }
			  }
			  else {
				  if (separar == 1) {
				     separar = 0;
				     i = donde (p, subir);
					  insertar (p, subir, &i);
					  cderecha_apunt (p, i+1);
				     p->apunt [i+1] = nuevo;
				  }
				  else insertar (p, x,&posicion);
				  terminar = 1;
			  }
			}
			if (separar == 1 && terminar == 0) {
				crear_pagina (raiz,subir);
				(*raiz)->apunt [0] = p;
				(*raiz)->apunt [1] = nuevo;
			}
		}
	}
}

int lea()
{
	char a[10];

	gets (a);
	return (atoi(a));
}

void retirar (pagina *p,int i)
{
	while (i < p->cont - 1) {
		p->info [i] = p->info [i+1];
		i++;
	}
	p->cont--;
}

void cambio (pagina *p,pagina *q,pagina *r,int i,int x)
{
	int k,t;

	if (x > r->info [r->cont - 1]) {
		t = q->info [i];
		retirar (q,i);
		k = 0;
		insertar (p,t,&k);
		t = r->info [r->cont - 1];
		retirar (r, r->cont - 1);
		k = i;
		if (k == -1)
			k = 0;
		insertar (q,t,&k);
	}
	else {
		t = q->info [i];
		retirar (q, i);
		k = p->cont - 1;
		if (k == -1)
			k = 0;
		insertar (p,t,&k);
		t = r->info [0];
		retirar (r, 0);
		k = i;
		if (q->cont != 0)
			if (k > q->cont - 1)
				k = q->cont -1;
		insertar (q,t,&k);
	}
}

int hoja (pagina *p)
{
	int j = 0;

	while (p->apunt [j] == NULL && j < p->cont - 1)
		j++;
	return (p->apunt [j] == NULL);
}

void cizquierda_apunt (pagina *p,int i,int j)
{
	while (i < j) {
		p->apunt [i] = p->apunt [i+1];
		i++;
	}
	p->apunt [i] = NULL;
}

void esta (pagina *p, int x, int *posicion, LIFO1 *pila)
{
	int i = 0,encontro = 0;

	*posicion = -1;
	while (p != NULL && !encontro) {
		i = 0;
		while (x > p->info [i] && i < p->cont - 1)
			i++;
		if (x < p->info [i]) {
			ins1_pila (pila, p, i);
			p = p->apunt [i];
		}
		else if (x > p->info [i]) {
			ins1_pila (pila, p, i+1);
			if (p->apunt [0] != NULL)
				p = p->apunt [i+1];
			else p = NULL;
		}
		else {
			if (p->apunt [0] != NULL) {
				ins1_pila (pila, p, i+1);
				p = p->apunt [i+1];
			}
			else {
				ins1_pila (pila, p, i);
				encontro = 1;
			}
		}
	}
	if (encontro == 1)
		*posicion = i;
}

void unir (pagina **raiz,  pagina *q, pagina *r, pagina *p,
			int  i, LIFO1 pila, int x, int posicion)
{
	int terminar = 0,j, k;
	pagina *t;

	retirar (p, posicion);
	if (x < r->info [0]) {
		t = p;
		p = r;
		r = t;
	}
	while (terminar == 0) {
	  if (r->cont < N && p->cont > N) {
		cambio (r, q, p, i, x);
		r->apunt [r->cont] = p->apunt [0];
		cizquierda_apunt (p, 0, p->cont + 1);
		terminar = 1;
	  }
	  else if (p->cont < N && r->cont > N) {
			cambio (p, q, r, i, x);
			cderecha_apunt (p, 0);
			p->apunt [0] = r->apunt [r->cont + 1];
			r->apunt [r->cont + 1] = NULL;
			terminar = 1;
	  }
	  else {
		  j = r->cont;
		  if (r->apunt [0] == NULL)    /* Si es ultimo nivel */
			r->apunt [M] = p->apunt [M];
		  else r->info [j++] = q->info [i];
		  k = 0;
		  while (k <= p->cont - 1)
			r->info [j++] = p->info [k++];
		  r->cont = j;
		  retirar (q, i);
		  k = 0;
		  j = M - p->cont;
		  while (p->apunt [k] != NULL)
			r->apunt [j++] = p->apunt [k++];
		  free (p);
		  if (q->cont == 0) {
			q->apunt [i+1] = NULL;
			if (pila1_vacia (&pila) ) {
				free (q);
				q = NULL;
			}
		  }
		  else cizquierda_apunt (q, i+1, q->cont+1);
		  if (q != NULL)
			if (q->cont >= N)
				terminar = 1;
			else {
				t = q;
				if (!pila1_vacia (&pila) ) {
					retira1_pila (&pila, &q, &i);
					if (x >= q->info [0]) {
						p = t;
						r = q->apunt [i-1];
						i--;
					}
					else {
						r = t;
						p = q->apunt [i+1];
					}
				}
				else terminar = 1;
			}
		  else {
				terminar = 1;
				*raiz = r;
		  }
	  }
	}
}

int retira_b (pagina **raiz, pagina **VSAM, int x, int *s)
{
	int posicion, i, k, temp;
	pagina *p, *q, *r;
	LIFO1 pila;

	*s = 1;
	init1_pila (&pila);
	esta (*raiz, x, &posicion, &pila);
	if (posicion == -1) {
		*s = 0;  /* La llave no existe en el arbol */
		return (0);
	}
	retira1_pila (&pila, &p, &i);
	if (p->cont > N) {
		retirar (p, posicion);
		return (1);
	}
	if (pila1_vacia (&pila)) {
		retirar (p, posicion);
		if (p->cont == 0) {
			free (*raiz);
			*raiz = *VSAM = NULL;
		}
		return (1);
	}
	retira1_pila (&pila, &q, &i);
	if (i < q->cont) {
		r = q->apunt [i+1];
		if (r->cont > N) {
			retirar (p, posicion);
			temp = r->info[0];
			retirar(r,0);
			retirar (q,i);
			k = donde (p, temp);
			insertar (p, temp, &k);
			k = donde (q, r->info [0]);
			insertar (q, r->info [0], &k);
			return (1);
		}
	}
	if (i > 0) {
		r = q->apunt [i-1];
		if (r->cont > N) {
			retirar (p, posicion);
			temp = r->info [r->cont - 1];
			retirar(r,r->cont - 1);
			retirar (q,i-1);
			k = donde (p, temp);
			insertar (p, temp, &k);
			k = donde (q, temp);
			insertar (q, temp, &k);
			return (1);
		}
	}
	if (i > 0)
		i--;
	unir (raiz,q,r,p,i,pila,x,posicion);
	return (1);
}
















