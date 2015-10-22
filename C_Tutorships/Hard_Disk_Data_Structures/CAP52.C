
/* Maneja un cursor lista simple en disco duro, cuando la informacion
	de cada registro es de tipo INFO */

#include "stdio.h"
#include "io.h"
#include "fcntl.h"
#include "stdlib.h"
#define MAXIMO 300
#define LON sizeof (BUFFER)
#define grabar(id,a)  _write (id,(char *)&a,LON)
#define lea(id,a)  _read (id,(char *)&a,LON)
#define ubicar(id,a)  lseek (id,(long)a * LON, SEEK_SET)
typedef struct BUFFER BUFFER;
typedef struct INFO INFO;

struct INFO {
       int cod;
       char nombre [30];
};

struct BUFFER {
	INFO info;
	int sig;
};

init_archivo ()
{
	int i,id;
	BUFFER a;

	id = _creat ("lista",32);
	close (id);
	id = _open ("lista",O_RDWR);
	a.info.cod = 0;
        strcpy (a.info.nombre,"        ");
	for (i=0; i<MAXIMO ; i++) {
		a.sig = i+1;
		grabar (id,a);
	}
	a.sig = 0;
	grabar (id,a);
	return (id);
}

insertar (int id,BUFFER n)
{
	int p,q,enc,prox;
	BUFFER pc,qc,r0,proxc;

	ubicar (id,0);
	lea (id,r0);
	p = r0.info.cod;
	q = enc = 0;
        while (p != 0 && !enc) {
		ubicar (id,p);
		lea (id,pc);
		if (n.info.cod > pc.info.cod) {
			q = p;
                        copie (&qc,pc);
			p = pc.sig;
		}
		else enc = 1;
	}

	if (enc == 1)
		if (pc.info.cod == n.info.cod)
			return (-1); /* Ya existe en el archivo */

	prox = disp(id,&r0);
	if (prox != -1) {
		proxc.info.cod = n.info.cod;
                strcpy (proxc.info.nombre,n.info.nombre);
		proxc.sig = p;
		ubicar (id,prox);
		grabar (id,proxc);
		if (q == 0)
			r0.info.cod = prox;
		else {
			qc.sig = prox;
			ubicar (id,q);
			grabar (id,qc);
		}
	}
	else {
		printf ("Archivo lleno. Se debe ampliar el archivo..\n");
		getch();
		exit (1);
	}
	ubicar (id,0);
	grabar (id,r0);
}

copie (BUFFER *q,BUFFER p)
{
        q->info.cod = p.info.cod;
        strcpy (q->info.nombre, p.info.nombre);
        q->sig = p.sig;
}






disp (int id, BUFFER *r0)
{
	int i;

	BUFFER r1;
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
	int id,n1;
        BUFFER n;
        char c;

	id = init_archivo ();
	printf ("de datos \n");
        c = 's';
	while (c == 's' || c == 'S') {
                lea1 (&n);
		if (insertar (id,n) == -1)
			printf ("repetido\n");
		else printf ("insertado....%d\n",n);
		printf ("Desea continuar? (s/n)\n");
                c = getch();
	}
	escribir (id);
	close (id);

	id = _open ("lista",O_RDWR);
	printf ("de codigo a retirar\n");
	while (  (n1=lea_entero()  ) != 9999) {
		if (retirar (id,n1) == -1)
			printf ("no existe...\n");
		else printf ("retirado ....%d\n",n1);
		printf ("de codigo a retirar \n");
	}
	escribir (id);
	close (id);
        getch();
	escribir1();
	getch();
}

lea_entero  ()
{
	char a[10];

	gets (a);
	return (atoi (a));
}

lea1 (BUFFER *p)
{
	char a[10];

        printf ("De codigo\n");
	gets (a);
	p->info.cod = atoi (a);
        printf ("De nombre \n");
	gets (p->info.nombre);
}

escribir (int id )
{
	int i;

	BUFFER a;

	ubicar (id,0);
	lea (id,a);
	i = a.info.cod;
	while (i != 0) {
		ubicar (id,i);
		lea (id,a);
		printf ("%d %s\n ",a.info.cod,a.info.nombre);
		i = a.sig;
	}
}

retirar (int id,int n)
{
	int p,q,enc,prox;
	BUFFER pc,qc,r0,proxc;

	ubicar (id,0);
	lea (id,r0);
	p = r0.info.cod;
	q = enc = 0;
	while (p != 0 && !enc) {
		ubicar (id,p);
		lea (id,pc);
		if (n > pc.info.cod) {
			q = p;
                        copie (&qc,pc);
			p = pc.sig;
		}
		else enc = 1;
	}


	if (enc == 1)
		if (pc.info.cod != n)
			return (-1); /* No existe */



	if (q == 0)
		r0.info.cod = pc.sig;
	else {
		qc.sig = pc.sig;
		ubicar (id,q);
		grabar (id,qc);
	}
	liberar (id,p,pc,&r0);

	ubicar (id,0);
	grabar (id,r0);
}

liberar (int id,int p, BUFFER pc, BUFFER *r0)
{
	pc.sig = r0->sig;
	ubicar (id,p);
	grabar (id,pc);
	r0->sig = p;
}

escribir1 ()
{
	int id;
	BUFFER a;

	id = _open ("lista",O_RDONLY);
	while (lea (id,a) != 0)
		printf ("%d %s %d \n",a.info.cod,a.info.nombre,a.sig);
	close (id);
}

/*

disp (int id)   No es muy eficiente
{
	int i;
	BUFFER r1,r0;

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