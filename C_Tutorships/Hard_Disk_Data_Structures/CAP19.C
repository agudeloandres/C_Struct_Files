/* Este programa maneja un cursor indexado a traves de un arbol B+ */
/* Se ejecuta desde el programa MCURB19.c */

#define N 2
#define M N*2
#define M1 M+1
#define MAXIMO 20
#define MAX 10
#define INTERNA 0
#define EXTERNA 1
#define P(x)  printf ("%s\n",x)

typedef struct LIFO LIFO;
typedef struct LIFO1 LIFO1;
typedef struct z CURSOR;
typedef struct REG REG;

struct LIFO {
	int t;
	int a[MAX];
};

struct datos {
	int direccion;
	int d;
};

struct REG {
	int cod;
	char nombre [30];
};

struct LIFO1 {
	int t;
	struct datos a[MAX];
};

struct z {
	int cont;
	int tipo;
	int info [M];
	int apunt [M1];
};

CURSOR a[MAXIMO];
REG datos [MAXIMO * M];

captu ()
{
	capturar (a, datos);
}

consul ()
{
	consul1 (a, datos);
}
retira ()
{
	retirar1 (a, datos);
}

listar ()
{
	listar_VSAM (a,datos);
	printf ("\nOprima una tecla\n");
	getch();
}

inicia ()
{
	init_cursor (a, datos);
}


consul1 (CURSOR a[], REG b[])
{
	int n,posicion,donde_esta;
	LIFO pila;

	P("De numero. <9999> para finalizar.");
	n = lea ();
	while (n != 9999) {
		init_pila (&pila);
		donde_esta = buscar (a,n,&posicion,&pila);
		if (posicion == -1)
			printf ("%d %s\n",b[donde_esta].cod,
					b[donde_esta].nombre);
		else P("No existe. Trate otra vez...");
		P("De numero. <9999> para finalizar.");
		n = lea ();
	}
}
	/*
lea_reg (REG *p) {
	char a[40];

	printf ("De codigo\n");
	gets (a);
	p->cod = atoi (a);
	printf ("De nombre\n");
	gets (a);
	strcpy (p->nombre,a);
}
*/

lea_reg (REG *p) {
	char a[40];

	p->cod = random (101);
	itoa (p->cod,a,10);
	strcpy (p->nombre,a);
}

capturar (CURSOR a[], REG datos[])
{
	int s,n,raiz,i;
	REG registro;

	printf ("De registro de datos. 9999 para finalizar\n");
	lea_reg (&registro);
	i=0;
	n = registro.cod;
	while (i <= 15) {
		ins_bmas (a, datos, n, &s, registro);
		if (s == 1)
			printf ("\nLa llave ya existe\n");
		lea_reg (&registro);
		n = registro.cod;
		i++;
	}
	getch();
}

retirar1 (CURSOR a[], REG b[])
{
	int n,raiz,s,VSAM;

	printf ("De llave a retirar. 9999 para finalizar\n");
	n = lea();
	while (n != 9999) {
		raiz = a[0].cont;
		VSAM = a[0].info[0];
		retira_b (a, b, &raiz, &VSAM, n, &s);
		a[0].cont = raiz;
		a[0].info[0] = VSAM;
		if (s == 0)
			printf ("La llave no existe\n");
		printf ("De llave a retirar. 9999 para finalizar\n");
		n = lea();
	}
	printf ("\n");
	listar_b (a,datos);
	printf ("\nOprima una tecla\n");
	getch();
}

init_cursor (CURSOR a[], REG b[])
{
	int i,j;

	for (i=0; i < MAXIMO; i++) {
		a[i].cont = a[i].tipo = 0;	/* raiz del arbol */
		for (j=0; j < M; j++)		/* a[0].info = VSAM */
			a[i].info [j] = 0;
		for (j=0; j < M1-1; j++)
			a[i].apunt [j] = 0;
		a[i].apunt [j] = i+1;
	}
	a[i-1].apunt [M1-1] = 0;
	for (i=0; i < MAXIMO * M - 1; i++) {
		b[i].cod = i+1;
		strcpy (b[i].nombre, "vacio");
	}
	b[i].cod = 0;
}

inicializar (CURSOR a[],int p)
{
	int i,j;

	a[p].cont = 0;
	for (j=0; j < M; j++)
		a[p].info [j] = 0;
	for (j=0; j < M1; j++)
		a[p].apunt [j] = 0;
}

