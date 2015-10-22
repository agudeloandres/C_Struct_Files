//TRABAJO REALIZADO POR FABIO GUTIERREZ COD:5971076//
//PRESANTADO A JUAN PABLO LLINAS//
//MATERIA==> FISICA Y LABORATORIO 1//
//TEMAS==> MOV.RECTILINEO--MOV.EN EL PLANO--LEYES DE NEWTON--POTENCIA--TRABAJO--FUERZA--ENERGIA//


#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <iostream.h>
#include <string.h>
#include <stdlib.h>
  void trabajo();
  void fuerza();
  void energia();
  void  energia_cinetica();
  void  energia_potencial();
  int instructions(void);

main ()
{
int sw,lon;

int  choice,est,i,cdel,k,y,p;
char name[30];
float not1,not2,prom,cod;
clrscr();
while((choice = instructions()) != 5  ){
     switch(choice){

	  case 1:
		trabajo();
		break;

	 case 2:
		fuerza();
		break;
	 case 3:
		energia_cinetica();
		break;
	 case 4:
		energia_potencial();
		break;

	   default:
		printf(" Invalid choice.\n\n");
		break;
	     }

	     }
     return 0;
     }

int instructions(void)
{
clrscr();
textbackground(1);
    int k,y,p;

     gotoxy(4,1); printf("É\n");
     gotoxy(74,1);printf("»\n");
     gotoxy(4,23);printf("È\n");
     gotoxy(74,23);printf("¼\n");

    for (k= 5; k<= 73; k ++)
  {gotoxy (k,y);
   gotoxy(k,1);printf("Í\n");
   gotoxy (k,23);printf("Í\n");
  }

   for (p=2; p<=22; p++)
  {
    gotoxy (4,p);printf("º\n");
   gotoxy (74,p);printf("º\n");
    }

int op;
char c[80];
gotoxy(25,4);
printf("  M E N U   P R I N C I P A L ");
printf("\n\n");
gotoxy(20,8);
printf(" 1  MOVIMIENTO RECTILINEO \n");
gotoxy(20,10);
printf(" 2  MOVIMIENTO EN EL PLANO\n");
gotoxy(20,12);
printf(" 3  APLICACION DE LAS LEYES DE NEWTON \n");
gotoxy(20,14);
printf(" 4  FUERZA - ENERGIA - TRABAJO - POTENCIA\n");
gotoxy(20,16);
printf(" 5  SALIR\n");
gotoxy(20,20);
printf("enter option [ ]");
gotoxy(34,20);
gets(c);
op = atoi(c);
return op;
}

