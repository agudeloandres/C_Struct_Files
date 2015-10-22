#include "io.h"
#include "dos.h"
#include "errno.h"
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

#define UNIDAD 0
#define SECTOR 1
#define PISTA 10
#define CABEZA 0
#define PR(x)  printf ("%s\n",x)


struct X {
	int i;
	char nombre[30];
	float sueldo;
	char filler [476]; /* Para completar 512  bytes */
};




void main() {
	int i,sector_logico;
	struct X buffer;
	void error();
	sector_logico = SECTOR - 1 +
			(CABEZA * 9) +
			(PISTA * 9 * 2);
	i = absread (UNIDAD, 1, sector_logico, (char *)&buffer);
	if (i == -1) error();
	printf ("%d %s %f\n",buffer.i, buffer.nombre, buffer.sueldo);
	getch();
}

void error () {
	switch (errno) {
		case 2 : PR ("Sector no encontrado"); break;
		case 3 : PR ("Disco protegido"); break;
		case 4 : PR ("Sector incorrecto"); break;
		case 8 : PR ("Error de DMA (Acceso Directo a Memoria)"); break;
		case 16: PR ("Fallo CRC. Error en comprobacion de paridad \
				\de datos");
				break;
		case 32: PR ("Fallo en el controlador del disco"); break;
		case 64: PR ("Fallo en el salto al cilindro solicitado");
				break;
		case 128:PR ("La unidad no esta lista"); break;
		default :PR ("Error indeterminado");
	}
	getch();
	exit (1);
}

