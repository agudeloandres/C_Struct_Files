#include "stdio.h"
#include "process.h"
#include "errno.h"
#include "conio.h"
#include "stdlib.h"

/* spawnlpe(), busca en el directorio actual y en PATH del DOS */

void main(int argc, char *argv[],char *env[]) {
	FILE *p;
	char a[30];
	int i = spawnlpe (P_WAIT,"prog.exe","prog.exe","prueba",NULL,env);

	if (i == -1) {
		printf ("%s %s %d\n",strerror (errno),argv[0],argc );
		getch();
		exit (1);
	}
	p = fopen("prueba","r");
	fgets (a,100,p);
	while (!feof(p)) {
		printf ("%s",a);
		fgets (a,100,p);
	}
	fclose (p);
	getch();
}

/*************  Programa prog.cpp(Para prueba) *****************/

#include "stdio.h"
#include "process.h"
#include "alloc.h"
#include "conio.h"
#include "stdlib.h"

/*
void main(int argc, char *argv[], char *env[]) {
	int i,j;
	FILE *p;
	char *copia[10];

	i = 0;
	while (env[i] != NULL) {
		copia [i] = malloc (30);
		strcpy (copia[i], env[i]);
		strcat (copia[i],"\n");
		i++;
	}
	p = fopen (argv[1],"w");
	i = 0;
	while (env[i] != NULL) {
		fputs (copia [i],p);
		i++;
	}
	fclose (p);
}
*/
/*************  Fin programa prog.cpp *****************/
