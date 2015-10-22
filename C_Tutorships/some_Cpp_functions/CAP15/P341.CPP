#include "dos.h"
#include "conio.h"
#include "stdio.h"
void main () {
	int i,j = 0;
	textbackground (BLACK);
   clrscr();

	i = setcbrk (j);
	i = getcbrk();
	if (i != 0)
		printf ("Error\n");
	getch();
}