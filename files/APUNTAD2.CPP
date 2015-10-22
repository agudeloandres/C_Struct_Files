#include <stdio.h>
#include <conio.h>
main (){
clrscr();
int i,j=25;
int *pi,*pj=&j;
*pj = j+5;
i = *pj +5;
pi=pj;
*pi=i+j;

printf("El valor de i es %d\n",i);
printf ("El valor de &i es  %lu\n",&i);
printf ("El valor de &j es  %lu\n",&j);
printf ("El valor de pi es  %lu\n",pi);
printf ("El valor de pj es  %lu\n",pj);
printf ("El valor de *pi es %d\n",*pi);
printf ("El valor de *pj es %d\n",*pj);
printf ("El valor de (pi+2) es  %lu\n",pi+2);
printf ("El valor de *pi+2 es %d\n",*pi+2);
printf("El valor de *(pi+2) es %d\n",*(pi+2));

getch();
}
