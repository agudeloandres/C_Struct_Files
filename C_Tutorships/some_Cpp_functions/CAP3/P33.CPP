#include "stdio.h"
#include "string.h"
#define PR(x) printf ("%s\n",x)
#include "conio.h"
char *a[] = {
	"Doscientos",
	"TREScienTOS",
	"Cuatrocientos",
	"QuInIeNtOs"
};

void main ()  {
	int i;

	for (i=0; i < 4; i++)
		strupr (a[i]);
	for (i=0; i < 4; i++)
		PR (a[i]);
	getch();
}