crear_pagina (CURSOR a[],int x)
{
	int p;

	p = disp (a);
	if (p == -1) {
		printf ("cursor lleno...");
		getch();
		exit (1);
	}
	inicializar (a, p);
	a[p].cont = 1;
	a[p].info [0] = x;
	return (p);
}

disp (CURSOR a[])
{
	int i = a[0].apunt [M1-1];

	if (i==0)
		return (-1);
	else {
		a[0].apunt [M1-1] = a[i].apunt [M1-1];
		return (i);
	}
}


crear_reg (REG a[],REG registro)
{
	int p;

	p = disp_reg (a);
	if (p == -1) {
		printf ("cursor de datos lleno...");
		getch();
		exit (1);
	}
	a [p].cod = registro.cod;
	strcpy (a[p].nombre, registro.nombre);
	return (p);
}

disp_reg (REG a[])
{
	int i = a[0].cod;

	if (i==0)
		return (-1);
	else {
		a[0].cod = a[i].cod;
		return (i);
	}
}

buscar (CURSOR a[],int x,int *posicion,LIFO *pila)
{
	int i,encontro = 0,p;

	*posicion = -1;
	p = a[0].cont;
	while (p && !encontro) {
		ins_pila (pila, p);
		i = 0;
		while (x > a[p].info [i] && i < a[p].cont - 1)
			i++;
		if (x < a[p].info [i])
			if (a[p].tipo == INTERNA)
				p = a[p].apunt [i];
			else p = 0;
		else if (x > a[p].info [i])
			if (a[p].tipo == INTERNA)
				p = a[p].apunt [i+1];
			else p = 0;
		else if (a[p].tipo == INTERNA)
			p = a[p].apunt [i + 1];
		     else encontro = 1;
	}
	if (!encontro)
		*posicion = i;
	else return (a[p].apunt [i]);
}

insertar (CURSOR a[],int p,int x,int *i,int tipo)
{
	int j;

	if (a[p].cont)
		if (x > a[p].info [*i])
			(*i)++;
		else {
			j = a[p].cont - 1;
			while (j >= *i) {
				a[p].info [j+1] = a[p].info [j];
				if (tipo == EXTERNA)
					a[p].apunt [j+1] = a[p].apunt [j];
				j--;
			}
		}
	a[p].cont++;
	a[p].info [*i] = x;
}

donde (CURSOR a[],int p, int x)
{
	int i;

	i= 0;
	while (x > a[p].info [i] && i < a[p].cont - 1)
		i++;
	return (i);
}

romper  (CURSOR a[],int p,int t,int *q,int x,int *subir, int separar)
{
	int aa [M1], i=0 ,j, s = 0;
	int b[M1+1],temp;

	if (separar == 0) {
		temp = a[p].apunt [M];
		a[p].apunt [M] = 0;
	}
	while (i < M && !s)
		if (a[p].info[i] < x) {
			aa[i] =a[p].info [i];
			b[i] = a[p].apunt [i];
			a[p].apunt [i++] = 0;
		}
		else s = 1;

	if (separar == 1) {
		aa[i] = x;
		b[i] = a[p].apunt [i];
		a[p].apunt [i] = 0;
		b[++i] = t;
		while (i <= M) {
			aa[i] =a[p].info [i-1];
			b[i+1] = a[p].apunt [i];
			a[p].apunt [i++] = 0;
		}
	}
	else {
		aa[i] = x;
		b[i++] = t;
		while (i <= M) {
			aa[i] =a[p].info [i-1];
			b[i] = a[p].apunt [i-1];
			a[p].apunt [i-1] = 0;
			i++;
		}
	}
	*q = disp (a);
	if (*q == -1) {
		printf ("Cursor lleno...");
		getch();
		exit(1);
	}
	inicializar (a, *q);
	i = 0;
	if (separar == 0) {
		a[p].cont = N;
		a[*q].cont = N + 1;
		a[*q].info [0] = aa[N];
		a[*q].apunt [0] = b [N];
		while (i < N) {
			a[p].info [i] = aa[i];
			a[p].apunt [i] = b [i];
			a[*q].info [i+1] = aa[i+N+1];
			a[*q].apunt [i+1] = b[i+N+1];
			i++;
		}
		a[*q].apunt [M] = temp;
		a[p].apunt [M] = *q;
		a[*q].tipo = EXTERNA;
	}
	else {
		a[p].cont = a[*q].cont = N;
		while (i < N) {
			a[p].info [i] = aa[i];
			a[p].apunt [i] = b [i];
			a[*q].info [i] = aa[i+N+1];
			a[*q].apunt [i] = b[i+N+1];
			i++;
		}
		a[p].apunt [N] = b [N];
		a[*q].apunt [N] = b [M1];
		a[*q].tipo = INTERNA;
	}
	*subir = aa [N];
}

