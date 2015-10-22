#include "stdio.h"
#include "ctype.h"
#include "conio.h"
void main() {
	int i,c;

	c = getch();
	i = tolower(c);
	printf ("%c %c\n",c,i);
	getch();
}
