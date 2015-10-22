#include "stdio.h"
#include "io.h"
#include"dos.h"
#include "fcntl.h"

#define LON sizeof (int)
#define lea(x,y) {  if(_read(x,(char *)&y,LON)==-1) error();   }
#define grabe(x,y) {  if(_write(x,(char *)&y,LON)==-1) error();   }
#define ubicar(x) {  if(lseek(x,(long)0,SEEK_END)==-1) error();   }
#define cierre(x) {  if(_close(x)==-1) error();   }
#define borre(x) {  if(unlink(x)==-1) error();   }
#define MENOR_VALOR -32768

main() {
	int sw;
	int ant,ant1,n,n1,UNO,DOS,TRES,CUATRO,termina,termina1,*p,*q;

	clrscr();
	UNO = _creat ("uno.dat",FA_ARCH);
	cierre(UNO);
	DOS = _creat ("dos.dat",FA_ARCH);
	cierre(DOS);
	sw = access ("cuatro.dat",0);
	if (sw == 0)
		unlink ("cuatro.dat");
	if(rename ("salida","cuatro.dat")==-1) error();
	printf ("Original\n");
	listar ("cuatro.dat");
	CUATRO = _open("cuatro.dat",O_RDONLY);
	UNO = _open("uno.dat",O_WRONLY);
	DOS = _open("dos.dat",O_WRONLY);
	ant = MENOR_VALOR;
	sw = 0;
	while (!eof(CUATRO) ) {
		lea (CUATRO,n);
		if (ant > n)
			if (sw == 0)
				sw = 1;
			else sw = 0;
		ant = n;
		if (sw == 0)
			grabe (UNO,n)
		else grabe (DOS,n)
	}

	cierre(UNO);
	cierre(DOS);
	cierre(CUATRO);
	UNO = _open("uno.dat",O_RDONLY);
	DOS = _open("dos.dat",O_RDONLY);
	sw = 0;
	while (filelength (UNO) != 0 && filelength (DOS) != 0) {
		TRES = _creat ("tres.dat",FA_ARCH);
		cierre (TRES);
		CUATRO = _creat ("cuatro.dat",FA_ARCH);
		cierre (CUATRO);
		TRES = _open ("tres.dat",O_WRONLY);
		CUATRO = _open ("cuatro.dat",O_WRONLY);
		q = &TRES;
		ant = ant1 = MENOR_VALOR;
		lea (UNO,n);
		lea (DOS,n1);
		termina = termina1 = 0;
		while (termina == 0 && termina1 == 0) {
			if (ant <= n && ant1 <= n1) {
				ant = n;
				ant1 = n1;
				if (n <= n1) {
					grabe(*q,n);
					if (!eof(UNO))
						lea(UNO,n)
					else termina = 1;
				}
				else {
					grabe (*q,n1);
					if (!eof (DOS))
						lea(DOS,n1)
					else termina1 = 1;
				}
				continue;
			}
			if (ant <= n) {
				ant = n;
				grabe (*q,n);
				if (!eof(UNO))
					lea(UNO,n)
				else termina = 1;
				continue;
			}
			if (ant1 <= n1) {
				ant1 = n1;
				grabe(*q,n1);
				if (!eof(DOS))
					lea(DOS,n1)
				else termina1 = 1;
				continue;
			}
			cambio (&q, &sw, &CUATRO, &TRES);
			ant = ant1 = MENOR_VALOR;
		}
		if (termina == 1) {
			if (n1 <= n)
				cambio (&q, &sw, &CUATRO, &TRES);
			p = &DOS;
			ant = n1;
		}
		else {
			if (n <= n1)
				cambio (&q, &sw, &CUATRO, &TRES);
			p = &UNO;
			ant = n;
		}
		grabe (*q,ant);
		while (!eof (*p) ) {
			lea(*p,n);
			if (ant > n)
				cambio (&q, &sw, &CUATRO, &TRES);
			ant = n;
			grabe (*q,n);
		}
		cierre(UNO);
		cierre (DOS);
		cierre(TRES);
		cierre (CUATRO);
		borre("uno.dat");
		borre("dos.dat");
		rename ("tres.dat","uno.dat");
		rename ("cuatro.dat","dos.dat");
		UNO = _open ("uno.dat",O_RDONLY);
		DOS = _open ("dos.dat",O_RDONLY);
		sw = 0;
	}
	if (filelength (UNO) == 0) {
		cierre (UNO);
		cierre(DOS);
		rename ("dos.dat","cuatro.dat");
	}
	else {
		cierre(UNO);
		cierre(DOS);
		rename ("uno.dat","cuatro.dat");
	}
	listar ("cuatro.dat");
	getch();
}

cambio (int **q, int *sw, int *a, int *b) {
	if (*sw == 0) {
		*q = a;
		*sw = 1;
	}
	else {
		*q = b;
		*sw = 0;
	}
}

listar (char *a) {
	int UNO,n;

	printf ("\n");
	UNO = _open (a,O_RDONLY);
	while (!eof (UNO) ) {
		lea (UNO,n);
		printf ("%d ",n);
	}
	printf ("\n");
	cierre (UNO);
}

error() {
	printf ("%s",_strerror("Error!"));
	getch();
	exit(1);
}

