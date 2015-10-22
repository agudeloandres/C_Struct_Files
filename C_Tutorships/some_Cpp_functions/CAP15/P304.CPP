#include "bios.h"
#include "stdio.h"
#include "conio.h"


struct BITS {
	unsigned cero : 1;
	unsigned uno  : 1;
	unsigned dos_tres : 2;
	unsigned cuatro_cinco : 2;
	unsigned seis_siete : 2;
	unsigned ocho : 1;
	unsigned nueve_diez_once : 3;
	unsigned doce : 1;
	unsigned trece : 1;
	unsigned catorce_quince : 2;
};

union TODO {
	unsigned int i;
	struct BITS bits;
};

void main() {
	union TODO t;
	unsigned int i;

	clrscr();
	i = biosequip ();
	t.i = i;
	if (t.bits.cero == 1) printf ("Boot desde el disco\n");
	if (t.bits.uno == 1) printf ("Coprocesador de punto flotante\n");
	printf ("RAM = ");
	switch (t.bits.dos_tres) {
		case 0 : printf ("16Kb\n");break;
		case 1 : printf ("32Kb\n");break;
		case 2 : printf ("48Kb\n");break;
		case 3 : printf ("64Kb\n");break;
		default : printf ("Error. t.bits.dos_tres\n");break;
	}
	switch (t.bits.cuatro_cinco) {
		case 0 : printf ("Sin uso\n");break;
		case 1 : printf ("40 * 25, Negro y Blanco. Tarjeta color\n");
			 break;
		case 2 : printf ("80 * 25, Negro y Blanco. Tarjeta color\n");
			 break;
		case 3 : printf ("80 * 25, Negro y Blanco. Tarjeta mono\n");
			 break;
		default : printf ("Error. t.bits.cuatro_cinco\n");
			  break;
	}
	switch (t.bits.seis_siete) {
		case 0 : printf ("Una unidad\n");break;
		case 1 : printf ("Dos unidades\n");break;
		case 2 : printf ("Tres unidades\n");break;
		case 3 : if (t.bits.cero == 1) printf ("Cuatro unidades\n");
			 break;
		default : printf ("Error. t.bits.seis_siete\n");
			  break;
	}
	if (t.bits.ocho == 1)
		printf ("Maquina sin acceso directo a memoria(DMA)\n");
	else printf ("Maquina con acceso directo a memoria(DMA)\n");
	printf ("Numero de puertos = %u\n",t.bits.nueve_diez_once);
	if (t.bits.doce == 1)
		printf ("Juegos conectados\n");
	if (t.bits.trece == 1)
		printf ("Impresora serial conectada\n");
	if (t.bits.catorce_quince == 1)
		printf ("Impresoras paralelas = %u\n",t.bits.catorce_quince);
	getch();
}





