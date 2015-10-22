#include "bios.h"
#include "stdio.h"
#include "conio.h"

#define UNIDAD 0
#define CABEZA 1
#define PISTA 1
#define SECTOR 3
#define NSECTORES 1

#define PR_B(x) { printf ("%s\n",x);break; }

void main() {
	char b [1030];
	int i;
	void estado(int);

	clrscr();
	for (i = 0; i < 511; i++)
		b[i] =  'x';
	b[511] = '\0';
	i = biosdisk (3,UNIDAD,CABEZA,PISTA,SECTOR,NSECTORES,b);
	estado(i);
	printf ("\n");
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