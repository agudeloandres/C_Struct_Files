#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>

 main()

 {

   char cadena[50],*p;
   int c,d=0,e,f,g,h;

   int j,grado;
   float num1,num2,coef[20],coef1[20],coef2[20];

  ini:
  textcolor(WHITE);
  textbackground(BLUE);
 clrscr();

gotoxy(24,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA\n");
gotoxy(30,4);
printf("TRABAJO DE MATEMATICAS \n");
gotoxy(32,7);
printf("INTEGRANTE :");
gotoxy(18,10);
gotoxy(18,13);
printf("              PETER HANS LORIS LUGO  \n ");
gotoxy(18,18);
printf("              PRESENTADO A: ");
gotoxy(32,20);
printf("    LIC: ALVARO MARRIAGA ");
getch();
clrscr();


 int opcion;
 float A,a,B,b,d1,d2,d3,d4;
 clrscr();
 gotoxy(8,3);
 printf("ESTE PROGRAMA DETERMINA LA ECUACION DIFERENCIAL ASOCIADA\n");
 gotoxy(14,7);
 printf("              PRIMITIVA A RESOLVER\n");

 gotoxy(25,13);
 printf("         POLINOMICA");


 getch();



 textcolor(15);
 textbackground(1);
 clrscr();
 printf("DIGITE EL GRADO DEL POLINOMIO  ");
 scanf("%d",&grado);
 gotoxy(15,4);
 printf("DIGITE ORDENADAMENTE LOS COEFICIENTES DE LA FUNCION");
 for (j=0; j<=grado; j++)
 {
  gotoxy(15,5);
  printf("DIGITE EL COEFICIENTE DE X A LA %d : ",grado-j);
  scanf("%f",&coef[j]);
 }

  gotoxy(15,6);
 printf("LA FUNCION INGRESADA FUE :  " );
 for (j=0; j<=grado; j++)
 {
  printf("%.2f ",coef[j]);
  printf("X^%d ",grado-j);
  }
  gotoxy(15,8);
  printf("DIGITE <ENTER> PARA CONTINUAR ");
  getch();

 clrscr();
  gotoxy(35,2);
 printf("MENU");
  gotoxy(10,8);
 printf("1.    DERIVAR");
  gotoxy(10,14);
 printf("2.    INTEGRAR");
  gotoxy(10,20);
 printf("DIGITE LA OPCION [ ]");
  gotoxy(28,20);
 do
 {
 scanf("%d",&opcion);
 }while((opcion<1)||(opcion>2));
 switch(opcion){

 case 1:

  clrscr();
  for (j=0; j<grado; j++)
  {
   num1=coef[j]*(grado-j);
   coef1[j]=num1;
  }
   gotoxy(30,10);
  printf("LA DERIVADA DE LA FUNCION ES\n ");
  a=0;
  for (j=0; j<grado; j++)
  {
    gotoxy(15+a,12);
   printf("%.2f",coef1[j]);

   printf("X^ %d  ",grado-j-1);

   a+=10;
  }

   break ;

 case 2:
 clrscr();
	/*EN ESTE MOMENTO COMIENZA EL PROCESO DE INTEGRACION*/
  for (j=0; j<=grado; j++)
  {

   num2=coef[j]/(grado-j+1);
   coef2[j]=num2;

  }
  gotoxy(20,10);
   printf("LA INTEGRAL DE LA FUNCION ES");
  for (j=0; j<=grado; j++)
  {
   gotoxy(15+a,12);
   printf("%.2f",coef2[j]);
   printf("X^%d ",grado-j+1);
   a-=10;
  }
  break ;
 }

 getch();
 goto ini;







  getch();
  return(0);
 }


