#include <stdio.h>
#include <conio.h>
#include <dos.h>
main ()

{
int a,b,d,t,j,H;



textcolor(4);
textbackground(11);
clrscr();
for(t=1;t<=30;t++){
gotoxy(t,1);printf(" PROGRAMA DE LA POTENCIACION");
delay(80);
}
gotoxy(1,3);printf("ESCRIBA LA BASE : ");
scanf("%d",&a);
gotoxy(1,5);printf("ESCRIBA EL EXPONENTE : " );
scanf("%d",&b);

d=1;
for (j=1;j<=b;j++){

d*=a;

}

H=1;
for (j=1;j<=a;j++){
H*=b;
}

gotoxy(1,7);printf("%d ELEVADO A LA %d ES IGUAL A : %d \n",a,b,d);
gotoxy(1,9);printf("%d ELEVADO A LA %d ES IGUAL A : %d \n ",b,a,H);

getch();
}