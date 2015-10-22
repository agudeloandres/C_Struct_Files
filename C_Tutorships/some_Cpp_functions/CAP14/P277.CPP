#include "process.h"
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

void main(int argc, char *argv[]) {
	int i;
	char *p;

	i = execvp ("prog.exe",argv);
	if (i == -1) {
		p = _strerror ("Error en execvp()");
		printf ("%s\n%d\n",p,argc);
		getch(); exit(1);
	}
	getch();
}
//  Programa de prueba. Favor compilar y probar con este codigo

/**************  Programa prog.cpp ****************/
/*
#include "stdio.h"
#include "process.h"
#include "conio.h"
#include "stdlib.h"

void main(int argc,char *argv[]) {
	char *p;
	unsigned char i;

	printf ("Linea de comandos\n");
	for (i=0; i < argc; i++)
		printf ("%s\n",argv [i]);
	getch();
}
*/