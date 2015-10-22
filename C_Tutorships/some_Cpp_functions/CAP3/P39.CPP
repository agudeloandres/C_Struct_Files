#include "stdio.h"
#include "string.h"
#define PR(x) printf ("%s\n",x)
#include "conio.h"
void main ()  {
	char a[30],b[30];
	size_t i;     // size_t esta declarada como unsigned int

	PR("De cadena a[]");
	gets (a);
	PR("De cadena b[]");
	gets (b);
	i = strcspn (a,b);
	printf ("%d\n",i);
	getch();
}



