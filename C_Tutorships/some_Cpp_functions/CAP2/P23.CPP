#include "stdio.h"
#include "ctype.h"
#include "conio.h"
void main()  {
	int i;

	for (i=0; i <=127; i++)
		if (isxdigit (i))
			printf ("%c  ",i);
	getch();

}



