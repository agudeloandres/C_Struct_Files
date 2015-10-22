/* Este programa maneja un archivo indexado a traves de un B+ */
/* Se ejecuta desde el programa MCURB20.c */



#define N 2
#define M N*2
#define M1 M+1
#define MAX 10
#define INTERNA 0
#define EXTERNA 1
#define P(x)  printf ("%s\n",x)
#define LON_INDICE sizeof (REGISTRO)
#define LON_DATOS sizeof (REG)

#define ubicar(x,y) if(lseek (x,(long)y * LON_INDICE, SEEK_SET)==-1)\
 error("Error en lseek()")
#define grabar(x,y) if(_write (x,(char *)&y, LON_INDICE)!=LON_INDICE)\
 error("Error en _write()")
#define leer(x,y) if(_read (x,(char *)&y, LON_INDICE)==-1)\
 error("Error en _read()")

#define ubicard(x,y) if(lseek (x,(long)y * LON_DATOS, SEEK_SET)==-1)\
 error("Error en lseek()")
#define grabard(x,y) if(_write (x,(char *)&y, LON_DATOS)!=LON_DATOS)\
 error("Error en _write()")
#define leerd(x,y) if(_read (x,(char *)&y, LON_DATOS)== -1)\
 error("Error en _read()")

#define cerrar(x) if(_close (x) == -1) error("error en _close()")

typedef struct LIFO LIFO;
typedef struct LIFO1 LIFO1;
typedef struct z REGISTRO;
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

lea_reg (REG *);
crear_pagina (int,int,REGISTRO *,REGISTRO *);
disp (int,REGISTRO *);
crear_reg (int,REG ,REG *);
disp_reg (int,REG *);
buscar (int,int,int *,LIFO *);
insertar (REGISTRO *,int,int *,int);
donde (REGISTRO *, int);
romper  (int,REGISTRO *,int,int *,int,int *, int,REGISTRO *,REGISTRO *);
cderecha_apunt (REGISTRO *,int);
ins_bmas (int, int,int,int *, REG);
retirar (REGISTRO *,int);
cambio (REGISTRO *,REGISTRO *,REGISTRO *,int,int);
cizquierda_apunt (REGISTRO *,int,int);
esta (int, int, int, int *, LIFO1 *);
unir (int, int,REGISTRO,REG,int, int,
		int, REGISTRO,REGISTRO,REGISTRO,int, LIFO1, int, int);
liberar (int,int,REGISTRO *);
libera_reg (int, int,REG *);
grabar_registros (int, int,int, int,REGISTRO,REGISTRO, REGISTRO);
retira_b (int, int, int, int *);
init_pila (LIFO *);
pila_vacia (LIFO *);
ins_pila (LIFO *,int);
retira_pila (LIFO *, int *);
init1_pila (LIFO1 *);
pila1_vacia (LIFO1 *);
ins1_pila (LIFO1 *,int,int);
retira1_pila (LIFO1 *, int *, int *);
error(char *);



captu ()
{
	capturar();
}

consul ()
{
	consul1 ();
}
retira ()
{
	retirar1 ();
}

listar ()
{
	char c;
	printf ("v=vsam; x = listar2\n");
	c=getch();
	if (c == 'v') listar_VSAM();
	else listar2();
	printf ("\nOprima una tecla\n");
	getch();
}

inicia ()
{
	init_archivos();
}


