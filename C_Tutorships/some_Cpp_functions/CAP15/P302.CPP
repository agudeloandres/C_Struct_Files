#include "bios.h"
#include "stdio.h"
#include "conio.h"

#define PR(x) printf ("%s\n",x)

void main() {   		/* Imprime caracteres en la impresora */
	char a[30],*p;

	PR("De cadena");
	gets (a);

	p = a;
	while (*p != '\0') {
		biosprint (0, *p, 0);
		p++;
	}
	biosprint (0,'\n',0);   /* Se debe escribir este caracter para
				que se acabe de desocupar el buffer de
				la impresora  */
	getch();
}