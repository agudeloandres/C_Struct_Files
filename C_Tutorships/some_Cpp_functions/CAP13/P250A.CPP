#include "stdio.h"
#include "alloc.h"
#include "string.h"
#include "conio.h"

#define PR(x)  printf ("%s\n",x)

void main() {
	int *p;

	p = (int *) malloc (sizeof (int));
	*p = 32767;
	printf ("En la direccion %p del heap, existe el numero %d\n",p,*p);
	getch();
   free (p);  // Libera la memoria indicada por p
}
