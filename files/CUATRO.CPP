# include <stdio.h>
# include <dos.h>
# include <conio.h>
# include <graphics.h>
# include <stdlib.h>


int main(void)

{
   /* Autodetectar */

   int gdriver = DETECT, gmode, errorcode;
   int midx, midy, i;

   /* inicializa graficos y las variables locales */
   initgraph(&gdriver, &gmode, "");

   /* observando resultado de la inicializacion */
   errorcode = graphresult();
   if (errorcode != grOk)  /* ocurrio un error */

   {
      printf("Error engrafico: %s\n", grapherrormsg(errorcode));
      printf("Presiona cualquier tecla y continua:");
      getch();
      exit(1); /* terminando con un codigo de error */
   }

    entrada:

    cleardevice();


   /* TEXTO */
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

     int x;
     int b,h,base,altura;

    /* mensaje */
      for (x= 0 ; x<=13; x++) {
      setcolor(x);
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
      delay(700);

     int y;
      cleardevice();


      base = b*10;
      altura = h*10;


      setcolor(BLUE);

	/* Primer Triangulo*/
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
    /* Segundo Triangulo Diagonal inverso */

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
    /* Tercer Triangulo Diagonal inverso */

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
    /* Cuarto Triangulo Diagonal inverso */

     outtextxy(50, 56," < CUARTO TRIANGULO >" );
     for (x=100;x<=base;x++){
	   line(100,100,100,x);

       }


       for (y=100;y<=altura;y++){
	   line(y,x,100,100);
       }

  gotoxy(29,25);printf("Presiona una tecla y continua..\n");
  getch();
closegraph();

}