cderecha_apunt (CURSOR a[],int p,int i)
{
	int j;

	j = a[p].cont;
	while (j > i) {
		a[p].apunt [j] = a[p].apunt [j - 1];
		j--;
	}
}


listar_b (CURSOR a[],REG datos)
{
	int i,p;
	LIFO1 pila;

	p = a[0].cont;
	init1_pila (&pila);
	while (p) {
		ins1_pila (&pila,p,0);
		if (a[p].tipo == INTERNA)
			p = a[p].apunt [0];
		else p = 0;
	}
	while (!pila1_vacia (&pila) ) {
		retira1_pila (&pila,&p,&i);
		if (i < a[p].cont) {
			printf ("%d",a[p].info [i]);
			if (a[p].tipo == 0)
				printf ("I ");
			else printf ("E ");
			ins1_pila (&pila,p,i+1);
			if (a[p].tipo == EXTERNA)
				p = 0;
			else p = a[p].apunt [i+1];
			while (p) {
				ins1_pila (&pila,p,0);
				if (a[p].tipo == INTERNA)
					p = a[p].apunt [0];
				else p = 0;
			}
		}
	}
}


ins_bmas (CURSOR a[],REG datos[],int x,int *s, REG registro)
{
	int posicion,i,j,subir,subir1,terminar,separar;
	int p,q,nuevo,nuevo1;
	LIFO pila;

	init_pila (&pila);
	*s = 0;
	if (a[0].cont == 0) {
	   q = crear_reg (datos,registro);
	   a[0].cont = crear_pagina (a, x);
	   a[ a[0].cont ].apunt [0] = q;
	   a[0].info [0] = a[0].cont;	/* Inicializa VSAM */
	   a[ a[0].cont ].tipo = EXTERNA;
	}
	else {
		buscar (a, x, &posicion, &pila);
		if (posicion == -1)
		   *s = 1;              /* La llave esta en el arbol */
		else {
			terminar = separar = 0;
			while (!pila_vacia (&pila) && terminar == 0) {
			  retira_pila (&pila, &p);
			  if (a[p].cont == M) {
			     if (separar == 0) {
				q = crear_reg (datos,registro);
				romper (a, p, q, &nuevo, x, &subir,separar);
				separar = 1;
			     }
			     else {
				     romper (a,p,nuevo,&nuevo1,
					subir,&subir1,separar);
				     subir = subir1;
				     nuevo = nuevo1;
			     }
			  }
			  else {
				  if (separar == 1) {
				     separar = 0;
				     i = donde (a, p, subir);
				     insertar (a, p, subir, &i,INTERNA);
				     cderecha_apunt (a, p, i+1);
				     a[p].apunt [i+1] = nuevo;
				  }
				  else {
					insertar (a, p, x,&posicion,EXTERNA);
					q = crear_reg (datos,registro);
					a[p].apunt [posicion] = q;
				  }
				  terminar = 1;
			  }
			}
			if (separar == 1 && terminar == 0) {
				a[0].cont = crear_pagina (a, subir);
				a[ a[0].cont  ].tipo = INTERNA;
				a[ a[0].cont ].apunt [0] = p;
				a[ a[0].cont ].apunt [1] = nuevo;
			}
		}
	}
}

lea()
{
	char a[10];

	gets (a);
	return (atoi (a) );
}


retirar (CURSOR a[],int p,int i)
{
	while (i < a[p].cont - 1) {
		a[p].info [i] = a[p].info [i+1];
		if (a[p].tipo == EXTERNA)
			a[p].apunt [i] = a[p].apunt [i+1];
		i++;
	}
	a[p].cont--;
}

cambio (CURSOR a[],int p,int q,int r,int i,int x)
{
	int k,t;

	if (x > a[r].info [a[r].cont - 1]) {
		t = a[q].info [i];
		retirar (a,q,i);
		k = 0;
		insertar (a,p,t,&k,INTERNA);
		t = a[r].info [a[r].cont - 1];
		retirar (a,r, a[r].cont - 1);
		k = i;
		if (k == -1)
			k = 0;
		insertar (a,q,t,&k,INTERNA);
	}
	else {
		t = a[q].info [i];
		retirar (a,q, i);
		k = a[p].cont - 1;
		if (k == -1)
			k = 0;
		insertar (a,p,t,&k,INTERNA);
		t = a[r].info [0];
		retirar (a,r, 0);
		k = i;
		if (a[q].cont != 0)
			if (k > a[q].cont - 1)
				k = a[q].cont -1;
		insertar (a,q,t,&k,INTERNA);
	}
}

