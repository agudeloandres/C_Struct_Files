#include <stdio.h>
#include <conio.h>
# include <f:\c.h>

main (){

int escaleno(int,int,int);
int isoceles(int,int,int);
int equilatero(int,int,int);
int a,b,c;
clrscr();
printf("teclee 3 valores enteros \n");
scanf("%d%d%d",&a,&b,&c);
if (escaleno(a,b,c)==1)
printf("ESCALENO \n");

if (isoceles(a,b,c)==1)
printf("ISOCELES \n");
if (equilatero(a,b,c)==1)
printf("EQUILATERO \n");
getch();
}
