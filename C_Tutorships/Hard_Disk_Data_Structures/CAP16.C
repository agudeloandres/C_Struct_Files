


/* Este programa maneja un archivo indexado */
/* No tiene funcion main()  */
/* Se ejecuta desde el programa mindex.c */



#include "stdio.h"
#include "io.h"
#include "fcntl.h"
#include "stdlib.h"
#define MAXIMO 50 /* Cada vez que se llene el archivo,
			se amplia automaticamente en MAXIMO registros */
#define P(x) printf ("%s\n",x)
#define LON sizeof (BUFFER)
#define grabar(id,a)  _write (id,(char *)&a,LON)
#define leer(id,a)  _read (id,(char *)&a,LON)
#define ubicar(id,a)  lseek (id,(long)a * LON, SEEK_SET);
#define LOND sizeof (BUFFERD)
#define grabard(id,a)  _write (id,(char *)&a,LOND)
#define leerd(id,a)  _read (id,(char *)&a,LOND)
#define ubicard(id,a)  lseek (id,(long)a * LOND, SEEK_SET);
#define N 2 /* Orden del arbol B */
#define M N*2
#define M1 M+1
#define MAX 10 /* Tamano de las pilas que utiliza el proceso */
#define MAXID  MAXIMO * M

typedef struct LIFO LIFO;
typedef struct LIFO1 LIFO1;
typedef struct z BUFFER;
typedef struct registro BUFFERD;

struct LIFO {
	int t;
	int a[MAX];
};


struct datos {
	int direccion;
	int d;
};


struct LIFO1 {
	int t;
	struct datos a[MAX];
};



struct z {
	int cont;
	int info [M];
	int posrel [M];
	int apunt [M1];
};

struct registro {
	int cod;
	char n [30];
	float sueldo;
};

capturar()
{
	int s,n,raiz,id,idd,posd;
	BUFFERD emple;
	char linea [10];

	id = _open ("arbolb",O_RDWR);
	idd = _open ("datos",O_RDWR);
	printf ("\nDe llave. 9999 para terminar.\n");
	n = lea ();
	while (n != 9999)  {
		ins_b (id,idd, n, &s,&posd);
		if (s == 1)
			printf ("La llave ya existe\n");
		else {
			emple.cod = n;
			printf("De nombre\n");
			gets (emple.n);
			printf ("De sueldo\n");
			gets (linea);
			emple.sueldo = (float) atof (linea);
			ubicard (idd, posd);
			grabard (idd,emple);
		}
		printf ("De llave. 9999 para terminar.\n");
		n = lea();
	}
	close (id);
	close (idd);
}

retirar1()
{
	BUFFER r0;
	int id,idd,n,s;

	id = _open ("arbolb",O_RDWR);
	idd = _open ("datos",O_RDWR);
	printf ("\nRetiros\n");
	printf ("De llave a retirar. 9999 para terminar.\n");
	n = lea();
	while (n != 9999)  {
		retira_b (id,idd, n, &s);
		if (s == 0)
			printf ("La llave no existe\n");
		printf ("De llave a retirar. 9999 para terminar.\n");
		n = lea();
	}
	close (id);
	close (idd);
}

inorden ()
{
	int id,idd;

	id = _open ("arbolb",O_RDONLY);
	idd = _open ("datos",O_RDONLY);
	listar_b (id,idd);
	close (id);
	close (idd);
}

consul1()
{
	int n,id,idd,x,posicion,p,i;
	LIFO1 pila;
	BUFFER pc;
	BUFFERD em;

	id = _open ("arbolb",O_RDONLY);
	idd = _open ("datos",O_RDONLY);
	printf ("\nConsultas\n");
	printf ("De llave a consultar. 9999 para terminar.\n");
	n = lea();
	while (n != 9999)  {
		init1_pila (&pila);
		esta (id,n,&posicion,&pila);
		if (posicion == -1)
			printf ("La llave no existe en el archivo\n");
		else {
			retira1_pila (&pila,&p,&i);
			ubicar (id,p);
			leer (id,pc);
			ubicard (idd,pc.posrel [posicion] );
			leerd (idd,em);
			printf ("\n");
			printf ("%d %s %10.2f\n",em.cod,em.n,em.sueldo);
		}
		printf ("De llave a consultar. 9999 para terminar.\n");
		n = lea();
	}
	close (id);
	close (idd);
}



