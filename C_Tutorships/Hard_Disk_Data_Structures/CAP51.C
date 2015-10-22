/* Maneja un cursor lista simple en disco duro */

#include "stdio.h"
#include "io.h"
#include "fcntl.h"
#include "stdlib.h"
#define MAXIMO 5
#define LON sizeof (CURSOR)
#define grabar(id,a)  _write (id,(char *)&a,LON)
#define lea(id,a)  _read (id,(char *)&a,LON)
#define ubicar(id,a)  lseek (id,(long)a * LON, SEEK_SET)
typedef struct CURSOR CURSOR;


struct CURSOR {
	int info;
	int sig;
};

init_cursor ()
{
	int i,id;
	CURSOR a;

	id = _creat ("borre",32);
	close (id);
	id = _open ("borre",O_RDWR);
	a.info = 0;
	for (i=0; i<MAXIMO ; i++) {
		a.sig = i+1;
		grabar (id,a);
	}
	a.sig = 0;
	grabar (id,a);
	return (id);
}

insertar (int id,int n)
{
	int p,q,enc,prox;
	CURSOR pc,qc,r0,proxc;

	ubicar (id,0);
	lea (id,r0);
	p = r0.info;
	q = enc = 0;
	while (p != 0 && !enc) {
		ubicar (id,p);
		lea (id,pc);
		if (n > pc.info) {
			q = p;
			qc = pc;
			p = pc.sig;
		}
		else enc = 1;
	}

	if (enc == 1)
		if (pc.info == n)
			return (-1); /* Ya existe en el archivo */

	prox = disp(id,&r0);
	if (prox != -1) {
		proxc.info = n;
		proxc.sig = p;
		ubicar (id,prox);
		grabar (id,proxc);
		if (q == 0)
			r0.info = prox;
		else {
			qc.sig = prox;
			ubicar (id,q);
			grabar (id,qc);
		}
	}
	else {
		printf ("lista llena. Se debe ampliar el archivo..\n");
		getch();
		exit (1);
	}
	ubicar (id,0);
	grabar (id,r0);
}




disp (int id, CURSOR *r0)
{
	int i;

	CURSOR r1;
	i = r0->sig;
	if (i==0)
		return (-1);
	else  {
			ubicar (id,i);
			lea (id,r1);
			r0->sig = r1.sig;
			return (i);
	}
}


main ()
{
	int n,id;

	id = init_cursor ();
	printf ("de numero\n");
	n = lea1();
	while (n != 9999) {
		if (insertar (id,n) == -1)
			printf ("repetido\n");
		else printf ("insertado....%d\n",n);
		printf ("de numero\n");
		n = lea1();
	}
	escribir (id);
	close (id);

	id = _open ("borre",O_RDWR);
	printf ("de numero a retirar\n");
	n = lea1();
	while (n != 9999) {
		if (retirar (id,n) == -1)
			printf ("no existe...\n");
		else printf ("retirado ....%d\n",n);
		printf ("de numero a retirar \n");
		n = lea1();
	}
	escribir (id);
	close (id);
	escribir1();
	getch();
}

lea1 ()
{
	char a[10];

	gets (a);
	return (atoi (a));
}

escribir (int id )
{
	int i;

	CURSOR a;

	ubicar (id,0);
	lea (id,a);
	i = a.info;
	while (i!= 0) {
		ubicar (id,i);
		lea (id,a);
		printf ("%d  ",a.info);
		i = a.sig;
	}
}

retirar (int id,int n)
{
	int p,q,enc,prox;
	CURSOR pc,qc,r0,proxc;

	ubicar (id,0);
	lea (id,r0);
	p = r0.info;
	q = enc = 0;
	while (p != 0 && !enc) {
		ubicar (id,p);
		lea (id,pc);
		if (n > pc.info) {
			q = p;
			qc = pc;
			p = pc.sig;
		}
		else enc = 1;
	}


	if (enc == 1)
		if (pc.info != n)
			return (-1); /* No existe */



	if (q == 0)
		r0.info = pc.sig;
	else {
		qc.sig = pc.sig;
		ubicar (id,q);
		grabar (id,qc);
	}
	liberar (id,p,pc,&r0);

	ubicar (id,0);
	grabar (id,r0);
}

liberar (int id,int p, CURSOR pc, CURSOR *r0)
{
	pc.sig = r0->sig;
	ubicar (id,p);
	grabar (id,pc);
	r0->sig = p;
}

escribir1 ()
{
	int id;
	CURSOR a;

	id = _open ("borre",O_RDONLY);
	while (lea (id,a) != 0)
		printf ("%d %d \n",a.info,a.sig);
	close (id);
}

/*

disp (int id)  /* No es muy eficiente */
{
	int i;
	CURSOR r1,r0;

	ubicar (id,0);
	lea (id,r0);
	i = r0.sig;
	if (i==0)
		return (-1);
	else  {
			ubicar (id,i);
			lea (id,r1);
                        r0.sig = r1.sig;
			ubicar (id,0);
			grabar (id,r0);
			return (i);
	}
}

*/
