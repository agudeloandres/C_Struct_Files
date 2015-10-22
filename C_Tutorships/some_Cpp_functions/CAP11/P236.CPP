#include "stdio.h"
#include "dir.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

#define PRS(x)  printf ("%s",x)
#define SALTO  printf ("\n")

void main(int argc,char *argv[]) {
	char a [MAXPATH];		/* MAXPATH =  80 */
	char unidad [MAXDRIVE];         /* MAXDRIVE =  3 */
	char directorio [MAXDIR];       /* MAXDIR = 66 */
	char nombre [MAXFILE];		/* MAXFILE =   9 */
	char extension [MAXEXT];        /* MAXEXT =    5 */

	int i;

	if (argc != 2) {
		PRS("Error en la linea de comandos");
		SALTO;
		getch();
		exit (1);
	}
	strcpy (a,argv[1]);
	i = fnsplit (a, unidad, directorio, nombre, extension);
	if (i & DRIVE) {
		PRS (unidad);
		SALTO;
	}
	if (i & DIRECTORY) {
		PRS (directorio);
		SALTO;
	}
	if (i & FILENAME) {
		PRS (nombre);
		SALTO;
	}
	if (i & EXTENSION) {
		PRS (extension);
		SALTO;
	}
	getch();
}