listar2 (int id) /* Se usa para pruebas. Lista todo el archivo ARBOLB */
{
	BUFFER a;
	int i,j=0;
	FILE *p;

	p = fopen ("CON","w");
	fprintf (p,"\n");
	ubicar (id,0);
	while (_read (id,(char *)&a,LON)  ){
		fprintf (p,"%2d      %2d ",j++,a.cont);
		for (i=0; i < M; i++)
			fprintf (p,"%3d:%2d ",a.info [i],a.posrel [i]);
		fprintf (p,"       ");
		for (i=0; i < M1; i++)
			fprintf (p,"%3d ",a.apunt [i]);
		fprintf (p,"\n");
	}
	fprintf (p,"\n");
	fclose (p);
	printf ("Oprima una tecla");
	getch();
}

listar3 (int id) /* Se usa para pruebas. Lista todo el archivo DATOS */
{
	BUFFERD a;
	int j=0;
	FILE *p;

	p = fopen ("CON","w");
	ubicard (id,0);
	fprintf (p,"\n");
	while (_read (id,(char *)&a,LOND)) {
	   fprintf (p,"%3d %3d %-30s %10.2f",j++,a.cod,a.n,a.sueldo);
	   fprintf (p,"\n");
	}
	fprintf (p,"\n");
	fclose (p);
	printf ("Oprima una tecla");
	getch();
}




init_archivo ()
{
	int i,j,id,idd;
	BUFFER a;
	BUFFERD b;

	id = _creat ("arbolb",32);
	idd = _creat ("datos",32);
	a.cont = 0;
	for (j=0; j < M; j++)
		a.info [j] = a.posrel [j] = 0;
	for (j=0; j < M1; j++)
		a.apunt [j] = 0;
	strcpy (b.n,"          ");
	b.sueldo = 0.0;
	for (i=0; i < MAXIMO; i++) {
		a.apunt [M1-1] = i + 1;
		grabar (id,a);
	}
	a.apunt [M1-1] = 0;
	grabar (id,a);
	for (i=0; i < MAXID; i++) {
		b.cod = i + 1;
		grabard (idd,b);
	}
	b.cod = 0;
	grabard (idd,b);
	close (id);
	close (idd);
}

inicializar (BUFFER *a)
{
	int i,j;

	a->cont = 0;
	for (j=0; j < M; j++)
		a->info [j] = a->posrel [j] = 0;
	for (j=0; j < M1; j++)
		a->apunt [j] = 0;
}

crear_pagina (int id,int idd,int x,int *q,BUFFER *a,BUFFER *r0,BUFFERD *rd)
{
	int p;

	p = disp (id,r0);
	if (p == -1) {
		printf ("Indice lleno...");
		getch();
		exit (1);
	}
	if (*q == -2) {
		*q = dispd (idd,rd);
		if (*q == -1) {
			printf ("Archivo de datos lleno...");
			getch();
			exit (1);
		}
	}
	inicializar (a);
	a->cont = 1;
	a->info [0] = x;
	a->posrel [0] = *q;
	return (p);
}

