#include "stdio.h"
#include "dir.h"
#include "conio.h"
#include "stdlib.h"

#define PRS(x)  printf ("%s",x)
#define SALTO  printf ("\n")

void main() {
       int i,d;

       d = 0;
		 i = setdisk(d);
       printf ("Unidades disponibles = %d\n",i);
       getch();
}


