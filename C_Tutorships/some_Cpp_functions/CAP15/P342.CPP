#include "dos.h"
#include "conio.h"
#include "stdlib.h"
#include "stdio.h"
void main() {
	struct dfree p;
	char a[10];

	printf ("De unidad a investigar\n");
	gets (a);
	getdfree (atoi (a), &p);
	if (p.df_sclus == 0xffff ) {	/* No puede ser -1 */
		printf ("%s\n","Error en getdfree()\n");
		getch();
		exit(1);
	}
	printf ("Clusters disponibles		=  %u\n",p.df_avail);
	printf ("Numero de clusters  		=  %u\n",p.df_total);
	printf ("Bytes por sector    		=  %u\n",p.df_bsec);
	printf ("Sectores por cluster		=  %u\n",p.df_sclus);
	printf ("Espacio disponible = %lu\n",
		(long) p.df_avail * (long) p.df_sclus * (long) p.df_bsec);
	getch();
}
