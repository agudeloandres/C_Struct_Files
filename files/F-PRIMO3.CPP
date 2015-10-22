#include <stdio.h>
#include <conio.h>
#include <dos.h>
main ()
{
textbackground(11);
textcolor(4);
clrscr();
int n,counter=0;
int primo (int);//prototipo
printf("LOS PRIMOS DE 1 AL 10000 SON :");
for(n=1;n<=10000;n++){
if (primo(n)){
printf("\t%d",n);
counter++;
}
}
printf("\n\tLA CANTIDAD DE PRIMOS DE 1 A 10000 ES : %d ",counter);
getch();
}

int primo (int x){
int i;
for (i=2;i<x;i++)
if (x%i==0)
return 0;  //CUANDO NO ES PRIMO
return 1; //CUANDO ES PRIMO
}