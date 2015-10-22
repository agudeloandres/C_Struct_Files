#include <stdio.h>
#include <conio.h>
main ()
{
int x,y,h,i,j;
agin:
textcolor(2);
textbackground(0);
clrscr();
printf("entre altura (max. 10) " );
scanf("%d",&h);
if (h<=10)
for (x=1;x<=h;++x){
for (y=1;y<=x;++y)

printf("* ");
printf("\n");
}
getch();
clrscr();
if (h<=10)
for (x=h;x!=0;x--){
for (y=1;y<=x;y++)
printf("* ");
printf("\n");
}
getch();
clrscr();
if (h<=10)
for (i=1;i<=h;i++)
{
gotoxy(1*-2+25,i+2);
for (j=1;j<=1;++j)
printf("* ");
printf("\n");
}
getch();
clrscr();
if (h<=10)
for (x=1;x<=h;++x){
for (y=1;y<=x;++y){
gotoxy(2*x,1*y);
printf("*");
printf("\n");
}
}
getch();
goto agin ;
}
