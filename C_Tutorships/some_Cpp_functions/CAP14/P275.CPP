#include "process.h"
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

void main(int argc, char *argv[]) {
	int i;
	char *p;

	i = execv ("prog.exe",argv);
	if (i == -1) {
		p = _strerror ("Error en execv()");
		printf ("%s\n%d\n",p,argc);
		getch(); exit(1);
	}
	getch();
}
/***********************

#include "stdio.h"
#include "process.h"
#include "conio.h"
#include "stdlib.h"

void main(int argc,char *argv[]) {
	char *p;
	unsigned char i;

	textattr(15);
	clrscr();
	printf ("Linea de comandos\n");
	for (i=0; i < argc; i++)
		printf ("%s\n",argv [i]);
	getch();


}

********************/