#include "dos.h"
#include "stdio.h"
#include "conio.h"

#define arrizq 201
#define arrder 187
#define abajizq 200
#define abajder 188
#define vert 186
#define horiz 205
#define espacio 32

void main() {
	unsigned int far *p;
	int i;

	p = (unsigned int *)MK_FP (0xb000,0);  // Se necesita el (molde) !
	for (i = 0; i < 2000;i++)
		p[i] = 0x0700 + espacio;
	p [0] = 0x0700 + arrizq;
	for (i = 1; i < 79 ;i++)
		p[i] = 0x0700 + horiz;
	p [79] = 0x0700 + arrder;
	for (i = 2; i < 25;i++)
		p[i*80 - 1] = 0x0700 + vert;
	p [1999] = 0x0700 + abajder;
	for (i = 1; i < 24;i++)
		p[i*80] = 0x0700 + vert;
	p [1920] = 0x0700 + abajizq;
	for (i = 1; i < 79 ;i++)
		p[i + 1920] = 0x0700 + horiz;
	getch();
}