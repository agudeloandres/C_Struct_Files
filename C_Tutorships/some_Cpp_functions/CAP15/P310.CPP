#include "bios.h"
#include "stdio.h"
#include "conio.h"

#define UNIDAD 0

#define PR_B(x) { printf ("%s\n",x);break; }

/* Chequea un diskette formateado con el format de DOS 3.0 */
/* 2 cabezas(0,1)	40 pistas(0-39)  9 sectores (1-9)  */

void main() {
	int pistas,sectores,cabezas,i;
	char b[512];
	void estado(int);

	clrscr();
	for (cabezas = 0; cabezas <= 1; cabezas++)
		for (pistas = 0; pistas <= 39; pistas++)
			for (sectores = 1; sectores <= 9; sectores++) {
				i = biosdisk (4,UNIDAD,cabezas,pistas,sectores,1,b);
				printf ("%d %d %d\n",cabezas,pistas,sectores);
				if (i != 0) estado(i);
			}
	printf ("Fin...\n");
	getch();
}

void estado (int i) {
	switch (i) {
		case  0x00 : PR_B ("Operacion Correcta");
		case  0x01 : PR_B ("Comando Incorrecto");
		case  0x02 : PR_B ("Direccion marcada no encontrada");
		case  0x03 : PR_B ("Disco Protegido");
		case  0x04 : PR_B ("Sector no encontrado");
		case  0x05 : PR_B ("Falla al reinicializar el disco");
		case  0x06 : PR_B ("Disco cambiado");
		case  0x07 : PR_B ("Falla en la unidad especificada");
		case  0x08 : PR_B ("Memoria de acceso directo exedida");
		case  0x09 : PR_B ("Intento de cruzar la memoria DMA mas haya\
					\ de los 64Kb");
		case  0x0A : PR_B ("Sector malo detectado");
		case  0x0B : PR_B ("Pista mala detectada");
		case  0x0C : PR_B ("Pista inexistente");
		case  0x10 : PR_B ("Error en CRC (Controlador)");
		case  0x11 : PR_B ("Error corregido por CRC/ECC");
		case  0x20 : PR_B ("Falla en el controlador");
		case  0x40 : PR_B ("Falla en una operacion seek()");
		case  0x80 : PR_B ("Falla en coneccion");
		case  0xAA : PR_B ("Unidad de disco duro no esta lista");
		case  0xBB : PR_B ("Error indefinido");
		case  0xCC : PR_B ("Error en escritura");
		case  0xE0 : PR_B ("Error en el estado");
		case  0xFF : PR_B ("Falla en la operacion");
		default : PR_B ("Error");
	}
}