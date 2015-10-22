#include "stdio.h"
#include "dir.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

#define PRS(x)  printf ("%s",x)
#define SALTO  printf ("\n")

void main() {
	char a [MAXPATH];		/* MAXPATH =  80 */
	char b [MAXPATH];
	char unidad [MAXDRIVE];         /* MAXDRIVE =  3 */
	char directorio [MAXDIR];       /* MAXDIR = 66 */
	char nombre [MAXFILE];		/* MAXFILE =   9 */
	char extension [MAXEXT];        /* MAXEXT =    5 */
	int i;

	strcpy (unidad,"c:");
	strcpy (directorio,"turboc\\work\\");
	strcpy (nombre,"cap1115");
	strcpy (extension,".c");
	fnmerge (a, unidad, directorio, nombre, extension);
	strcpy (unidad,"\0");
	strcpy (directorio,"\0");
	strcpy (nombre,"\0");
	strcpy (extension,"\0");
	i=fnsplit (a,unidad,directorio,nombre,extension);
	fnmerge (b, unidad, directorio, nombre, extension);
	if (strcmp (a,b) == 0) {
		PRS ("Correcto");
		SALTO;
	}
	else {
		PRS ("No puede ser");
		SALTO;
	}
	printf ("\n%d\n",i);
	getch();
}