consul1 ()
{
	int n,posicion,donde_esta,id,idd;
	REG b;
	LIFO pila;

	id = _open ("indice",O_RDONLY);
	idd = _open ("datos",O_RDONLY);
	P("De numero. <9999> para finalizar.");
	n = lea();
	while (n != 9999) {
		init_pila (&pila);
		donde_esta = buscar (id,n,&posicion,&pila);
		if (posicion == -1) {
			ubicard (idd,donde_esta);
			leerd (idd,b);
			printf ("%d %s\n",b.cod,b.nombre);
		}
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
	itoa (p->cod,a,10);
	strcpy (p->nombre,a);
}
	*/

lea_reg (REG *p) {
	char a[40];

	p->cod = rand();
	itoa (p->cod,a,10);
	strcpy (p->nombre,a);
}

capturar ()
{
	int s,n,raiz,i,id,idd;
	REG registro;


	id = _open ("indice",O_RDWR);
	idd = _open ("datos",O_RDWR);
	printf ("De registro de datos. 9999 para finalizar\n");
	lea_reg (&registro);
	i=1;
	n = registro.cod;
	while (i <= 100) {
		ins_bmas (id,idd, n, &s, registro);
		if (s == 1)
			printf ("\nLa llave ya existe\n");
		else printf ("%d ",n);
		lea_reg (&registro);
		n = registro.cod;
		i++;
	}
	cerrar(id);
	cerrar(idd);
	getch();
}

retirar1 ()
{
	int i,id,idd,n,raiz,s,VSAM;


	if((id = _open ("indice",O_RDWR)) == -1) error ("error en _open()");
	if((idd = _open ("datos",O_RDWR)) == -1) error ("error en _open()");
	printf ("De llave a retirar. 9999 para finalizar\n");
	n = rand();
	i=1;
	while (i<=99) {
		retira_b (id, idd, n, &s);
		if (s == 0)
			printf ("La llave no existe\n");
		printf ("De llave a retirar. 9999 para finalizar\n");
		n = rand();
		i++;
	}
	printf ("\n");
	cerrar (id);
	cerrar(idd);
	if ((id = _open ("indice",O_RDWR)) == -1) error ("error en _open()");
	listar_b (id);
	cerrar (id);
	printf ("\nOprima una tecla\n");
	getch();
}

init_archivos()
{
	int id,idd;
	REGISTRO b;
	REG b1;
	int i,j;

	if ((id = _creat("indice",FA_ARCH) ) == -1) error("error en _creat()");
	if ((idd = _creat("datos",FA_ARCH) ) == -1) error("error en _creat()");
	cerrar (id);
	cerrar (idd);
	id = _open ("indice",O_WRONLY);
	idd = _open ("datos",O_WRONLY);
	b.cont = b.tipo = 0;		/* Raiz del arbol */
	for (j=0; j < M; j++)   /* VSAM = registro 0, info [0]  */
		b.info [j] = 0;
	for (j=0; j < M1; j++)
		b.apunt [j] = 0;
	grabar (id,b);
	b1.cod = 0;
	strcpy (b1.nombre, "vacio");
	grabard (idd,b1);
	cerrar (id);
	cerrar (idd);
}

ampliar_indice (int id) {
	REGISTRO b,r0;
	int i,j;
	long n;

	ubicar (id,0);
	leer (id,r0);
	n = lseek (id,(long)0,SEEK_END);
	n = n / LON_INDICE;
	b.tipo = b.cont = 0;
	for (j=0; j < M; j++)
		b.info [j] = 0;
	for (j=0; j < M1; j++)
		b.apunt [j] = 0;
	for (i=(int)n; i < (int)n+20; i++) {
		b.apunt [M] = (int)i+1;
		grabar (id, b);
	}
	b.apunt [M] = 0;
	grabar (id,b);
	r0.apunt [M] = (int)n;
	ubicar (id,0);
	grabar (id,r0);
}

ampliar_datos (int idd) {
	REG b,r0;
	int i,j;
	long n;

	ubicard (idd,0);
	leerd (idd,r0);
	n = lseek (idd,(long)0,SEEK_END);
	n = n / LON_DATOS;
	strcpy (b.nombre, "vacio");
	for (i=(int)n; i < (int)n+40; i++) {
		b.cod = i+1;
		grabard (idd,b);
	}
	b.cod = 0;
	grabard (idd,b);
	r0.cod = (int)n;
	ubicard (idd,0);
	grabard (idd,r0);
}

inicializar (REGISTRO *p)
{
	int i,j;

	p->cont = p->tipo =  0;
	for (j=0; j < M; j++)
		p->info [j] = 0;
	for (j=0; j < M1; j++)
		p->apunt [j] = 0;
}

crear_pagina (int id,int x,REGISTRO *r0,REGISTRO *b)
{
	int p;

	p = disp (id,r0);
	inicializar (b);
	b->cont = 1;
	b->info [0] = x;
	return (p);
}

copiar (REGISTRO *p, REGISTRO q) {
	int i;

	p->cont = q.cont;
	p->tipo = q.tipo;
	for (i=0; i < M; i++)
		p->info[i] = q.info [i];
	for (i=0; i < M1; i++)
		p->apunt [i] = q.apunt [i];
}


disp (int id,REGISTRO *p)
{
	int i;
	REGISTRO b;

	i = p->apunt [M1-1];
	if (i == 0) {
		ampliar_indice (id);
		ubicar (id,0);
		leer (id,b);
		copiar (p,b);
		i = p->apunt [M1-1];
	}
	ubicar (id,i);
	leer (id,b);
	p->apunt [M1-1] = b.apunt [M1-1];
	return (i);
}


crear_reg (int idd,REG registro,REG *p)
{
	int i;
	REG b;

	i = disp_reg (idd,p);
	ubicard (idd,i);
	b.cod = registro.cod;
	strcpy (b.nombre, registro.nombre);
	grabard (idd,b);
	return (i);
}

disp_reg (int idd,REG *p)
{
	int i;
	REG b;

	i = p->cod;
	if (i == 0) {
		ampliar_datos (idd);
		ubicard (idd,0);
		leerd (idd,b);
		i = p->cod = b.cod;
	}
	ubicard (idd,i);
	leerd (idd,b);
	p->cod = b.cod;
	return (i);
}



buscar (int id,int x,int *posicion,LIFO *pila)
{
	int i,encontro = 0,p;
	REGISTRO b;

	*posicion = -1;
	ubicar (id,0);
	leer (id,b);
	p = b.cont;
	while (p && !encontro) {
		ins_pila (pila, p);
		i = 0;
		ubicar (id,p);
		leer (id,b);
		while (x > b.info[i] && i < b.cont - 1)
			i++;
		if (x < b.info [i])
			if (b.tipo == INTERNA)
				p = b.apunt [i];
			else p = 0;
		else if (x > b.info [i])
			if (b.tipo == INTERNA)
				p = b.apunt [i+1];
			else p = 0;
		else if (b.tipo == INTERNA)
			p = b.apunt [i + 1];
		     else encontro = 1;
	}
	if (!encontro)
		*posicion = i;
	else return (b.apunt [i]);
}

insertar (REGISTRO *p,int x,int *i,int tipo)
{
	int j;

	if (p->cont)
		if (x > p->info [*i])
			(*i)++;
		else {
			j = p->cont - 1;
			while (j >= *i) {
				p->info [j+1] = p->info [j];
				if (tipo == EXTERNA)
					p->apunt [j+1] = p->apunt [j];
				j--;
			}
		}
	p->cont++;
	p->info [*i] = x;
}

donde (REGISTRO *p, int x)
{
	int i;

	i= 0;
	while (x > p->info [i] && i < p->cont - 1)
		i++;
	return (i);
}

romper  (int id,REGISTRO *p,int t,int *q,int x,int *subir, int separar,
			REGISTRO *r0,REGISTRO *bb)
{
	int aa [M1], i=0 ,j, s = 0;
	int b[M1+1],temp;

	if (separar == 0) {
		temp = p->apunt [M];
		p->apunt [M] = 0;
	}
	while (i < M && !s)
		if (p->info[i] < x) {
			aa[i] =p->info [i];
			b[i] = p->apunt [i];
			p->apunt [i++] = 0;
		}
		else s = 1;

	if (separar == 1) {
		aa[i] = x;
		b[i] = p->apunt [i];
		p->apunt [i] = 0;
		b[++i] = t;
		while (i <= M) {
			aa[i] =p->info [i-1];
			b[i+1] = p->apunt [i];
			p->apunt [i++] = 0;
		}
	}
	else {
		aa[i] = x;
		b[i++] = t;
		while (i <= M) {
			aa[i] =p->info [i-1];
			b[i] = p->apunt [i-1];
			p->apunt [i-1] = 0;
			i++;
		}
	}
	*q = disp (id,r0);
	inicializar (bb);
	i = 0;
	if (separar == 0) {
		p->cont = N;
		bb->cont = N + 1;
		bb->info [0] = aa[N];
		bb->apunt [0] = b [N];
		while (i < N) {
			p->info [i] = aa[i];
			p->apunt [i] = b [i];
			bb->info [i+1] = aa[i+N+1];
			bb->apunt [i+1] = b[i+N+1];
			i++;
		}
		bb->apunt [M] = temp;
		p->apunt [M] = *q;
		bb->tipo = EXTERNA;
	}
	else {
		p->cont = bb->cont = N;
		while (i < N) {
			p->info [i] = aa[i];
			p->apunt [i] = b [i];
			bb->info [i] = aa[i+N+1];
			bb->apunt [i] = b[i+N+1];
			i++;
		}
		p->apunt [N] = b [N];
		bb->apunt [N] = b [M1];
		bb->tipo = INTERNA;
	}
	*subir = aa [N];
}

cderecha_apunt (REGISTRO *p,int i)
{
	int j;

	j = p->cont;
	while (j > i) {
		p->apunt [j] = p->apunt [j - 1];
		j--;
	}
}



listar_b (int id)
{
	int i,p;
	LIFO1 pila;
	REGISTRO b;

	ubicar (id,0);
	leer (id,b);
	p = b.cont;
	init1_pila (&pila);
	while (p) {
		ubicar (id,p);
		leer (id,b);
		ins1_pila (&pila,p,0);
		if (b.tipo == INTERNA)
			p = b.apunt [0];
		else p = 0;
	}
	while (!pila1_vacia (&pila) ) {
		retira1_pila (&pila,&p,&i);
		ubicar (id,p);
		leer (id,b);
		if (i < b.cont) {
			printf ("%d",b.info [i]);
			if (b.tipo == 0)
				printf ("I ");
			else printf ("E ");
			ins1_pila (&pila,p,i+1);
			if (b.tipo == EXTERNA)
				p = 0;
			else p = b.apunt [i+1];
			while (p) {
                        	ubicar (id,p);
				leer (id,b);
				ins1_pila (&pila,p,0);
				if (b.tipo == INTERNA)
					p = b.apunt [0];
				else p = 0;
			}
		}
	}
}

ins_bmas (int id, int idd,int x,int *s, REG registro)
{
	int posicion,i,j,subir,subir1,terminar,separar;
	int p,q,nuevo,nuevo1;
	LIFO pila;
	REGISTRO r0,b,pc;
	REG r00;

	init_pila (&pila);
	*s = 0;
	ubicar (id,0);
	leer (id,r0);
	ubicard (idd,0);
	leerd (idd,r00);
	if (r0.cont == 0) {
	   q = crear_reg (idd,registro, &r00);
	   i = crear_pagina (id,x,&r0,&b);
	   b.apunt [0] = q;
	   r0.cont = r0.info[0] = i;
	   b.tipo = EXTERNA;
	   ubicar (id,i);
	   grabar (id,b);
	}
	else {
		buscar (id, x, &posicion, &pila);
		if (posicion == -1)
		   *s = 1;              /* La llave esta en el arbol */
		else {
			terminar = separar = 0;
			while (!pila_vacia (&pila) && terminar == 0) {
			  retira_pila (&pila, &p);
			  ubicar (id,p);
			  leer (id,pc);
			  if (pc.cont == M) {
			     if (separar == 0) {
				q = crear_reg (idd,registro,&r00);
				romper (id, &pc, q, &nuevo, x, &subir,separar,
					&r0,&b);
				ubicar (id,p);
				grabar (id,pc);
				ubicar (id,nuevo);
				grabar (id,b);
				separar = 1;
			     }
			     else {
				     romper (id,&pc,nuevo,&nuevo1,
					subir,&subir1,separar,&r0,&b);
				     ubicar (id,p);
				     grabar (id,pc);
				     ubicar (id,nuevo1);
				     grabar (id,b);
				     subir = subir1;
				     nuevo = nuevo1;
			     }
			  }
			  else {
				  if (separar == 1) {
				     separar = 0;
				     i = donde (&pc, subir);
				     insertar (&pc, subir, &i,INTERNA);
				     cderecha_apunt (&pc, i+1);
				     pc.apunt [i+1] = nuevo;
				     ubicar (id,p);
				     grabar (id,pc);
				  }
				  else {
					insertar (&pc, x,&posicion,EXTERNA);
					q = crear_reg (idd,registro,&r00);
					pc.apunt [posicion] = q;
					ubicar (id,p);
					grabar (id,pc);
				  }
				  terminar = 1;
			  }
			}
			if (separar == 1 && terminar == 0) {
				i = crear_pagina (id, subir,&r0,&b);
				r0.cont = i;
				b.tipo = INTERNA;
				b.apunt [0] = p;
				b.apunt [1] = nuevo;
				ubicar (id,i);
				grabar (id,b);
			}
		}
	}
	ubicar (id,0);
	grabar (id,r0);
	ubicard (idd,0);
	grabard (idd,r00);
}

lea()
{
	char a[10];

	gets (a);
	return (atoi (a) );
}

retirar (REGISTRO *p,int i)
{
	while (i < p->cont - 1) {
		p->info [i] = p->info [i+1];
		if (p->tipo == EXTERNA)
			p->apunt [i] = p->apunt [i+1];
		i++;
	}
	p->cont--;
}

cambio (REGISTRO *p,REGISTRO *q,REGISTRO *r,int i,int x)
{
	int k,t;

	if (x > r->info [r->cont - 1]) {
		t = q->info [i];
		retirar (q,i);
		k = 0;
		insertar (p,t,&k,INTERNA);
		t = r->info [r->cont - 1];
		retirar (r, r->cont - 1);
		k = i;
		if (k == -1)
			k = 0;
		insertar (q,t,&k,INTERNA);
	}
	else {
		t = q->info [i];
		retirar (q, i);
		k = p->cont - 1;
		if (k == -1)
			k = 0;
		insertar (p,t,&k,INTERNA);
		t = r->info [0];
		retirar (r, 0);
		k = i;
		if (q->cont != 0)
			if (k > q->cont - 1)
				k = q->cont -1;
		insertar (q,t,&k,INTERNA);
	}
}

cizquierda_apunt (REGISTRO *p,int i,int j)
{
	while (i < j) {
		p->apunt [i] = p->apunt [i+1];
		i++;
	}
	p->apunt [i] = 0;
}

esta (int id, int p, int x, int *posicion, LIFO1 *pila)
{
	int i = 0,encontro = 0;
	REGISTRO b;

	*posicion = -1;
	while (p != 0 && !encontro) {
		ubicar (id,p);
		leer (id,b);
		i = 0;
		while (x > b.info [i] && i < b.cont - 1)
			i++;
		if (x < b.info [i]) {
			ins1_pila (pila, p, i);
			if (b.tipo == INTERNA)
				p = b.apunt [i];
			else p = 0;
		}
		else if (x > b.info [i]) {
			ins1_pila (pila, p, i+1);
			if (b.tipo == INTERNA)
				p = b.apunt [i+1];
			else p = 0;
		}
		else {
			if (b.tipo == INTERNA) {
				ins1_pila (pila, p, i+1);
				p = b.apunt [i+1];
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

unir (int id, int idd,REGISTRO r0,REG r00,int q, int r,
		int p, REGISTRO qc,REGISTRO rc,REGISTRO pc,
			int i, LIFO1 pila, int  x, int posicion)
{
	int terminar = 0,j, k,t;
	REGISTRO tc;

	libera_reg (idd,pc.apunt [posicion],&r00);
	ubicard (idd,0);
	grabard (idd,r00);
	retirar (&pc, posicion);
	if (x < rc.info [0]) {
		t = p;
		p = r;
		r = t;
		copiar (&tc,pc);
		copiar (&pc,rc);
		copiar (&rc,tc);
	}
	while (terminar == 0) {
	  if (rc.cont < N && pc.cont > N) {	/* CASO 7 */
		cambio (&rc, &qc, &pc, i, x);
		rc.apunt [rc.cont] = pc.apunt [0];
		cizquierda_apunt (&pc, 0, pc.cont + 1);
		grabar_registros (id,p,q,r,pc,qc,rc);
		terminar = 1;
	  }
	  else if (pc.cont < N && rc.cont > N) {   /* CASO 6  */
			cambio (&pc, &qc, &rc, i, x);
			cderecha_apunt (&pc, 0);
			pc.apunt [0] = rc.apunt [rc.cont + 1];
			rc.apunt [rc.cont + 1] = 0;
			grabar_registros (id,p,q,r,pc,qc,rc);
			terminar = 1;
	  }
	  else {
		  j = rc.cont;
		  if (rc.tipo == EXTERNA)	/* Si es el ultimo nivel */
			rc.apunt [M] = pc.apunt [M];
		  else rc.info [j++] = qc.info [i];
		  k = 0;
		  while (k <= pc.cont - 1) {
			rc.info [j] = pc.info [k];
			if (rc.tipo == EXTERNA)
				rc.apunt [j] = pc.apunt [k];
			j++;
			k++;
		  }
		  rc.cont = j;
		  retirar (&qc, i);
		  if (rc.tipo == INTERNA) {
			k = 0;
			j = M - pc.cont;
			while (pc.apunt [k] != 0)
				rc.apunt [j++] = pc.apunt [k++];
		  }
		  liberar (id,p,&r0);
		  if (qc.cont == 0) {
			qc.apunt [i+1] = 0;
			if (pila1_vacia (&pila) ) {
				liberar (id,q,&r0);
				q = 0;
			}
		  }
		  else cizquierda_apunt (&qc, i+1, qc.cont+1);
		  if (q != 0)
			if (qc.cont >= N) {
				ubicar (id,q);
				grabar (id,qc);
				ubicar (id,r);
				grabar (id,rc);
				terminar = 1;
			}
			else {
				t = q;
				copiar (&tc,qc);
				if (!pila1_vacia (&pila) ) {
					retira1_pila (&pila, &q, &i);
					ubicar (id,q);
					leer (id,qc);
					if (x >= qc.info [0]) {
						p = t;
						copiar (&pc,tc);
						ubicar (id,r);
						grabar (id,rc);
						r = qc.apunt [i-1];
						ubicar (id,r);
						leer (id,rc);
						i--;
					}
					else {
						ubicar (id,r);
						grabar (id,rc);
						r = t;
						copiar (&rc,tc);
						p = qc.apunt [i+1];
						ubicar (id,p);
						leer (id,pc);
					}
				}
				else {
					ubicar (id,q);
					grabar (id,qc);
					ubicar (id,r);
					grabar (id,rc);
					terminar = 1;
				}
			}
		  else {
				r0.cont = r;
				ubicar (id,r);
				grabar (id,rc);
				terminar = 1;
		  }
	  }
	}
	ubicar (id,0);
	grabar (id,r0);
}

liberar (int id,int p,REGISTRO *r0)
{
	REGISTRO b;

	inicializar (&b);
	b.apunt [M1-1] = r0->apunt [M1-1];
	r0->apunt [M1-1] = p;
        ubicar (id,p);
	grabar (id,b);
}

libera_reg (int idd, int p,REG *r00)
{
	REG b;

	strcpy (b.nombre,"vacio");
	b.cod = r00->cod;
	r00->cod = p;
	ubicard (idd,p);
	grabard (idd,b);
}

grabar_registros (int id, int p,int q, int r,
			REGISTRO pc,REGISTRO qc, REGISTRO rc) {
	ubicar (id,p);
	grabar (id,pc);
	ubicar (id,q);
	grabar (id,qc);
	ubicar (id,r);
	grabar (id,rc);
}

retira_b (int id, int idd, int x, int *s)
{
	int posicion, i, k, p, q, r, t, temp,temp1;
	LIFO1 pila;
	REGISTRO r0,pc,qc,rc;
	REG r00;

	ubicar (id,0);
	leer (id,r0);
	ubicard (idd,0);
	leerd (idd,r00);
	*s = 1;
	init1_pila (&pila);
	esta (id, r0.cont, x, &posicion, &pila);
	if (posicion == -1) {
		*s = 0;   /* La llave no existe en el arbol  */
		return (0);
	}
	retira1_pila (&pila, &p, &i);
	ubicar (id,p);
	leer (id,pc);
	if (pc.cont > N) {
		libera_reg (idd,pc.apunt [posicion],&r00);
		ubicard (idd,0);
		grabard (idd,r00);
		retirar (&pc, posicion);
		ubicar (id,p);
		grabar (id,pc);
		return (1);
	}
	if (pila1_vacia (&pila) ) {
		libera_reg (idd,pc.apunt [posicion],&r00);
                ubicard (idd,0);
		grabard (idd,r00);
		retirar (&pc, posicion);
		if (pc.cont == 0) {
			liberar (id,r0.cont,&r0);
			r0.cont = r0.info[0] = 0;
			ubicar (id,0);
			grabar (id,r0);
			return(1);
		}
		ubicar (id,0);
		grabar (id,r0);
                ubicar (id,p);
		grabar (id,pc);
		return (1);
	}
	retira1_pila (&pila, &q, &i);
	ubicar (id,q);
	leer (id,qc);
	if (i < qc.cont) {
		r = qc.apunt [i+1];
		ubicar (id,r);
		leer (id,rc);
		if (rc.cont > N) {
			libera_reg (idd,pc.apunt [posicion],&r00);
                        ubicard (idd,0);
			grabard (idd,r00);
			retirar (&pc, posicion);
			temp = rc.info [0];
			temp1= rc.apunt [0];
			retirar (&rc,0);
			retirar (&qc,i);
			k = donde (&pc,temp);
			insertar (&pc,temp,&k,EXTERNA);
			pc.apunt [k] = temp1;
			k = donde (&qc,rc.info [0]);
			insertar (&qc,rc.info[0], &k,INTERNA);
			grabar_registros (id,p,q,r,pc,qc,rc);
			return (1);
		}
	}
	if (i > 0) {
		r = qc.apunt [i-1];
		ubicar (id,r);
		leer (id,rc);
		if (rc.cont > N) {
			libera_reg (idd,pc.apunt [posicion],&r00);
			retirar (&pc, posicion);
			temp = rc.info [  rc.cont -1 ];
			temp1 = rc.apunt [ rc.cont -1  ];
			retirar (&rc,rc.cont -1);
			retirar (&qc,i-1);
			k = donde (&pc,temp);
			insertar (&pc,temp,&k,EXTERNA);
			pc.apunt [k] = temp1;
			k = donde (&qc,temp);
			insertar (&qc,temp, &k,INTERNA);
                        grabar_registros (id,p,q,r,pc,qc,rc);
			ubicard (idd,0);
			grabard (idd,r00);
			return (1);
		}
	}
	if (i > 0)
		i--;
	unir (id,idd,r0,r00,q,r,p,qc,rc,pc,i,pila,x,posicion);
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

listar2()
{
	int i=0,j,k=0,id,idd;
	FILE *p,*fopen();
	REGISTRO b;
	REG b1;

	p = fopen ("CON","w");
	fprintf (p,"\n");
	fprintf (p,"tp pos  cont  l l a v e s   apuntadores \n");
	id = _open ("indice",O_RDONLY);
	idd = _open ("datos",O_RDONLY);
	for (;i<25;i++) {
		leer (id,b);
		fprintf (p,"%2d %2d     %2d   ",b.tipo,k++,b.cont);
		for (j=0; j<M; j++)
			fprintf (p,"%3d ",b.info[j]);
		fprintf (p,"     ");
		for (j=0; j<M1; j++)
			fprintf (p,"%3d ",b.apunt [j]);
		fprintf (p,"\n");
	}
	getch();
        fprintf (p,"\n");
	for (i=0; i < 24;i++) {
		leerd (idd,b1);
		fprintf (p,"%d     %d %s\n",i,b1.cod,b1.nombre);
	}
        fprintf (p,"\n");
	fclose (p);
	cerrar (id);
	cerrar (idd);
}


listar_VSAM () {
	int    i,p,j,id,idd;
	REGISTRO b;
	REG b1;

	id = _open ("indice",O_RDONLY);
	idd = _open ("datos",O_RDONLY);
	ubicar (id,0);
	leer (id,b);
	p = b.info[0];

	while (p != 0) {
		i=0;
		ubicar (id,p);
		leer (id,b);
		while (i < b.cont) {
			j = b.apunt [i];
			ubicard (idd,j);
			leerd (idd,b1);
			printf ("%d %s\n",b1.cod,b1.nombre);
			i++;
		}
		p = b.apunt [M];
	}
	cerrar (id);
	cerrar (idd);
	printf ("\n");
}

error(char *a) {
	char *p;

	p = _strerror (a);
	printf ("%s\n",p);
	getch();
	exit(1);
}

