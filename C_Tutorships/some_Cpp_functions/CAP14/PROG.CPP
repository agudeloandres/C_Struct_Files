
/*************  Programa prog.cpp *****************/

#include "stdio.h"
#include "process.h"
#include "alloc.h"
#include "conio.h"
#include "stdlib.h"
#include "string .h"
#include "alloc.h"
void main(int argc, char *argv[], char *env[]) {
	int i,j;
	FILE *p;
	char *copia[10];
	printf ("%d Parametros\n",argc);
	i = 0;
	while (env[i] != NULL) {
		copia [i] = (char *)malloc (30);
		strcpy (copia[i], env[i]);
		strcat (copia[i],"\n");
		i++;
	}
	p = fopen (argv[1],"w");
	i = 0;
	while (env[i] != NULL) {
		fputs (copia [i],p);
		printf ("%s\n",copia[i]);
		free (copia[i]);
		i++;
	}
	fclose (p);
}

/*************  Fin programa prog.cpp *****************/
