#include "stdio.h"
#include "process.h"
#include "conio.h"
#include "stdlib.h"

/* La funcion execle(), solamente busca en el directorio actual, si no
		se especifica el camino  */

void main(int argc, char *argv[], char *env[]) {
	char *p;
	int i = execle ("c:\\bc\\work1\\prog.exe","c:\\bc\\work1\\prog.exe",
				"llave","200",NULL,env);
	if (i == -1) {
		p = _strerror ("Error en execle()");
		printf ("%s %d %s\n",p,argc,argv[0]);
		getch();
		exit (1);
	}
}