cizquierda_apunt (CURSOR a[],int p,int i,int j)
{
	while (i < j) {
		a[p].apunt [i] = a[p].apunt [i+1];
		i++;
	}
	a[p].apunt [i] = 0;
}

esta (CURSOR a[],int p, int x, int *posicion, LIFO1 *pila)
{
	int i = 0,encontro = 0;

	*posicion = -1;
	while (p != 0 && !encontro) {
		i = 0;
		while (x > a[p].info [i] && i < a[p].cont - 1)
			i++;
		if (x < a[p].info [i]) {
			ins1_pila (pila, p, i);
			if (a[p].tipo == INTERNA)
				p = a[p].apunt [i];
			else p = 0;
		}
		else if (x > a[p].info [i]) {
			ins1_pila (pila, p, i+1);
			if (a[p].tipo == INTERNA)
				p = a[p].apunt [i+1];
			else p = 0;
		}
		else {
			if (a[p].tipo == INTERNA) {
				ins1_pila (pila, p, i+1);
				p = a[p].apunt [i+1];
			}
			else {
				ins1_pila (pila,p,i);
				encontro = 1;
			}
		}
	}
	if (encontro == 1)
		*posicion = i;
}

unir (CURSOR a[],REG b[],int *raiz,int q, int r,
	int p, int i, LIFO1 pila, int  x, int posicion)
{
	int terminar = 0,j, k,t;

	libera_reg (b,a[p].apunt [posicion]);
	retirar (a, p, posicion);
	if (x < a[r].info [0]) {
		t = p;
		p = r;
		r = t;
	}
	while (terminar == 0) {
	  if (a[r].cont < N && a[p].cont > N) {	/* CASO 7 */
		cambio (a, r, q, p, i, x);
		a[r].apunt [a[r].cont] = a[p].apunt [0];
		cizquierda_apunt (a, p, 0, a[p].cont + 1);
		terminar = 1;
	  }
	  else if (a[p].cont < N && a[r].cont > N) {   /* CASO 6  */
			cambio (a, p, q, r, i, x);
			cderecha_apunt (a, p, 0);
			a[p].apunt [0] = a[r].apunt [a[r].cont + 1];
			a[r].apunt [a[r].cont + 1] = 0;
			terminar = 1;
	  }
	  else {
		  j = a[r].cont;
		  if (a[r].tipo == EXTERNA)	/* Si es el ultimo nivel */
			a[r].apunt [M] = a[p].apunt [M];
		  else a[r].info [j++] = a[q].info [i];
		  k = 0;
		  while (k <= a[p].cont - 1) {
			a[r].info [j] = a[p].info [k];
			if (a[r].tipo == EXTERNA)
				a[r].apunt [j] = a[p].apunt [k];
			j++;
			k++;
		  }
		  a[r].cont = j;
		  retirar (a, q, i);
		  if (a[r].tipo == INTERNA) {
			k = 0;
			j = M - a[p].cont;
			while (a[p].apunt [k] != 0)
				a[r].apunt [j++] = a[p].apunt [k++];
		  }
		  liberar (a, p);
		  if (a[q].cont == 0) {
			a[q].apunt [i+1] = 0;
			if (pila1_vacia (&pila) ) {
				liberar (a, q);
				q = 0;
			}
		  }
		  else cizquierda_apunt (a, q, i+1, a[q].cont+1);
		  if (q != 0)
			if (a[q].cont >= N)
				terminar = 1;
			else {
				t = q;
				if (!pila1_vacia (&pila) ) {
					retira1_pila (&pila, &q, &i);
					if (x >= a[q].info [0]) {
						p = t;
						r = a[q].apunt [i-1];
						i--;
					}
					else {
						r = t;
						p = a[q].apunt [i+1];
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

liberar (CURSOR a[], int p)
{
	a[p].apunt [M1-1] = a[0].apunt [M1-1];
	a[0].apunt [M1-1] = p;
}

libera_reg (REG a[], int p)
{
	a[p].cod = a[0].cod;
	a[0].cod = p;
}

retira_b (CURSOR a[], REG b[], int *raiz, int *VSAM, int x, int *s)
{
	int posicion, i, k, p, q, r, t, temp,temp1;
	LIFO1 pila;

	*s = 1;
	init1_pila (&pila);
	esta (a, *raiz, x, &posicion, &pila);
	if (posicion == -1) {
		*s = 0;   /* La llave no existe en el arbol  */
		return (0);
	}
	retira1_pila (&pila, &p, &i);
	if (a[p].cont > N) {
		libera_reg (b,a[p].apunt [posicion]);
		retirar (a, p, posicion);
		return (1);
	}
	if (pila1_vacia (&pila) ) {
        	libera_reg (b,a[p].apunt [posicion]);
		retirar (a, p, posicion);
		if (a[p].cont == 0) {
			liberar (a, *raiz);
			*raiz = *VSAM = 0;
		}
		return (1);
	}
	retira1_pila (&pila, &q, &i);
	if (i < a[q].cont) {
		r = a[q].apunt [i+1];
		if (a[r].cont > N) {
                	libera_reg (b,a[p].apunt [posicion]);
			retirar (a, p, posicion);
			temp = a[r].info [0];
			temp1= a[r].apunt [0];
			retirar (a,r,0);
			retirar (a,q,i);
			k = donde (a,p,temp);
			insertar (a,p,temp,&k,EXTERNA);
			a[p].apunt [k] = temp1;
			k = donde (a,q,a[r].info [0]);
			insertar (a,q,a[r].info[0], &k,INTERNA);
			return (1);
		}
	}
	if (i >0) {
		r = a[q].apunt [i-1];
		if (a[r].cont > N) {
                	libera_reg (b,a[p].apunt [posicion]);
			retirar (a, p, posicion);
			temp = a[r].info [  a[r].cont -1 ];
			temp1 = a[r].apunt [ a[r].cont -1  ];
			retirar (a,r,a[r].cont -1);
			retirar (a,q,i-1);
			k = donde (a,p,temp);
			insertar (a,p,temp,&k,EXTERNA);
			a[p].apunt [k] = temp1;
			k = donde (a,q,temp);
			insertar (a,q,temp, &k,INTERNA);
			return (1);
		}
	}
	if (i > 0)
		i--;
	unir (a,b,raiz,q,r,p,i,pila,x,posicion);
}

init_pila (LIFO *p)
{
	p->t = 0;
}

pila_vacia (LIFO *p)
{
	return (p->t == 0);
}

ins_pila (LIFO *p,int s)
{
	if (p->t == MAX) {
		printf ("Pila llena...");
		getch();
		exit (1);
	}
	else {
		p->a [p->t] = s;
		p->t++;
	}
}

retira_pila (LIFO *p, int *s)
{
	if (pila_vacia (p) ) {
		printf ("pila vacia...");
		getch();
		exit (1);
	}
	else {
		p->t--;
		*s = p->a [p->t];
	}
}


init1_pila (LIFO1 *p)
{
	p->t = 0;
}

pila1_vacia (LIFO1 *p)
{
	return (p->t == 0);
}

ins1_pila (LIFO1 *p,int s,int q)
{
	if (p->t == MAX) {
		printf ("PILA LLENA...");
		getch();
		exit (1);
	}
	else {
		p->a [p->t].direccion = s;
		p->a [p->t].d = q;
		p->t++;
	}
}

retira1_pila (LIFO1 *p, int *s, int *q)
{
	if (pila1_vacia (p) ) {
		printf ("pila vacia...");
		getch();
		exit (1);
	}
	else {
		p->t--;
		*s = p->a [p->t].direccion;
		*q = p->a [p->t].d;
	}
}

listar2(CURSOR a[])
{
	int i=0,j,k=0;
	FILE *p,*fopen();

	p = fopen ("CON","w");
	fprintf (p,"\n");
	fprintf (p,"posrel  cont  l l a v e s   apuntadores \n");
	for (;i<MAXIMO;i++) {
		fprintf (p,"%d %2d     %2d   ",a[i].tipo,k++,a[i].cont);
		for (j=0; j<M; j++)
			fprintf (p,"%2d ",a[i].info[j]);
		fprintf (p," ");
		for (j=0; j<M1; j++)
			fprintf (p,"%2d ",a[i].apunt [j]);
		fprintf (p,"\n");
	}
	fclose (p);
}

listar_VSAM (CURSOR a[], REG b[]) {
	int i,p,j;

	p = a[0].info [0];
	while (p != 0) {
		i=0;
		while (i < a[p].cont) {
			j = a[p].apunt [i];
			printf ("%d %s\n",b[j].cod,b[j].nombre);
			i++;
		}
		p = a[p].apunt [M];
	}
	printf ("\n");
}