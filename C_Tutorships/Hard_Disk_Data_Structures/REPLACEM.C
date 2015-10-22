#include "stdio.h"
#include "io.h"
#include "fcntl.h"
#include "dos.h"

#define LON sizeof (int)
#define lea(x,y) if(_read (x,(char *)&y,LON)==-1) error()
#define grabe(x,y) if(_write(x,(char *)&y,LON)==-1) error()
#define cerrar(x) if(_close(x)==-1) error()
#define BUFFER 3 /* El numero de elementos por cola es BUFFER - 1 */

typedef struct COLA COLA;
struct COLA {
	int cont;
	int a[BUFFER];
};


main() {
	COLA A,B,*cola1,*cola2,*temp;
	int i,n,llave,entra,sale;


	crear_archivo();


	entra = _open("entrada",O_RDONLY);
	sale = _creat ("salida",FA_ARCH);
	cerrar (sale);
	sale = _open("salida",O_WRONLY);
	cola1 = &A;
	cola2 = &B;
	inicia_p (cola1);
	inicia_p (cola2);
	i = 1;
	while (!eof (entra) && i < BUFFER) {
		lea (entra,n);
		crea_p(cola1,n);
		i++;
	}
	while (!eof (entra) ) {
		lea (entra,n);
		if (cola_vacia (cola1) ) {
                	temp = cola1;
			cola1 = cola2;
			cola2 = temp;
		}
		retirar_p (cola1,&llave);
		grabe (sale,llave);
		if (n < llave)
			crea_p (cola2,n);
		else crea_p (cola1,n);
	}
	while (!cola_vacia (cola1) ) {
		retirar_p (cola1,&llave);
		grabe (sale,llave);
	}
	while (!cola_vacia (cola2) ) {
		retirar_p (cola2,&llave);
		grabe (sale,llave);
	}
	cerrar (entra);
	cerrar (sale);
	printf ("\nsalida\n");
	sale = _open("salida",O_RDONLY);
	while (!eof (sale)) {
		lea (sale,n);
		printf ("%d ",n);
	}
	getch();
}

inicia_p (COLA *m) {
	m->cont = 0;
	m->a[0] = -32768;
}

crea_p (COLA *m, int dato) {
	int i,j;

	m->cont++;
	i = m->cont;
	j = i / 2;
	while (m->a[j] > dato) {
		m->a[i] = m->a[j];
		i = j;
		j = i / 2;
	}
	m->a[i] = dato;
}

cola_vacia (COLA *m) {
	return (m->cont == 0);
}

retirar_p (COLA *m, int *elemento) {
	int i,j,temp;

	*elemento = m->a[1];
	temp = m->a[m->cont];
	m->cont--;
	i = 1;
	j = 2;
	while (j <= m->cont) {
		if (j < m->cont)
			if (m->a[j] > m->a[j+1] )
				j++;
		if (temp <= m->a[j])
			break;
		m->a[i] = m->a[j];
		i = j;
		j = 2 * i;
	}
	m->a[i] = temp;
}


int prueba[] = {
/*6,3,9,27,9,43,5 ,1,1,0,1,8,10,10,7,8,4,51,1, 2,23,0,71,0,2,45, 8,1,1 ,9999};*/
8,4,3,27,9,43,50,4,2,5,1,8,10,10,7,8,4,15,1,22,23,7,17,1,2,45,38,1,10,9999};

crear_archivo() {
	int n,id,i=0;

	id = _creat ("entrada",FA_ARCH);
	cerrar (id);
	id = _open ("entrada",O_WRONLY);
	printf ("De numeros. 9999 para terminar\n");
	n = prueba [i++];
	while (n != 9999) {
		grabe (id,n);
		n = prueba [i++];
	}
	cerrar (id);
}

leer() {
	char a[10];

	gets (a);
	return (atoi (a));
}

error () {
	printf ("%s",_strerror ("Error!")  );
	getch();
	exit(1);
}






