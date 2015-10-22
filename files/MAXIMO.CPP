# include <stdio.h>
# include <dos.h>
# include <conio.h>
# include <graphics.h>
# include <stdlib.h>


int main(void)
{
   // Autodetectar

   int gdriver = DETECT, gmode, errorcode;
   int midx, midy, i;

   // inicializa graficos y las variables locales

   initgraph(&gdriver, &gmode, "");

   // observando resultado de la inicializacion

   errorcode = graphresult();
   if (errorcode != grOk)  // ocurrio un error
     {
      printf("Error en grafico: %s\n", grapherrormsg(errorcode));
      printf("Presiona cualquier tecla y continua:");
      getch();
      exit(1); // terminando con un codigo de error
      }

   char r;
   int y=0,c=0,x=0,t=0;


   // ----------< P O R T A D A  D E L  T R A B A J O >-------------------//


   while (y<=360){
   line(0, 0, random(getmaxx()),random(getmaxy()));
   y++;
   }
   settextstyle(1,0,9);
   setcolor(WHITE);
   for (x=9;x<=31;x++){
   outtextxy(x,100,"TRIANGULOS");
   delay(30);
   }

   for (x=9;x<=19;x++){
     for (c=0;c<=14;c++){
     outtextxy(x,100, "TRIANGULOS");
     setcolor(c);
     }
     delay(30);
   }

   setcolor(WHITE);
   y=0;
   while (y<=600){
   line(640, 480, random(getmaxx()),random(getmaxy()));
   y++;
   }

   setbkcolor(WHITE);
   delay(100);
   setcolor(MAGENTA);
   outtextxy(19,100,"TRIANGULOS");
   settextstyle(7,0,5);

   for (c=0;c<=13;c++){
   outtextxy(25,250,"CARLOS ANDRES AGUDELO");
   setcolor(c);
   delay(30);
   }

   for (c=0;c<=13;c++){
   outtextxy(70,350,"ISAAC ABELLO ARIZA");
   setcolor(c);
   delay(30);
   }
   getch();

  cleardevice();
  setbkcolor(BLACK);



   // --------------------< T R I A N G U L O S >------------------ //

  // TEXTO

    do{
    inicio:
    cleardevice();
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

    int b,h,base,altura;

    // mensaje

      for (t= 0 ; t<=13; t++) {
      setcolor(t);
      delay(20);
      outtextxy(10, 16,"Digite el numero de la Base [Min 15, Max 40]" );
      }
      gotoxy(57,2);scanf("%d",&b);

      for (x= 0 ; x<=13; x++) {
      setcolor(x);
      delay(20);
      outtextxy(10, 46,"Digite el numero de la Altura [Min 15, Max 40]" );
      }

      gotoxy(57,4);scanf("%d",&h);

      outtextxy(140, 246,"Un Momento, Procesando el triangulo y sus coordenadas" );
      gotoxy(38,15);printf("[   ]");

      for (x=0;x<=25 ;x++){
      gotoxy(40,15);printf("|");
      delay(20);
      gotoxy(40,15);printf("/");
      delay(20);
      gotoxy(40,15);printf("-");
      delay(20);
      gotoxy(40,15);printf("\\");
      delay(20);
      }
      delay(200);

	if (h==0 && b== 0){
	outtextxy(150,180 ,"No es posible realizar calculos sin medidas");
	delay(1500);
	goto salida;
       }


      if (b>=41 || b<=14 ){
      outtextxy(30,180 ,"No es posible realizar calculos con esas medidas, intentelo de nuevo !");
      delay(1500);
      goto inicio;
      }

      if (h>=41 || h<=14){
      outtextxy(30,180 ,"No es posible realizar calculos con esas medidas, intentelo de nuevo !");
      delay(1500);
      goto inicio;
      }


      cleardevice();
      base = b*10;
      altura = h*10;

      setcolor(BLUE);

      // Primer Triangulo

      outtextxy(50, 56," < PRIMER TRIANGULO >" );
      for (x=100;x<=base;x++){
      }
      for (y=100;y<=altura;y++){
	   line(x,100,100,y);
      }
     gotoxy(29,25);printf("Presiona una tecla y continua..\n");
     getch();

     cleardevice();
     setcolor(GREEN);

    // Segundo Triangulo Diagonal inverso

     outtextxy(50, 56," < SEGUNDO TRIANGULO >" );
     for (x=100;x<=base;x++){
     }
     for (y=100;y<=altura;y++){
     line(100,x,y,100);
     }

     gotoxy(29,25);printf("Presiona una tecla y continua..\n");
     getch();

     cleardevice();
     setcolor(RED);

    // Tercer Triangulo Diagonal inverso

     outtextxy(50, 56," < TERCER TRIANGULO >" );
     for (x=100;x<=base;x++){
     }

     for (y=100;y<=altura;y++){
	   line(x,y,100,100);
     }

  gotoxy(29,25);printf("Presiona una tecla y continua..\n");
  getch();

   cleardevice();
   setcolor(LIGHTGREEN);

    // Cuarto Triangulo Diagonal inverso

    outtextxy(50, 56," < CUARTO TRIANGULO >" );
    for (x=100;x<=base;x++){
    }

    for (y=100;y<=altura;y++){
    setcolor(y-altura);
    line(y,x,100,100);
    }

   salida:
   setcolor(BLUE);
   settextstyle(1, HORIZ_DIR, 1);
   outtextxy(30,380 ,"Deseas salir  [S/N] ? [   ]");
   gotoxy(30,25);getchar();

   r=getchar();

  } while (r !='s'&& r!='S');



  // Salida Del Programa

  for (t= 0 ; t<=13; t++) {
  setcolor(t);
  delay(20);
  outtextxy(30,380 ,"Deseas salir  [S/N] ? [   ]");
  }
   delay(50);
   cleardevice();
   settextstyle(0, HORIZ_DIR, 1);

   for (t= 0 ; t<=13; t++) {
   setcolor(t);
   delay(20);
   outtextxy(30,280 ,"ESTE PROGRAMA HA FINALIZADO, GRACIAS POR UTILIZAR EL PROGRAMA !");
   }
   delay(50);

   getch();
   closegraph();
   return 0;

}
