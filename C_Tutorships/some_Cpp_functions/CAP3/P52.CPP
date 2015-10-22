#include "stdio.h"
#include "conio.h"
#include "string.h"
#define PRC(x,y) printf ("La cadena hasta el caracter %2d, esta\
 formada por %s\n",x,y)

char a[] = "LIBROS, CUADERNOS Y LAPICES";
char *b[] = {
	"CU ALBIROS,",
	"LBIRU,S CUAP",
	"LBI",
	"LBIRU,S YCUAP",
	"DORES",
};

void main ()  {
	int i,j;

	for (i=0; i < 5; i++) {
		j = strspn (a,b[i]);
		PRC(j,b[i]);
	}
	getch();
}
