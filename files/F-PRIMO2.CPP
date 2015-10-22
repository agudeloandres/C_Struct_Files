#include <stdio.h>
#include <conio.h>
#include <dos.h>
main ()
{
textbackground(11);
textcolor(4);
clrscr();

int n;
int primo (int);//prototipo
printf ("DIGITE UN NUMERO ENTERO \n");
scanf("%d",&n);
if (primo(n))
printf ("ES PRIMO");
else printf("NO ES PRIMO");
getch();
}

int primo (int x){
int i;
for (i=2;i<x;i++)
if (x%i==0)
return 0;  //CUANDO NO ES PRIMO
return 1; //CUANDO ES PRIMO
}