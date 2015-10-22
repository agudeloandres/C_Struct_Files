#include "dos.h"
#include "stdio.h"
#include "conio.h"

#undef peekb
#define PR(x) printf ("%s\n",x)

struct XX  {
	unsigned int uno: 1;
	unsigned int dos: 1;
	unsigned int tres: 1;
	unsigned int cuatro:1;
	unsigned int cinco: 1;
	unsigned int seis: 1;
	unsigned int siete: 1;
	unsigned int ocho: 1;
};

union X {
      struct XX a;
      unsigned char j;
};

void main() {
	unsigned char a;
	union X i;

	a = peekb (0x40,0x17);
	i.j = a;
	if (i.a.uno) PR ("Shift dercha pulsada");
	if (i.a.dos) PR ("Shift izquierda pulsada");
	if (i.a.tres) PR ("Ctrl pulsada");
	if (i.a.cuatro) PR ("Alt pulsada");
	if (i.a.cinco) PR ("Scroll Lock activa");
	if (i.a.seis) PR ("Num Lock activa");
	if (i.a.siete) PR ("Caps Lock activa");
	if (i.a.ocho) PR ("Insertar activa"); /* No funciona en la practica */
	getch();
}




