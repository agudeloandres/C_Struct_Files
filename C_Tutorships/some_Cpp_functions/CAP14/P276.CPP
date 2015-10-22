#include "stdio.h"
#include "process.h"
#include "conio.h"
#include "stdlib.h"

/* La funcion execve(), solamente busca en el directorio actual */

void main(int argc,char *argv[],char *env[]) {
	char *p;
	int i = execve ("prog.exe",argv,env);
	if (i == -1) {
		p = _strerror ("Error en execve()");
      printf ("%s %d\n",p,argc);
		getch();
		exit (1);
	}
	getch();
}

//*****************  Programa prog.cpp  (De prueba) *****************/

/******************

#include "stdio.h"
#include "process.h"
#include "conio.h"
#include "stdlib.h"

void main(int argc,char *argv[],char *env[]) {
	char *p;
	unsigned char i;

	textattr(15);
	clrscr();
	printf ("Medio ambiente\n");
	for (i=0; env[i] != NULL; i++)
		printf ("%s\n",env[i]);
	printf ("Linea de comandos\n");
	for (i=0; i < argc; i++)
		printf ("%s\n",argv [i]);
	getch();
}

 ************/