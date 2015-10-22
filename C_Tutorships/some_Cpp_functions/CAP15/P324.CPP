#include "stdio.h"
#include "dos.h"
#include "errno.h"
#include "conio.h"

void main() {
	FILE *q;
	struct DOSERROR p;

	q = fopen ("a:noexiste.dik","r");   /* Supongamos que no existe */
	if (q == NULL)
		printf ("%s\n",strerror (errno));
	/* Para conseguir mas informacion del error.... */
	dosexterr (&p);
	printf ("Codigo error	        = %d\n",p.de_exterror);
	printf ("Clase del error        = %d\n",p.de_class);
	printf ("Accion sugerida        = %d\n",p.de_action);
	printf ("Localizacion del error = %d\n",p.de_locus);
	getch();
}