disp (int id,BUFFER *r0)
{
	BUFFER r1;
	BUFFER a;
	long ii;
	int i = r0->apunt [M1-1],j;

	if (i==0) {
		ii = lseek (id,(long)0,SEEK_END);
		ii = ii / LON;
		a.cont = 0;
		for (j=0; j < M; j++)
			a.info [j] = a.posrel [j] = 0;
		for (j=0; j < M1; j++)
			a.apunt [j] = 0;
		for (i=ii; i < MAXIMO + ii; i++) {
			a.apunt [M1-1] = i+1;
			grabar (id,a);
		}
	        a.apunt [M1-1] = 0;
	        grabar (id,a);
                r0->apunt [M1-1] = ii + 1;
                return (ii);
        }
        else {
             ubicar (id,i);
	     leer (id,r1);
	     r0->apunt [M1-1] = r1.apunt [M1-1];
	     return (i);
        }
}

dispd (int id,BUFFERD *r0)
{
	BUFFERD r1,b;
	int i = r0->cod;
	long ii;

	if (i==0) {
		ii = lseek (id,(long)0,SEEK_END);
		ii = ii / LOND;
		strcpy (b.n,"          ");
		b.sueldo = 0.0;
		for (i=ii; i < MAXID + ii; i++) {
			b.cod = i + 1;
			grabard (id,b);
		}
		b.cod = 0;
		grabard (id,b);
		r0->cod = ii + 1;
		return (ii);
	}
	else {
		ubicard (id,i);
		leerd (id,r1);
		r0->cod = r1.cod;
		return (i);
	}
}

buscar (int id,int x,int *posicion,LIFO *pila)
{
	int i,encontro = 0,p;
	BUFFER r0,pc;

	*posicion = -1;
	ubicar (id,0);
	leer (id,r0);
	p = r0.cont;
	while (p && !encontro) {
		ins_pila (pila, p);
		i = 0;
		ubicar (id,p);
		leer (id,pc);
		while (x > pc.info [i] && i < pc.cont - 1)
			i++;
		if (x < pc.info [i])
			p = pc.apunt [i];
		else if (x > pc.info [i])
			p = pc.apunt [i+1];
		else encontro = 1;
	}
	if (!encontro)
		*posicion = i;
}

insertar (BUFFER *p,int x,int pos,int *i)
{
	int j;

	if (p->cont)
		if (x > p->info [*i])
			(*i)++;
		else {
			j = p->cont - 1;
			while (j >= *i) {
				p->info [j+1] = p->info [j];
				p->posrel [j+1] = p->posrel [j];
				j--;
			}
		}
	p->cont++;
	p->info [*i] = x;
	p->posrel [*i] = pos;
}

donde (BUFFER pc, int x)
{
	int i;

	i= 0;
	while (x > pc.info [i] && i < pc.cont - 1)
		i++;
	return (i);
}

romper (int id,BUFFER *pc,int t,int *q,BUFFER *qc,int x,
		int posd,int *subir,int *poss,BUFFER *r0)
{
	int aa [M1], aa1 [M1], i=0 ,j, s = 0;
	int b[M1+1];

	while (i < M && !s)
		if (pc->info[i] < x) {
			aa[i] = pc->info [i];
			aa1 [i] = pc->posrel [i];
			b[i] = pc->apunt [i];
			pc->apunt [i++] = 0;
		}
		else s = 1;
	aa[i] = x;
	aa1 [i] = posd;
	b[i] = pc->apunt [i];
	pc->apunt [i] = 0;
	b[++i] = t;
	while (i <= M) {
		aa[i] =pc->info [i-1];
		aa1 [i] = pc->posrel [i-1];
		b[i+1] = pc->apunt [i];
		pc->apunt [i++] = 0;
	}
	*q = disp (id,r0);
	if (*q == -1) {
		printf ("Indice lleno...");
		getch();
		exit(1);
	}
	inicializar (qc);
	pc->cont = qc->cont = N;
	i = 0;
	while (i < N) {
		pc->info [i] = aa[i];
		pc->posrel [i] = aa1[i];
		pc->apunt [i] = b [i];
		qc->info [i] = aa [i+N+1];
		qc->posrel [i] = aa1 [i+N+1];
		qc->apunt [i] = b[i+N+1];
		i++;
	}
	pc->apunt [N] = b [N];
	qc->apunt [N] = b [M1];
	*subir = aa [N];
	*poss = aa1 [N];
}

