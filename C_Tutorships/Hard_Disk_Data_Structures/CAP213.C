/* ESTE PROGRAMA MUESTRA LAS INSTRUCCIONES PARA
	ACTUALIZAR UN ARCHIVO EN DISCO DURO */


#include "stdio.h"
#include "io.h"
#include "fcntl.h"
#include "stdlib.h" /* atof() */
#define LON sizeof (TIPO)
#define grabar(id,p)  _write (id,(char *)&p,LON)
#define lea_reg(id,p)  _read (id,(char *)&p,LON)
#define ubicar(id,i) lseek (id,(long)i * LON,SEEK_SET)

typedef struct TIPO TIPO;
struct TIPO {
	int cod;
	char N[60];
	float precio;
};

main()
{
	int id,posrel,tamano;
	TIPO libro,v;
	char c;

	if ((id = _open ("LIBRO",O_RDWR)   ) == -1   ) {
		printf ("Error en apertura\n");
		exit (1);
	}
	tamano = long_archivo (id);
	printf ("Lea posicion relativa para el libro a modificar\n");
	posrel = lea_entero();
	while (posrel != 9999) {
	   if (posrel >= 0 && posrel < tamano) {
		ubicar (id,posrel);  /* Ubica el registro a modificar */
		lea_reg (id,v);  /* Lee el registro y avanza el apuntador */
		modificar (&v);      /* Modifica el registro  */
		ubicar (id,posrel);  /* Reubica el apuntador */
		grabar (id,v);       /* Graba el registro modificado */
	   }
           else printf ("\nPosicion relativa invalida..\n");
           printf ("Lea posicion relativa para el libro a modificar\n");
           posrel = lea_entero();
	}
	close (id);
	id = _open ("LIBRO",O_RDONLY);
	while (lea_reg (id,v) != 0)
		printf ("%d %s %f\n",v.cod,v.N,v.precio);
	close (id);
	getch();
}


lea_entero ()
{
	char a[10];
	gets (a);
	return (atoi(a));
}

modificar (struct TIPO *p)
{
	char aux [10],c;

	printf ("Modifica codigo? (s/n)\n");
	c = getch();
	if (c == 's') {
		printf ("Lea codigo\n");
		gets (aux);
		p->cod = atoi (aux);
	}
	printf ("Modifica nombre? (s/n)\n");
	c = getch();
	if (c == 's') {
		printf ("Lea nombre\n");
		gets (p->N);
	}
	printf ("Modifica precio? (s/n)\n");
	c = getch();
	if (c == 's') {
		printf ("Lea precio \n");
		gets (aux);
		p->precio = atof (aux);
	}
}

long_archivo(int id)
{
	long final;

	final = lseek (id,(long)0,SEEK_END);
	return ( (int) final / LON);
}
