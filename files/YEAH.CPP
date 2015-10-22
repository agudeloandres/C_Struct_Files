#include<stdio.h>
#include<conio.h>
#include<dos.h>
main(){
int x,par=0,positivo=0,c;
i:
clrscr();

for(c=0;c<=41;c++){
textbackground(c);
clrscr();
delay(150);
}


textcolor(4);
printf("TECLEE UN VALOR....\n\a");
scanf("%d",&x);
if (!(x%2))
par++;
if (x>0)
positivo++;
if (par)
 printf("PAR\n");
 else
 printf("IMPAR\n");

if (positivo)
 printf("POSITIVO\n");
 else
  printf("NEGATIVO\n");
 getch();
 goto i;
 }