cderecha_apunt (BUFFER *p,int i)
{
	int j;

	j = p->cont;
	while (j > i) {
		p->apunt [j] = p->apunt [j - 1];
		j--;
	}
}

listar_b (int id,int idd)
{
	int i,p;
	LIFO1 pila;
	BUFFER pc;
	BUFFERD b;

	printf ("\n");
	ubicar (id,0);
	leer (id,pc);
	p = pc.cont;
	init1_pila (&pila);
	while (p) {
		ubicar (id,p);
		leer (id,pc);
		ins1_pila (&pila,p,0);
		p = pc.apunt [0];
	}
	while (!pila1_vacia (&pila) ) {
		retira1_pila (&pila,&p,&i);
		ubicar (id,p);
		leer (id,pc);
		if (i < pc.cont) {
			ubicard (idd,pc.posrel [i]);
			leerd (idd,b);
			printf ("%d %s %10.2f\n",b.cod,b.n,b.sueldo);
			ins1_pila (&pila,p,i+1);
			p = pc.apunt [i+1];
                	while (p) {
				ubicar (id,p);
				leer (id,pc);
				ins1_pila (&pila,p,0);
				p = pc.apunt [0];
			}
		}
	}
}

/*
listar1_b (int id, int p, int lon)
{
	int i;

	if (p) {
		for (i = 0; i < lon; i++)
			printf ("  ");
		for (i = 0; i < pc.cont; i++)
			printf ("%4d",pc.info [i]);
		printf ("\n");
		listar1_b (id,pc.apunt [0],lon+1);
		for (i=1; i <= pc.cont; i++)
			listar1_b (id,pc.apunt [i], lon+1);
	}
}
*/


ins_b (int id,int idd, int x,int *s,int *posd)
{
	int posicion,i,j,subir,subir1,terminar,separar,poss,poss1;
	int p,nuevo,nuevo1,nograbar = 1;
	LIFO pila;
	BUFFER r0,pc,nuevoc,nuevo1c;
	BUFFERD rd;

	init_pila (&pila);
	*s = 0;
	ubicar (id,0);
	leer (id,r0);
	ubicard (idd,0);
	leerd (idd,rd);
	if (r0.cont == 0) {
	   *posd = -2;
	   i = crear_pagina (id,idd,x,posd,&nuevoc,&r0,&rd);
	   r0.cont = i;
	   ubicar (id,i);
	   grabar (id,nuevoc);
	   ubicar (id,0);
	   grabar (id,r0);
	   ubicard (idd,0);
	   grabard (idd,rd);
	}
	else {
		buscar (id, x, &posicion, &pila);
		if (posicion == -1)
		   *s = 1;              /* La llave esta en el arbol */
		else {
			*posd = dispd (idd,&rd);
			if (*posd == -1) {
				printf ("Archivo de datos lleno...");
				getch();
				exit (1);
			}
			terminar = separar = 0;
			ubicard (idd,0);
			grabard (idd,rd);
			while (!pila_vacia (&pila) && terminar == 0) {
			  retira_pila (&pila, &p);
			  ubicar (id,p);
			  leer (id,pc);
			  if (pc.cont == M) {
			     if (separar == 0) {
				romper (id,&pc,0,&nuevo,&nuevoc,x,*posd,
						&subir,&poss,&r0);
				ubicar (id,p);
				grabar (id,pc);
				ubicar (id,nuevo);
				grabar (id,nuevoc);
				separar = 1;
			     }
			     else {
				     romper (id,&pc,nuevo,
					&nuevo1,&nuevo1c,subir,poss,&subir1,
						&poss1,&r0);
				     ubicar (id,p);
				     grabar (id,pc);
				     ubicar (id,nuevo1);
				     grabar (id,nuevo1c);
				     subir = subir1;
				     nuevo = nuevo1;
				     poss = poss1;
				     copie (&nuevoc, nuevo1c);
			     }
			  }
			  else {
				  if (separar == 1) {
				     separar = 0;
				     i = donde (pc, subir);
				     insertar (&pc, subir, poss, &i);
				     cderecha_apunt (&pc, i+1);
				     pc.apunt [i+1] = nuevo;
				     ubicar (id,nuevo);
				     grabar (id,nuevoc);
				  }
				  else {
					insertar (&pc, x, *posd, &posicion);
					nograbar = 0;
				  }
				  ubicar (id,p);
				  grabar (id,pc);
				  terminar = 1;
			  }
			}
			if (separar == 1 && terminar == 0) {
				i = crear_pagina (id,idd,subir,&poss,
					&pc,&r0,&rd);
				r0.cont = i;
				pc.apunt [0] = p;
				pc.apunt [1] = nuevo;
				ubicar (id,i);
				grabar (id,pc);
			}
			if (nograbar == 1) {
				ubicar (id,0);
				grabar (id,r0);
			}
		}
	}
}

