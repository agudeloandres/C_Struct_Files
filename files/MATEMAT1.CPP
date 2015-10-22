#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
//#include<graphics.h>


struct tipo{
     struct tipo *a;
     char ch;
     struct tipo *b;
  }inicio,*ap;

 main()
 {
  textcolor(01);
  textbackground(003);
 clrscr();

   char cadena[50],*p;
   int c,d=0,e,f,g,h;
//  graphics(3,78,4,24);
//  graphics(7,73,7,21);
gotoxy(24,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA\n");
gotoxy(30,4);
printf("TRABAJO DE MATEMATICAS \n");
gotoxy(32,7);
printf("INTEGRANTES :");
gotoxy(18,10);
printf("  ...................ASTRID CARRASQUILLA          ");
gotoxy(18,12);
printf("  ...................SANDRA GOMEZ            ");
gotoxy(18,14);
printf("  ...................BELKIS CUCUNUBA          ");
gotoxy(18,16);
printf("  ...................ALEJADRA MONERI         ");
gotoxy(18,18);
printf("  ...................SILAK DEL TORO         ");
gotoxy(18,20);
printf("  ...................MILENA TORRES         ");
gotoxy(18,22);
printf("  ...................ANA MARIA VAN-LEENDEN ");
gotoxy(18,24);
printf("  PRESENTADO A: ");
gotoxy(32,24);
printf("   LIC: ALVARO MARRIAGA ");
getch();
clrscr();
gotoxy(24,2);
printf("UNIVERSIDAD COOPERATIVA DE COLOMBIA\n");
gotoxy(30,4);
printf("TRABAJO DE MATEMATICAS \n");
gotoxy(32,7);
printf("INTEGRANTES :");
gotoxy(18,10);
printf("  KARINA ACOSTA          COD:5971004 ");
gotoxy(18,12);
printf("  LUIS BORREGO           COD:5971012 ");
gotoxy(18,14);
printf("  ISMEL CERCHAR          COD:5971018 ");
gotoxy(18,16);
printf("  INGRID ESCOBAR         COD:5971026 ");
gotoxy(18,18);
printf("  MAYERLY LOZANO         COD:5971034 ");
gotoxy(18,21);
printf("  PRESENTADO A: ");
gotoxy(32,21);
printf("   LIC: ALVARO MARRIAGA ");
gotoxy(30,23);
printf("DIGITE <ENTER> PARA CONTINUAR");
getch();

 int opcion;
 float A,a,B,b,d1,d2,d3,d4;
 clrscr();
 gotoxy(8,3);
 printf("ESTE PROGRAMA DETERMINA LA ECUACION DIFERENCIAL ASOCIADA\n");
 gotoxy(14,7);
 printf("ESCOJA EL TIPO DE PRIMITIVA A DESARROLLAR\n");

 do
 {
 gotoxy(25,10);
 printf("1.         TRIGONOMETRICA");
 gotoxy(25,13);
 printf("2.         EXPONENCIAL");
 gotoxy(25,16);
 printf("3.         POLINOMICA");
// gotoxy(25,19);
// printf("4.         MIXTA");
 gotoxy(25,23);
 printf("DIGITE LA OPCION [ ]");
 gotoxy(43,23);
 scanf("%d",&opcion);
 }while((opcion<1)||(opcion>3));
 switch(opcion){
  case 1:
  clrscr();
   gotoxy(2,2);
   printf(" y= Acos ax + Bsen bx");
   gotoxy(2,4);
   printf(" DIGITE UNO A UNO LOS COEFICIENTES");
   gotoxy(2,6);
   printf(" y= (   )cos (  )x + (  )sen (  )x");
   gotoxy(7,6);
   scanf("%f",&A);
   gotoxy(16,6);
   scanf("%f",&a);
   gotoxy(24,6);
   scanf("%f",&B);
   gotoxy(32,6);
   scanf("%f",&b);
   gotoxy(2,8);
   printf("LAS DERIVADAS DEL PROCESO SON:");
   d1=A*a;
   d2=B*b;
   gotoxy(2,10);
   printf("-%.1f sen %.1f x + %.1f cos %.1f x",d1,a,d2,b);
   d3=a*d1;
   d4=b*d2;
   gotoxy(2,12);
   printf("-%.1f cos %.1f x - %.1f sen %.1f x",d3,a,d4,b);
   gotoxy(2,14);
   printf("DADO QUE LA SEGUNDA DERIVADA TIENE LA FORMA:");
   gotoxy(2,16);
   printf("-(%.1f)^2 (%.1f cos %.1f x + %.1f sen %.1f x)",a,A,a,B,b);
   gotoxy(2,18);
   printf("LO QUE EQUIVALE A:");
   printf("-(%.1f)y",a);
   gotoxy(2,20);
   printf("LO CUAL DEMUESTRA QUE LA ECUACION INGRESADA...");
   gotoxy(2,22);
   printf("(dy/dx)^2 + (%.1f)^2 y = 0",a);
   gotoxy(2,24);
   printf("FUE PERFECTAMENTE RESUELTA\n");
   getch();
   break;
  case 2:

	    int i,num,opc,exp[10];
 float dato1,dato2,fact[10],fact1[10],fact2[10];

 textcolor(1);
 textbackground(11);
 clrscr();
 gotoxy(2,2);
 printf("DIGITE EL NUMERO DE TERMINOS DE LA ECUACION: ");
 scanf("%d",&num);
 for (i=0; i<num; i++)
 {
 gotoxy(2,4);
  printf("DIGITE EL COEFICIENTE NUMERO %d: ",i+1);
  scanf("%f",&fact[i]);
  gotoxy(2,6);
  printf("DIGITE EL EXPONENTE DE EULER: ");
  scanf("%d",&exp[i]);
 }
 for (i=0; i<num; i++)
 {

  gotoxy(2,8);
  printf("+");
  printf("(%.2f)*(e^%dX)",fact[i],exp[i]);

 }
 gotoxy(2,10);
  printf("DIGITE <ENTER> PARA SEGUIR");
  getch();
  //clrscr();
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
 clrscr();
 gotoxy(28,20);
 scanf("%d",&opc);
 }while((opc<1)||(opc>2));
 switch(opc){
 case 1:
  for (i=0; i<num; i++)
  {
   dato1=fact[i]*exp[i];
   fact1[i]=dato1;
  }
  for (i=0; i<num; i++)
  {
   if (exp[i]!=0)
   {
    printf("+");
    printf("(%.2f)*(e^%dX)",fact1[i],exp[i]);
   }
  }
 break;
 case 2:
  for (i=0; i<num; i++)
  {
   dato2=fact[i]/exp[i];
   fact2[i]=dato2;
  }
  for (i=0; i<num; i++)
  {
   if (exp[i]!=0)
   {
   printf("+");
   printf("(%.2f)*(e^%dX)",fact2[i],exp[i]);
   }
   if (exp[i]==0)
   {
    printf("+");
    printf("%.2f*X",fact[i]);
   }
  }
 break;
}
///////////////////////////////////////////////////////////////////////////////
case 3:
      int j,grado,opcion,a;
 float num1,num2,coef[20],coef1[20],coef2[20];

 textcolor(1);
 textbackground(11);
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
 I:
 case 1:
	   /*EN ESTE MOMENTO COMIENZA EL PROCESO DE DERIVACION*/
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
    gotoxy(30+a,12);
   printf("%.2f",coef1[j]);

   printf("X^ %d  ",grado-j-1);

   a+=10;
  }
   //gotoxy(38,12);
   //printf("+");
   //gotoxy(15,4);
   break ;
  // goto I;
 case 2:
 clrscr();
	/*EN ESTE MOMENTO COMIENZA EL PROCESO DE INTEGRACION*/
  for (j=0; j<=grado; j++)
  {

   num2=coef[j]/(grado-j+1);
   coef2[j]=num2;

  }
  gotoxy(30,10);
   printf("LA INTEGRAL DE LA FUNCION ES");
  for (j=0; j<=grado; j++)
  {
   gotoxy(30+a,12);
   printf("%.2f",coef2[j]);
   printf("X^%d ",grado-j+1);
   a-=10;
  }
  break ;
 }

 getch();
// return(0);
}






  getch();
  return(0);
 }


