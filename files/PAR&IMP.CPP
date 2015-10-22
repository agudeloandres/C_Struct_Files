#include <stdio.h>
#include <conio.h>
#include <dos.h>
main ()
{
int a,b ,c ,d ,p,x,h ;
textcolor (4);
textbackground(11);
clrscr();

p=0;h=0;
printf("digite 4 numeros \n");


for (x=1;x<=4;x++)

{
scanf("%d",&a);
if(a%2==0)
p++;

else
h++;
}
printf("La cantidad de pares es : %d\n",p);
printf("la cantidad de impares es %d\n",h);
getch();
}