copie (BUFFER *a, BUFFER b)
{
	int i;

	a->cont = b.cont;
	for (i = 0; i < M; i++) {
		a->info [i] = b.info [i];
		a->posrel [i] = b.posrel [i];
	}
	for (i = 0; i < M1; i++)
		a->apunt [i] = b.apunt [i];
}




lea()
{
	char a[10];

	gets (a);
	return (atoi (a) );
}

retirar (BUFFER *p,int i)
{
	while (i < p->cont - 1) {
		p->info [i] = p->info [i+1];
		p->posrel [i] = p->posrel [i+1];
		i++;
	}
	p->cont--;
}

cambio (BUFFER *p,BUFFER *q,BUFFER *r,int i,int x)
{
	int k,t,t1;

	if (x > r->info [r->cont - 1]) {
		t = q->info [i];
		t1 = q->posrel [i];
		retirar (q,i);
		k = 0;
		insertar (p,t,t1,&k);
		t = r->info [r->cont - 1];
		t1 = r->posrel [r->cont - 1];
		retirar (r, r->cont - 1);
		k = i;
		if (k == -1)
			k = 0;
		insertar (q,t,t1,&k);
	}
	else {
		t = q->info [i];
		t1 = q->posrel [i];
		retirar (q, i);
		k = p->cont - 1;
		if (k == -1)
			k = 0;
		insertar (p,t,t1,&k);
		t = r->info [0];
		t1 = r->posrel [0];
		retirar (r, 0);
		k = i;
		if (q->cont != 0)
			if (k > q->cont - 1)
				k = q->cont -1;
		insertar (q,t,t1,&k);
	}
}

hoja (BUFFER pc)
{
	int j = 0;

	while (pc.apunt [j] == 0 && j < pc.cont - 1)
		j++;
	return (pc.apunt [j] == 0);
}

cizquierda_apunt (BUFFER *p,int i,int j)
{
	while (i < j) {
		p->apunt [i] = p->apunt [i+1];
		i++;
	}
	p->apunt [i] = 0;
}

esta (int id,int x, int *posicion, LIFO1 *pila)
{
	int i = 0,encontro = 0,p;
	BUFFER pc;

	ubicar (id,0);
	leer (id,pc);
	p = pc.cont;
	*posicion = -1;
	while (p != 0 && !encontro) {
		ubicar (id,p);
		leer (id,pc);
		i = 0;
		while (x > pc.info [i] && i < pc.cont - 1)
			i++;
		if (x < pc.info [i]) {
			ins1_pila (pila, p, i);
			p = pc.apunt [i];
		}
		else if (x > pc.info [i]) {
			ins1_pila (pila, p, i+1);
			p = pc.apunt [i+1];
		}
		else {
			ins1_pila (pila, p, i);
			encontro = 1;
		}
	}
	if (encontro == 1)
		*posicion = i;
}

