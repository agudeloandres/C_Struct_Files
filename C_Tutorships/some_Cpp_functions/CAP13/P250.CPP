#include "stdio.h"
#include "alloc.h"
#include "string.h"
#include "conio.h"
#include "stdlib.h"
#define PR(x)  printf ("%s\n",x)

void main() {
	char *p,*q;

	p = (char *)malloc (20);  /* Devuelve una direccion de memoria */
										/* Se debe hacer un (molde) para con-
											vertirla a direccion a char */
	if (p==NULL) {
		printf ("No existe memoria disponible\n");
		getch();
		exit (1);
	}
	strcpy (p,"MEMORIA");
	q = strcat (p," DINAMICA");
	PR(q);
	getch();
	free (p);  // Libera la memoria
}