void trabajo()
{
clrscr();
int k,y,p,op;
char c[80];
float espacio1,espacio,espacio2,tiempo1,tiempo2,tiempo,x,t,v1,v2,t1,t2,v;
do{
clrscr();

     gotoxy(4,1); printf("É\n");
     gotoxy(74,1);printf("»\n");
     gotoxy(4,23);printf("È\n");
     gotoxy(74,23);printf("¼\n");

    for (k= 5; k<= 73; k ++)
  {gotoxy (k,y);
   gotoxy(k,1);printf("Í\n");
   gotoxy (k,23);printf("Í\n");
  }

   for (p=2; p<=22; p++)
  {
    gotoxy (4,p);printf("º\n");
   gotoxy (74,p);printf("º\n");
    }


gotoxy(26,2);
printf("-----S U B  M E N U  ------");
gotoxy(27,4);
printf("  MOVIMIENTO RECTILINEO ");
printf("\n\n");
gotoxy(20,6);
printf(" 1  REPIDEZ MEDIA \n");
gotoxy(20,8);
printf(" 2  VELOCIDAD MEDIA\n");
gotoxy(20,10);
printf(" 3  VELOCIDAD INSTANTANEA\n");
gotoxy(20,12);
printf(" 4  ACELERACION MEDIA\n");
gotoxy(20,14);
printf(" 5  ACELERACION INSTANTANEA\n");
gotoxy(20,16);
printf(" 6  ACELERACION CONSTANTE\n");

gotoxy(20,18);
printf(" 7  SALIR\n");
gotoxy(20,20);
printf("enter option [ ]");
gotoxy(34,20);
gets(c);
op = atoi(c);


      if(op == 1){
		clrscr();
		gotoxy(30,4);
		printf("  MOVIMIENTO RECTILINEO ");
		gotoxy(31,5);
		printf(" ------------------------");

		printf("\n\n\n");
		printf("             distancia total recorrida \n ");
		printf(" rapidez = ---------------------------- \n");
		printf("              intervalo de tiempo    \n ");
		printf("\n\n\n");
		printf("            distancia =     \n ");
		printf(" rapidez = --------------- \n");
		printf("            tiempo    =     \n ");

		gotoxy(25,14);
		scanf("%f",&espacio);
		gotoxy(25,16);
		scanf("%f",&tiempo);
		gotoxy(45,15);
		printf(" rapidez  media ==> %1.2f ",(espacio/tiempo));
		getch();
	     }

    if(op == 2){
		clrscr();
		gotoxy(30,4);
		printf("  MOVIMIENTO RECTILINEO ");
		gotoxy(31,5);
		printf(" ------------------------");

		printf("\n\n\n");
		printf("                       desplazamiento \n ");
		printf(" velocidad media  = --------------------- \n");
		printf("                     intervalo de tiempo    \n ");
		printf("\n\n\n");
		printf("                      X2=      -  X1 =     \n ");
		printf(" velocidad media = ----------------------- \n");
		printf("                       T2=     - T1 =     \n ");

		gotoxy(27,14);
		scanf("%f",&espacio2);
		gotoxy(40,14);
		scanf("%f",&espacio1);

		gotoxy(27,16);
		scanf("%f",&tiempo2);
		gotoxy(40,16);
		scanf("%f",&tiempo1);
		gotoxy(15,18);
		printf("velocidad  media ==> %1.2f  m/s ",((espacio2-espacio1)/(tiempo2-tiempo1)));
		getch();
	     }
      if(op==3){

		clrscr();
		gotoxy(30,4);
		printf("  MOVIMIENTO RECTILINEO ");
		gotoxy(31,5);
		printf(" ------------------------");

		printf("\n\n\n");
		printf("                     variacion del espacio   \n ");
		printf(" velocidad inst  = -------------------------- \n");
		printf("                     varicion del tiempo    \n ");
		printf("\n\n\n");
		printf("                      X=     \n ");
		printf(" velocidad inst = ----------- \n");
		printf("                      T=    \n ");

		gotoxy(27,14);
		scanf("%f",&x);

		gotoxy(27,16);
		scanf("%f",&t);
		gotoxy(15,18);
		printf("velocidad  instantanea ==> %1.2f  m/s ",x/t);
		getch();
	     }
	     if(op == 4){
		clrscr();
		gotoxy(30,4);
		printf("  MOVIMIENTO RECTILINEO ");
		gotoxy(31,5);
		printf(" ------------------------");
		printf("\n\n\n");
		printf("                     variacion de la veloc   V     \n");
		printf(" aceleracion media = -------------------- = ----      \n");
		printf("                     variacion del tiempo    t     \n ");
		printf("\n\n\n");
		printf("                      V2=      -  V1 =     \n ");
		printf(" aceleracion media = ----------------------- \n");
		printf("                       T2=     - T1 =     \n ");
		gotoxy(27,14);
		scanf("%f",&v2);
		gotoxy(40,14);
		scanf("%f",&v1);

		gotoxy(27,16);
		scanf("%f",&t2);
		gotoxy(40,16);
		scanf("%f",&t1);
		gotoxy(15,18);
		printf("aceleracion  media ==> %1.2f  m/sý ",((v2-v1)/(t2-t1)));
		getch();
	     }
	     if(op==5){

		clrscr();
		gotoxy(30,4);
		printf("  MOVIMIENTO RECTILINEO ");
		gotoxy(31,5);
		printf(" ------------------------");

		printf("\n\n\n");
		printf("                     variacion de la Veloc    dV     \n ");
		printf(" aceleracion inst  = -----------------------= ---    \n");
		printf("                     varicion del tiempo      dt     \n ");
		printf("\n\n\n");
		printf("                      V=     \n ");
		printf(" aceleracion inst = ------------ \n");
		printf("                      T=    \n ");

		gotoxy(27,14);
		scanf("%f",&v);

		gotoxy(27,16);
		scanf("%f",&t);
		gotoxy(15,18);
		printf("aceleracion instantanea ==> %1.2f  m/s ",v/t);
		getch();
	     }
	    if(op == 6){
	      printf(" no terminado ");
	      getch();
	      }




}while(op > 0 && op <7);
}
void fuerza()
{
textbackground(15);
textcolor(0);
int k,y,p;
clrscr();

     gotoxy(4,1); printf("É\n");
     gotoxy(74,1);printf("»\n");
     gotoxy(4,23);printf("È\n");
     gotoxy(74,23);printf("¼\n");

    for (k= 5; k<= 73; k ++)
  {gotoxy (k,y);
   gotoxy(k,1);printf("Í\n");
   gotoxy (k,23);printf("Í\n");
  }

   for (p=2; p<=22; p++)
  {
    gotoxy (4,p);printf("º\n");
   gotoxy (74,p);printf("º\n");
    }
gotoxy(29,2);
gotoxy(26,2);
printf("-----S U B  M E N U  ------");
gotoxy(27,4);
printf("  MOVIMIENTO PLANO ");
printf("\n\n");
gotoxy(20,6);
printf(" 1  VELOCIDAD  \n");
gotoxy(20,8);
printf(" 2  ACELERACION\n");
gotoxy(20,10);
printf(" 3  ACELERACION CONSTANTE\n");
gotoxy(20,12);
printf(" 4  SALIR\n");
gotoxy(20,14);
printf("enter option [ ]");
gotoxy(34,14);

getch();
}

