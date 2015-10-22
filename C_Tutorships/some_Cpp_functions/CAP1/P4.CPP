#include "stdio.h"
#include "conio.h"
void main() {
	void lea_cadena (char a[]);
	char a[20];
	lea_cadena(a);
	printf ("\n%s\n",a);
	getch();
}

void lea_cadena (char a[]) {
	char c;
	unsigned char i=0;

	while ((c=getche()) != 13)     /* Termina con la tecla <R> */
		a[i++] = c;
	a[i] = '\0';
}