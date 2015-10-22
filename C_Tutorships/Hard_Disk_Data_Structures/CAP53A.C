/* Maneja un cursor lista doblemente encadenado en disco duro, cuando
	la informacion de cada registro es de tipo entero */


#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "fcntl.h"
#define MAXIMO 10
#define P(x)  printf ("%s\n",x)
#define LON sizeof (BUFFER)
#define grabar(id,a)  _write (id,(char *)&a,LON)
#define lea(id,a)  _read (id,(char *)&a,LON)
#define ubicar(id,a)  lseek (id,(long)a * LON, SEEK_SET)
typedef struct BUFFER BUFFER;

struct BUFFER {
	int ant;
	int info;
	int sig;
};

main()
{
	int id,n;
	BUFFER x;

	id = init_archivo ();
	id = _open ("lista",O_RDWR);
	P(" ");
	P("De codigo");
	n = lea_entero();
	while (n != 9999) {
		if (insertar (id, n) == -1)
			P("Repetido");
		else P("Insertado");
		P("De entero");
		n = lea_entero();
	}
	escribir (id);
	getch();
	P(" ");
	P("De codigo a retirar ");
	n = lea_entero();
	while (n != 9999) {
		if (retirar (id, n) == -1)
			P("No existe...");
		else P("Retirado...");
		P("De codigo a retirar ");
		n = lea_entero();
	}
	escribir (id);
	P(" ");
	ubicar (id,0);
	n=0;
	while (lea (id,x) )
		printf ("%2d %2d %2d %2d\n",n++,x.ant,x.info,x.sig);
	close (id);
	getch();
}


init_archivo ()
{
	int i,id;
	BUFFER a;

	id = _creat ("lista",32);
	a.ant = a.info = 0;
	for (i=0; i < MAXIMO; i++) {
		a.sig = i + 1;
		grabar (id,a);
	}
	a.sig = 0;
	grabar (id,a);
	close (id);
	return (id);
}

lea_entero()
{
	char a[10];

	gets (a);
	return (atoi (a));
}


escribir (int id)
{
	int i;
	BUFFER a;

	ubicar (id,0);
	lea (id,a);
	i = a.ant;
	while (i != 0) {
		ubicar (id,i);
		lea (id,a);
		printf ("%d ",a.info);
                i = a.sig;
	}
	P("\n");
	ubicar (id,0);
	lea (id,a);
	i = a.info;
	while (i != 0) {
		ubicar (id,i);
		lea (id,a);
		printf ("%d ",a.info);
		i = a.ant;
	}
}


insertar (int id,int n)
{
	int p,q,enc,prox;
	BUFFER r0,pc,qc,proxc;

	ubicar (id,0);
	lea (id,r0);
	p = r0.ant;
	enc = q = 0;
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
			return (-1);


	prox = disp (id, &r0);

	if (prox != -1) {
		proxc.info = n;
		proxc.sig = p;
		proxc.ant = q;
		ubicar (id,prox);
		grabar (id,proxc);
		if (p == 0)
			r0.info = prox;
		else {
			pc.ant = prox;
			ubicar (id,p);
			grabar (id,pc);
		}
		if (q == 0)
			r0.ant = prox;
		else {
			qc.sig = prox;
			ubicar (id,q);
			grabar (id,qc);
		}
	}
	else {
		P("Archivo lleno. Se debe ampliar el archivo...");
		getch();
		exit (1);
	}
	ubicar (id,0);
	grabar (id,r0);

}


disp (int id, BUFFER *r0)
{
	int i;
	BUFFER r1;

	i = r0->sig;
	if (i == 0)
		return (-1);
	else {
		ubicar (id,i);
		lea (id, r1);
		r0->sig = r1.sig;
		return (i);
	}
}


retirar (int id,int n)
{
	BUFFER r0,pc,qc,rc;
	int p,q,r,enc;

        ubicar (id,0);
        lea (id,r0);
        p = r0.ant;
        enc = 0;
	while (p != 0 && !enc) {
		ubicar (id,p);
		lea (id,pc);
		if (n > pc.info)
			p = pc.sig;
		else enc = 1;
	}

	if (enc == 1)
		if (pc.info != n)
			return (-1); /* No existe */
	if (p == 0)
	   return (-1); /* No existe */

        r = pc.ant;
        q = pc.sig;
        if (r == 0)
	   if (q == 0) {
	      r0.ant = 0;
	      r0.info = 0; /* Final de la lista */
	   }
           else {
                    r0.ant = pc.sig;
                    ubicar (id,q);
                    lea (id,qc);
                    qc.ant = 0;
                    ubicar (id,q);
                    grabar (id,qc);
           }
	else if (q == 0) {
		r0.info = r; /* Apunta al ultimo de la lista */
		ubicar (id,r);
		lea (id,rc);
		rc.sig = 0;
		ubicar (id,r);
		grabar (id,rc);
	}
	else {
		ubicar (id,r);
		lea (id,rc);
		ubicar (id,q);
		lea (id,qc);
		rc.sig = q;
		qc.ant = r;
		ubicar (id,r);
		grabar (id,rc);
		ubicar (id,q);
		grabar (id,qc);
	}
	liberar (id,p,pc,&r0);

	ubicar (id,0);
	grabar (id,r0);
	return (0); /* Retirado correctamente */
}


liberar (int id,int p, BUFFER pc, BUFFER *r0)
{
	pc.sig = r0->sig;
	ubicar (id,p);
	grabar (id,pc);
	r0->sig = p;
}




