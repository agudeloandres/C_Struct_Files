#include "stdio.h"
#include "string.h"
#include "conio.h"
#define PR(x) printf ("%s\n",x)

char a[] = "COMPUTADORES E IMPRESORAS";
char *b[] = {
	"DISKETTES",
	"NCR",
	"LUZ",
	"SL",
	"XLK",
};

void main ()  {
	char *p;
	int i;

	for (i=0; i < 5; i++) {
		p = strpbrk (a,b[i]);
		PR(p);
	}
	getch();
}
