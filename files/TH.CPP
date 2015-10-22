# include <stdio.h>
# include <conio.h>
# include "f:\hanoi.h"
void postes(int, int, int, int);
main()
{
textbackground(11);
textcolor(9);
clrscr();
int c;
printf("DIGITE LA CANTIDAD DE DISCOS QUE DESEA MOVER:  ");
scanf("%d",&c);
 postes (c,1,2,3);
getch();

}
