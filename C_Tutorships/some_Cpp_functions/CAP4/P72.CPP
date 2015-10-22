#include "stdio.h"
#include "ctype.h"
#include "conio.h"
void main() {
	int i,c;

	c = getch();
	i = toupper (c);
	printf ("%c %c\n",c,i);
	getch();
}
