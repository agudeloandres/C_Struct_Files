#include "io.h"
#include "stdio.h"
#include "errno.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x) printf ("%s\n",x)


void main() {
	int i;
	char a[30];

	PRS ("De nombre del archivo a examinar");
	gets (a);
	i = access (a,0);
	if (i == 0)
		if (access (a,6) == 0)
			PRS ("Correcto! se puede actualizar");
		else if (access(a,4) == 0)
			PRS ("Solamente es para leer");
		else if (access (a,2) == 0)
			PRS ("Solamente es para escribir");
		else PRS ("Error");
	else PRS("EL archivo no existe");
	getch();
}