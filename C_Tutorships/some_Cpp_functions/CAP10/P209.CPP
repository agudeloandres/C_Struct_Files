#include "stdio.h"
#include "fcntl.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x) printf ("%s\n",x)

void main() {
	FILE *p;
	long pos;
	char c;
	int i;
	int lea_entero() ;

	if ( (p = fopen ("prueba","r+") ) == NULL) {   /* Para actualizar */
		PRS ("Error en apertura\n");
		getch(); exit(1);
	}
	pos = fseek (p,(long)0,SEEK_END);  /* Ubica el apuntador
						al final del archivo */
	fgetpos(p,&pos);
	PRS("De posicion del caracter a modificar");
	printf ("Rango 0-%d\n",pos-1);
	i = lea_entero();
	while (i >=0 && i < pos) {
		fseek (p,(long)i,SEEK_SET);
		PRS("De nuevo caracter");
		c = getche();getch();putchar('\n');
		fputc (c,p);
                PRS("De posicion del caracter a modificar");
		printf ("Rango 0-%d\n",pos-1);
		i = lea_entero();
	}
	rewind(p);
	c = fgetc(p);
	while (!feof(p)) {
		printf ("%c",c);
		c = fgetc(p);
	}
	getch();
}

int lea_entero() {
	char a[10];gets(a);return (atoi(a));
}