unir (int id,int q,int r,int p,BUFFER *qc, BUFFER *rc,BUFFER *pc,
	int i, LIFO1 pila, int  x, int posicion,BUFFER *r0)
{
	int terminar = 0,j, k,t;
	BUFFER tc;

	retirar (pc, posicion);
	if (x < rc->info [0]) {
		t = p;
		p = r;
		r = t;
		copie (&tc,*pc);
		copie (pc,*rc);
		copie (rc,tc);
	}
	while (terminar == 0) {
	  if (rc->cont < N && pc->cont > N) {
		cambio (rc, qc, pc, i, x);
		rc->apunt [rc->cont] = pc->apunt [0];
		cizquierda_apunt (pc, 0, pc->cont + 1);
		escribir (id,p,*pc,q,*qc,r,*rc);
		terminar = 1;
	  }
	  else if (pc->cont < N && rc->cont > N) {
			cambio (pc, qc, rc, i, x);
			cderecha_apunt (pc, 0);
			pc->apunt [0] = rc->apunt [rc->cont + 1];
			rc->apunt [rc->cont + 1] = 0;
			escribir (id,p,*pc,q,*qc,r,*rc);
			terminar = 1;
	  }
	  else {
		  j = rc->cont;
		  rc->posrel [j] = qc->posrel [i];
		  rc->info [j++] = qc->info [i];
		  k = 0;
		  while (k <= pc->cont - 1) {
			rc->posrel [j] = pc->posrel [k];
			rc->info [j++] = pc->info [k++];
		  }
		  rc->cont = j;
		  retirar (qc, i);
		  k = 0;
		  j = M - pc->cont;
		  while (pc->apunt [k] != 0)
			rc->apunt [j++] = pc->apunt [k++];
		  liberar (id,r0,p,pc);
		  if (qc->cont == 0) {
			qc->apunt [i+1] = 0;
			if (pila1_vacia (&pila) ) {
				liberar (id,r0,q,qc);
				q = 0;
			}
		  }
		  else cizquierda_apunt (qc, i+1, qc->cont+1);
		  if (q != 0)
			if (qc->cont >= N) {
				ubicar (id,q);
				grabar (id, (*qc) );
				ubicar (id,r);
				grabar (id,(*rc));
				terminar = 1;
			}
			else {
				t = q;
				copie (&tc,*qc);
				if (!pila1_vacia (&pila) ) {
					retira1_pila (&pila, &q, &i);
					ubicar (id,q);
					leer (id,(*qc));
					if (x >= qc->info [0]) {
						p = t;
						copie (pc,tc);
						ubicar (id,r);
						grabar (id,(*rc));
						r = qc->apunt [i-1];
						ubicar (id,r);
						leer (id, (*rc) );
						i--;
					}
					else {
						ubicar (id,r);
						grabar (id,(*rc));
						r = t;
						copie (rc,tc);
						p = qc->apunt [i+1];
						ubicar (id,p);
						leer (id, (*pc) );
					}
				}
				else {
						ubicar (id,q);
						grabar (id,(*qc));
						ubicar (id,r);
						grabar (id,(*rc));
						terminar = 1;
				}
			}
		  else {
				ubicar (id,r);
				grabar (id,(*rc));
				terminar = 1;
				r0->cont = r;
		  }
	  }
	}
}

liberar (int id,BUFFER *r0, int p, BUFFER *pc)
{
	pc->apunt [M1-1] = r0->apunt [M1-1];
	r0->apunt [M1-1] = p;
	ubicar (id,p);
	grabar (id, (*pc) );
}

liberard (int idd,BUFFERD *r0, int p, BUFFERD *pc)
{
	pc->cod = r0->cod;
	r0->cod = p;
	ubicard (idd,p);
	grabard (idd, (*pc) );
}

