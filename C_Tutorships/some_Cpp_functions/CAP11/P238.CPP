#include "stdio.h"
#include "dir.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

#define PRS(x)  printf ("%s",x)
#define SALTO  printf ("\n")

void main() {
	char a [MAXPATH];		/* MAXPATH =  80 */
	char unidad [MAXDRIVE];         /* MAXDRIVE =  3 */
	char directorio [MAXDIR];       /* MAXDRIVE = 66 */
	char nombre [MAXFILE];		/* MAXFILE =   9 */
	char extension [MAXEXT];        /* MAXEXT =    5 */

	strcpy (unidad,"c:");
	strcpy (directorio,"turboc\\work\\");
	strcpy (nombre,"cap1115");
	strcpy (extension,".c");
	fnmerge (a, unidad, directorio, nombre, extension);
	PRS (a);
	getch();
}


