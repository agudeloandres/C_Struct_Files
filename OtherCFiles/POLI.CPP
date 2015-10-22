#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
textbackground(6);textcolor(7);
float Wi,Wh,pi=3.141596,Ang;
int Grado,F,X;
char a,c;
do{
clrscr();
gotoxy(31,3);puts("TRABAJO DE FISICA");
gotoxy(20,10);printf("1  PLANO INCLINADO ");putchar(17);
gotoxy(20,12);printf("2  PLANO HORIZONTAL ");putchar(17);
gotoxy(20,14);printf("3  SALIR ");putchar(17);
c=getch();
a=c;
switch(a){
case '1':
{
clrscr();
	gotoxy(31,3);puts("TRABAJO DE FISICA \n\n");

	gotoxy(1,6); printf("Digite el valor de la fuerza: ");
		 scanf("%d",&F);gotoxy(34,6);printf(" New.");

	gotoxy(1,8); printf("Digite el valor del espacio: ");
		 scanf("%d",&X);gotoxy(33,8);printf("mts.");

	gotoxy(1,10); printf("Digite el valor del angulo: ");
		 scanf("%d",&Grado);gotoxy(31,10);printf("§");
				 Ang=(Grado*pi)/180;
				 Wi=(F*cos(Ang))*X;
	gotoxy(1,12);printf("El trabajo realizado es:%.2f	 Julios",Wi);
			  getch();break;
}
case'2':
{
clrscr();
	gotoxy(31,3);puts("TRABAJO DE FISICA \n\n");
	gotoxy(1,6);printf("Digite el valor de la fuerza: ");
		scanf("%d",&F);gotoxy(34,6);printf(" Nwt");

	gotoxy(1,8); printf("Digite el valor del espacio: ");
		scanf("%d",&X);gotoxy(33,8);printf("mts");
				Wh=F*X;
	gotoxy(1,10);printf("El trabajo realizado es:%.0f Julios",Wh);
getch();break;
}
}
}
while(a!='3');
}