retira_b (int id, int idd, int x, int *s)
{
	int posicion, i, k, p, q, r, t, tposrel;
	LIFO1 pila;
	BUFFER pc,r0,qc,rc,tc;
	BUFFERD rd,vacia;

	vacia.cod = 0;
	strcpy (vacia.n,"registro vacio");
	vacia.sueldo = 0;
	ubicar (id,0);
	leer (id,r0);
	*s = 1;
	init1_pila (&pila);
	esta (id, x, &posicion, &pila);
	if (posicion == -1)
		*s = 0;   /* La llave no existe en el arbol  */
	else {
		retira1_pila (&pila, &p, &i);
		ubicar (id,p);
		leer (id,pc);
		if (!hoja (pc)) {
			t = p;
			copie (&tc,pc);
			k = i;
			ins1_pila (&pila, p, i+1);
			p = pc.apunt [i+1];
			while ( p != 0) {
				ubicar (id,p);
				leer (id,pc);
				ins1_pila (&pila, p, 0);
				p = pc.apunt [0];
			}
			retira1_pila (&pila, &p, &i);
			tc.info [k] = pc.info [0];
			tposrel = tc.posrel [k];
			tc.posrel [k] = pc.posrel [0];
			x = pc.info [0];
			pc.posrel [0] = tposrel;
			posicion = 0;
			ubicar (id,t);
			grabar (id,tc);
		}
		ubicard (idd,0);
		leerd (idd,rd);
		liberard (idd,&rd,pc.posrel [posicion],&vacia);
		ubicard (idd,0);
		grabard(idd,rd);
		if (pc.cont > N) {
			retirar (&pc, posicion);
			ubicar (id,p);
			grabar (id,pc);
		}
		else {
			if (!pila1_vacia (&pila)) {
				retira1_pila (&pila, &q, &i);
				ubicar (id,q);
				leer (id,qc);
				if (i < qc.cont) {
					r = qc.apunt [i+1];
					ubicar (id,r);
					leer (id,rc);
					if (rc.cont > N) {
						retirar (&pc, posicion);
						cambio (&pc,&qc,&rc, i, x);
						escribir (id,p,pc,q,qc,r,rc);
					}
					else {
						if (i != 0) {
						   r = qc.apunt [i-1];
						   ubicar (id,r);
						   leer (id,rc);
						   if (rc.cont > N) {
						     retirar (&pc, posicion);
						     cambio(&pc,&qc,&rc,i-1,x);
						     escribir (id,p,pc,q,
								qc,r,rc);
						   }
						   else unir (id,q,r,p,&qc,&rc,
							&pc,i-1,pila,x,
							posicion,&r0);
						}
						else unir (id,q,r,p,&qc,&rc,
						    &pc,i,pila,x,posicion,&r0);
					}
				}
				else {
					r = qc.apunt [i-1];
					ubicar (id,r);
					leer (id,rc);
					if (rc.cont > N) {
						retirar (&pc, posicion);
						cambio (&pc,&qc,&rc,i-1,x);
						escribir (id,p,pc,q,qc,r,rc);
					}
					else unir (id,q,r,p,&qc,&rc,&pc,
						i-1,pila,x, posicion,&r0);
				}
			}
			else {
				retirar (&pc, posicion);
				if (pc.cont == 0) {
					liberar (id,&r0,p,&pc);
					r0.cont = 0;
				}
				else {
					ubicar (id,p);
					grabar (id,pc);
				}
			}
			ubicar (id,0);
			grabar (id,r0);
		}
	}
}

escribir (int id,int p,BUFFER pc,int q,BUFFER qc, int r, BUFFER rc)
{
	ubicar (id,p);
	grabar (id,pc);
	ubicar (id,q);
	grabar (id,qc);
	ubicar (id,r);
	grabar (id,rc);
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