void energia_cinetica()
{
clrscr();
textbackground(18);
textcolor(0);
int k,y,p;
clrscr();

     gotoxy(4,1); printf("É\n");
     gotoxy(74,1);printf("»\n");
     gotoxy(4,23);printf("È\n");
     gotoxy(74,23);printf("¼\n");

    for (k= 5; k<= 73; k ++)
  {gotoxy (k,y);
   gotoxy(k,1);printf("Í\n");
   gotoxy (k,23);printf("Í\n");
  }

   for (p=2; p<=22; p++)
  {
    gotoxy (4,p);printf("º\n");
   gotoxy (74,p);printf("º\n");
    }
gotoxy(29,2);
gotoxy(22,2);
printf("  APLICACION DE LA LEY DE NEWTON ");
gotoxy(27,4);
printf("  S U B  M E N U ");
printf("\n\n");
gotoxy(20,6);
printf(" 1  FRICCION  \n");
gotoxy(20,8);
printf(" 2  FUERZAS DE RESISTENCIAS\n");
gotoxy(20,10);
printf(" 3  SALIR\n");
gotoxy(20,12);
printf("enter option [ ]");
gotoxy(34,12);

getch();

}
void energia_potencial()
{
clrscr();
clrscr();
textbackground(15);
textcolor(0);
int k,y,p,op;
float a,masa,e2,t2,x,t;
clrscr();

     gotoxy(4,1); printf("É\n");
     gotoxy(74,1);printf("»\n");
     gotoxy(4,23);printf("È\n");
     gotoxy(74,23);printf("¼\n");

    for (k= 5; k<= 73; k ++)
  {gotoxy (k,y);
   gotoxy(k,1);printf("Í\n");
   gotoxy (k,23);printf("Í\n");
  }

   for (p=2; p<=22; p++)
  {
    gotoxy (4,p);printf("º\n");
   gotoxy (74,p);printf("º\n");
    }
gotoxy(29,2);
gotoxy(22,2);
printf("  APLICACION DE LA LEY DE NEWTON ");
gotoxy(27,4);
printf("  S U B  M E N U ");
printf("\n\n");
gotoxy(20,6);
printf(" 1  FUERZA  \n");
gotoxy(20,8);
printf(" 2  POTENCIA\n");
gotoxy(20,10);
printf(" 3  TRABAJO (Cuando f -> desp)\n");
gotoxy(20,12);
printf(" 4  ENERGIA CINETICA\n");
gotoxy(20,14);
printf(" 5  ENERGIA POTENCIAL\n");
gotoxy(20,16);
printf(" 6  SALIR\n");
gotoxy(20,18);
printf("enter option [ ]");
gotoxy(34,18);
scanf("%d",&op);
      if(op == 1){
		clrscr();
		gotoxy(30,4);
		printf("  LEYES DE NEWTON ");
		gotoxy(31,5);
		printf("  ---------------");

		printf("\n\n\n");
		printf(" fuerza= masa x aceleracion \n");
		printf("\n\n\n");
		printf(" FUERZA = MASA =       x  aceleracion =     \n");

		gotoxy(19,12);
		scanf("%f",&masa);
		gotoxy(40,12);
		scanf("%f",&a);
		gotoxy(45,15);
		printf(" FUERZA ==> %1.2f newton ",(masa*a));
		getch();
	     }

    if(op == 2){
		clrscr();
		gotoxy(30,4);
		printf("  MOVIMIENTO RECTILINEO ");
		gotoxy(31,5);
		printf(" ------------------------");

		printf("\n\n\n");
		printf("                trabajo   \n ");
		printf(" potencia  = ------------ \n");
		printf("                tiempo   \n ");
		printf("\n\n\n");
		printf("                      W2=          \n ");
		printf(" potencia = ----------------------- \n");
		printf("                      t=          \n ");

		gotoxy(27,14);
		scanf("%f",&e2);
		gotoxy(27,16);
		scanf("%f",&t2);
		gotoxy(15,18);
		printf("potencia ==> %1.2f  m/s ",(e2/t2));
		getch();
	     }
      if(op==3){

		clrscr();
		gotoxy(30,4);
		printf("  MOVIMIENTO RECTILINEO ");
		gotoxy(31,5);
		printf(" ------------------------");

		printf("\n\n\n");
		printf(" trabajo  =  fuerza x distancia \n");
		printf("\n\n\n");
		printf(" velocidad inst = ferza =       x  distancia =      \n");

		gotoxy(27,12);
		scanf("%f",&x);

		gotoxy(48,12);
		scanf("%f",&t);
		gotoxy(15,18);
		printf("velocidad  instantanea ==> %1.2f  m/s ",x*t);
		getch();
	     }

	      if(op==4){

		clrscr();
		gotoxy(30,4);
		printf("  MOVIMIENTO RECTILINEO ");
		gotoxy(31,5);
		printf(" ------------------------");

		printf("\n\n\n");
		printf(" Energia cinetica  = «masa * V ý  \n");
		printf("\n\n\n");
		printf(" Ec = «*masa=      * V ý =      \n");

		gotoxy(14,12);
		scanf("%f",&x);

		gotoxy(28,12);
		scanf("%f",&t);
		gotoxy(25,18);
		printf("Ec ==> %1.2f  julios ",(0.5)*x*t*t);
		getch();
	       }
       if(op==5){

		clrscr();
		gotoxy(30,4);
		printf("  MOVIMIENTO RECTILINEO ");
		gotoxy(31,5);
		printf(" ------------------------");

		printf("\n\n\n");
		printf(" Energia potencial  = w x g x h = m*g*h \n");
		printf("\n\n\n");
		printf(" Ep = masa=      (9.8 m/sý)*h =      \n");

		gotoxy(14,12);
		scanf("%f",&x);

		gotoxy(32,12);
		scanf("%f",&t);
		gotoxy(35,18);
		printf("Ep ==> %1.2f  julios ",(9.8)*x*t);
		getch();
	       }

}
