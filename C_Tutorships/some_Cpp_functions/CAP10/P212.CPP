#include "stdio.h"
#include "fcntl.h"
#include "conio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#define PRS(x) printf ("%s\n",x)
#define MAX 200  /* Varia de acuerdo al tamano del archivo */

void main() {
	FILE *p;
	char a[20],b[MAX],*q;
	int i,num;
	long pos,pos1;

	randomize();
	if ( (p = fopen ("prueba","r+") ) == NULL) {
		PRS ("Error en apertura\n");
		getch(); exit(1);
	}
	fseek (p,(long)0,SEEK_END);
	fgetpos (p, &pos);
	printf ("Tamano de archivo = %ld. Oprima <R>\n",pos);
	getch();
	i = random (pos-1);
	printf ("Numero aleatorio = %d\n",i);
	fseek (p,(long)i,SEEK_SET);
	fgetpos (p,&pos1);
	printf ("De una cadena. Maximo %d caracteres.\n",pos-pos1-1);
	a[0] = pos-pos1;
	cgets(a);
	printf ("%d %d %s\n",a[0],a[1],a+2);
	putchar('\n');
	fputs (a+2,p);     /* En este lugar se corrio
				el apuntador del archivo */

	if (fsetpos (p,&pos1) !=  0) {     /*   Ubica el apuntador del
						archivo, donde estaba
						antes de escribir la cadena */
		PRS ("Error en fsetpos()");
		getch();
		exit(1);
        }
	q = fgets (b, a[1]+1, p); /* O hasta donde encuentre '\n' */
	*(q + a[1]+1) = '\0';
	printf("La cadena grabada fue : %s\n",b);
	fclose (p);

	/* A continuacion se certifica lo anterior */


	if ( (p = fopen ("prueba","r") ) == NULL) {
		PRS ("Error en apertura\n");
		getch(); exit(1);
	}
        rewind (p);
	q = fgets (a,100,p);
	while (!feof (p) ) {
		i = strlen (a);
		a[i-1] = '\0';
		printf ("%s\n",q);
		q = fgets (a,100,p);
	}
	getch();
}
