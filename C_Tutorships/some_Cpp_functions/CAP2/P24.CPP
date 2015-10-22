#include "stdio.h"
#include "ctype.h"
#include "conio.h"
void main()  {
	int i,conlin=0;


	for (i=0; i <=127; i++) {
		if (conlin == 23) {
			printf ("Oprima <R>\n");
			getch();
			conlin = 0;
		}
		conlin++;
		if (isprint(i))
			printf ("Si %c\n",i);
		else printf ("No %d\n",i);
	}
	getch();

}



