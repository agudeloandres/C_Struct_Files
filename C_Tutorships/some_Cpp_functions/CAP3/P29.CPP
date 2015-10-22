#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "stdlib.h"
void main ()  {
	char *p,b[20];

	b[0] = 18;
	printf ("De cadena\n");
	cgets(b);
	printf ("\n"); 		/* Para cambiar de linea  */
	p = strchr (b+2,'t');
	if (p==NULL) {
		printf ("\'t\' no esta en la cadena\n");
		getch();
		exit(1);
	}
	printf ("%s\n",p);
	printf ("De cadena\n");
	cgets (b);
	printf ("\n");          /* Para cambiar de linea  */
	p = strchr (b+2,'q');
	if (p==NULL) {
		printf ("\'q\' no esta en la cadena\n");
		getch();
		exit(1);
	}
	printf ("%s\n",p);
	getch();
}
